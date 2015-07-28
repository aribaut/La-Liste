<?php
/**
 * @file
 * Include file for LaListe Ranking Cron/Drush Computation.
 */

/*
** Update all restaurant scores from today's date
*/
function laliste_ranking_update($method) {
	// for all restaurants, compute their scores
	$results = db_query("
	SELECT nid  
	FROM {node}
		");

	foreach($results as $row) {
		$scores = array();
		$scores = laliste_ranking_compute_restaurant_ranking_score($row->nid, $method);
		
		// We ONLY treat scores where we have existing business rules
		if($scores != -1) {
			//echo "nid:".$row->nid.' | score1:'.$scores['method1'].' | score2:'.$scores['method2']."\n";
			// Do we have a corresponding restaurant in the stats table?

			$nid = db_query("
			SELECT restaurant_id FROM {restaurant_stats} WHERE restaurant_id = :nid
				", array(':nid' => $row->nid))->fetchField();
			
			
			// We insert if no records exist
			if(!$nid) {
			  db_insert('restaurant_stats')
	    	  ->fields(array(
	      		'restaurant_id' => $row->nid,
	      		'score1' => floatval($scores['method1']),
	      		'score2' => floatval($scores['method2']),
	      		'created' => time(),
	      		'updated' => time(),
	    	  ))
	    	  ->execute();
			}
			else {
			  // Let's update then
			  db_update('restaurant_stats')
	  		  ->fields(array(
	    	    'score1' => floatval($scores['method1']),
	    	    'score2' => floatval($scores['method2']),
	    	    'updated' => time(),
	  		    )
	  		  )
	  		  ->condition('restaurant_id', $row->nid)
	  		  ->execute();
		    }
		}
	    else {
	    	// Let's implement a guide catch
	    }
	}
	echo "\nLALISTE IS UPDATED!\n";

}

/*
** Calculate the score for each ranking record.
*/
function laliste_ranking_compute_restaurant_ranking_score($restaurant_id, $method) {
  $scores = [];

  // for all ranking rows, calculate the score according to guide rule and update row
  $results = db_query("
    SELECT {restaurantguideranking}.guide_id, {ranking}.ranking_id, food, bonus, wine, service, atmosphere, panorama, quiet, value, votes 
    FROM {ranking}
    LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id
    WHERE {restaurantguideranking}.restaurant_id = :restaurant_id", array(':restaurant_id' => $restaurant_id));

  // counter
  $n=0;
  foreach($results as $row) {
  	// let's calculate scores based on ecach guide's rule. We update the DB each time?
  	if(isset($row->guide_id)) {
  	  $scores[] = generate_score(
  	  	$row->ranking_id,
  	  	$row->guide_id,
  	  	$row->food+0, 
  	  	$row->bonus+0, 
  	  	$row->wine+0, 
  	  	$row->service+0, 
  	  	$row->atmosphere+0, 
  	  	$row->panorama+0, 
  	  	$row->quiet+0, 
  	  	$row->value+0, 
  	  	$row->votes+0
  	  );
  	  $n=$n+1;
  	}
  }
  // We have can compute the compunded scores
  foreach($scores as $score) {
  	if(isset($score['method1']) && $score['method1']!=0) {
  	  // Let's update the DB with those raw scores (before guide coefficient apply)	
  	  db_update('ranking')
  		  ->fields(array(
    	    'score1' => floatval($score['method1']),
    	    'score2' => floatval($score['method2']),
    	    'updated' => time(),
  		    )
  		  )
  		  ->condition('ranking_id', intval($score['ranking_id']))
  		  ->execute();

  	  $coef = laliste_ranking_get_guide_factor($score['guide'],$method);
  	  $compound1 += $score['method1'] * $coef;
  	  $compound2 += $score['method2'] * $coef;
  	}
  	else {
  		$n=$n-1;
  	}
  }

  // We divide using the precision math lib to obtain the median score for each methods.
  if($n>0) {
    $compound['method1'] = $compound1/$n;
    $compound['method2'] = $compound2/$n;
    $compound['guide'] = $scores['guide'];
    return($compound);
  }
  else return -1; // no guide rule setup for this dataset
}

/*
** The business rules are here!
** For now we have two models
** Model 1 : Cuisine is 80% of the score
** Model 2 : Cuisine is 75% of the score
*/
function generate_score($ranking_id, $guide_id, $food, $bonus, $wine, $service, $atmosphere, $panorama, $quiet, $value, $votes) {
  $scores = array();
  // We extract the taxonomy term to identify the guide
  $term = taxonomy_term_load($guide_id);
  $guide = $term->name;

  if(isset($guide)) {
  	// We set the guide to calculate the associated coefficient upon return to function call
    $scores['guide'] = $guide;
    $scores['ranking_id'] = $ranking_id;
    
    switch($guide) {
      case 'Aral Schlemmer Atlas':
        // method1
      	$score1 = $food*16;
      	$score1 +=  ($wine == 1 ? 5 : 0);
      	$score1 +=  ($service == 1 ? 15 : 0);
      	$scores['method1'] = $score1;
        // method2
      	$score2 = $food*15;
      	$score2 +=  ($wine == 1 ? 10 : 0);
      	$score2 +=  ($service == 1 ? 15 : 0);
      	$scores['method2'] = $score2;
      break;

      case 'Der große Restaurant- & Hotelguide':
        // method1
      	if ($bonus == 1) {
      	  $score1 =  ($food == 5 ? 80 : 0);
      	  $score1 +=  ($food == 4 ? 73 : 0);
      	}
      	elseif(!isset($bonus) || $bonus == 0) {
      	  $score1 =  ($food == 5 ? 77 : 0);
      	  $score1 +=  ($food == 4 ? 70 : 0);
      	}
      	$score1 += $service*3;
      	$score1 += ($wine == 3 ? 5 : 0);
      	$score1 += ($wine == 2 ? 3 : 0);
      	$score1 += ($wine == 1 ? 1 : 0);
      	$scores['method1'] = $score1;
      	// method2
      	if ($bonus == 1) {
      	  $score2 =  ($food == 5 ? 75 : 0);
      	  $score2 +=  ($food == 4 ? 65 : 0);
      	}
      	elseif(!isset($bonus) || $bonus == 0) {
      	  $score2 =  ($food == 5 ? 70 : 0);
      	  $score2 +=  ($food == 4 ? 60 : 0);
      	}
      	$score2 += $service*3;
      	$score2 += ($wine == 3 ? 10 : 0);
      	$score2 += ($wine == 2 ? 6.5 : 0);
      	$score2 += ($wine == 1 ? 4 : 0);
      	$scores['method2'] = $score2;
      break;

      case 'Gault-Millau (FR)':
      	switch($food) {
      	  case 5: $score = 19.5; break;
      	  case 4: $score = 19;   break;
      	  case 3: $score = 18;   break;
      	  case 2: $score = 16;   break;
      	  case 1: $score = 13;   break;
      	}
      	$scores['method1'] = $score*5; // base 100
      	$scores['method2'] = $scores['method1'];
      break;

      case 'Gault-Millau (DE)':
      	// method 1
	    $score1 = $food*4;
	    $score1 += ($service == 1 ? 5 : 0);
	    $score1 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
	    $scores['method1'] = $score1;
	    // method2
	    $score2 = $food*3.75;
	    $score2 += ($service == 1 ? 10 : 0);
	    $score2 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
	    $scores['method2'] = $score2;
      break;

      case 'Guia Repsol':
        $score = ($food == 3 ? 100 : 0);
        $score += ($food == 2 ? 80 : 0);
        $score += ($food == 1 ? 60 : 0);
        $scores['method1'] = $score;
        $scores['method2'] = $score;
      break;

      case 'Gusto':
        // method1
      	if ($bonus == 1) {
      	  $score1 =  ($food == 10 ? 80 : 0);
      	  $score1 +=  ($food == 9 ? 73 : 0);
      	  $score1 +=  ($food == 8 ? 63 : 0);
      	}
      	elseif(!isset($bonus) || $bonus == 0) {
      	  $score1 =  ($food == 10 ? 77 : 0);
      	  $score1 +=  ($food == 9 ? 70 : 0);
      	  $score1 +=  ($food == 8 ? 60 : 0);
      	}
      	elseif($bonus == -1) {
      	  $score1 =  ($food == 10 ? 74 : 0);
      	  $score1 +=  ($food == 9 ? 67 : 0);
      	}
      	$score1 += $atmosphere*4;
      	$scores['method1'] = $score1; // service?
      	// method2
      	if ($bonus == 1) {
      	  $score2 =  ($food == 10 ? 75 : 0);
      	  $score2 +=  ($food == 9 ? 70 : 0);
      	  $score2 +=  ($food == 8 ? 63 : 0);
      	}
      	elseif(!isset($bonus) || $bonus == 0) {
      	  $score2 =  ($food == 10 ? 73 : 0);
      	  $score2 +=  ($food == 9 ? 68 : 0);
      	  $score2 +=  ($food == 8 ? 60 : 0);
      	}
      	elseif($bonus == -1) {
      	  $score2 =  ($food == 10 ? 71 : 0);
      	  $score2 +=  ($food == 9 ? 66 : 0);
      	}
      	$score2 += $atmosphere*5;
      	$scores['method2'] = $score2; // service?
      break;

      case 'Michelin' :
      	// method1
      	$score1 =  ($food == 3 ? 80 : 0);
      	$score1 +=  ($food == 2 ? 70 : 0);
      	$score1 +=  ($food == 1 ? 60 : 0);
      	$score1 +=  ($food == 0 ? 50 : 0); // Bib?
      	$score1 += ($wine == 1 ? 5 : 0);
      	$score1 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
      	$scores['method1'] = $score1;
      	// method2
      	$score2 =  ($food == 3 ? 75 : 0);
      	$score2 +=  ($food == 2 ? 70 : 0);
      	$score2 +=  ($food == 1 ? 60 : 0);
      	$score2 +=  ($food == 0 ? 50 : 0); // Bib?
      	$score2 += ($wine == 1 ? 10 : 0);
      	$score2 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
      	$scores['method2'] = $score2;
      break;

      case 'Tripadvisor':
      	// method1
      	$score1 = $food*16;
      	$score1 += $service*2;
      	$score1 += $atmosphere*2;
      	$scores['method1'] = $score1;
      	// method2
      	$score2 = $food*15;
      	$score2 += $service*3;
      	$score2 += $atmosphere*2;
      	$scores['method2'] = $score2;
      break;

      case 'Varta-Führer':
      	// method1
      	if ($bonus) {
      	  $score1 =  ($food == 5 ? 80 : 0);
      	  $score1 +=  ($food == 4 ? 70 : 0);
      	  $score1 +=  ($food == 3 ? 60 : 0);
      	}
      	else {
      	  $score1 =  ($food == 5 ? 75 : 0);
      	  $score1 +=  ($food == 4 ? 65 : 0);
      	  $score1 +=  ($food == 3 ? 55 : 0);
      	}
      	$score1 += ($atmosphere == 1 ? 10 : 0);
      	$score1 += ($service == 1 ? 10 : 0);
      	$scores['method1'] = $score1;
      	// method2
      	if ($bonus) {
      	  $score2 =  ($food == 5 ? 75 : 0);
      	  $score2 +=  ($food == 4 ? 65 : 0);
      	  $score2 +=  ($food == 3 ? 55 : 0);
      	}
      	else {
      	  $score2 =  ($food == 5 ? 70 : 0);
      	  $score2 +=  ($food == 4 ? 60 : 0);
      	  $score2 +=  ($food == 3 ? 50 : 0);
      	}
      	$score2 += ($atmosphere == 1 ? 10 : 0);
      	$score2 += ($service == 1 ? 15 : 0);
      	$scores['method2'] = $score2;
      break;

      case 'Zagat':
        // method1
        $score1 = $food*2.6666;
        $score1 += $atmosphere/3;
        $score1 += $service/3;
        $scores['method1'] = $score1;
        // method2
        $score2 = $food*2.5;
        $score2 += $atmosphere/3;
        $score2 += $service/2;
        $scores['method2'] = $score2;
      break;

      case 'Der Feinschmecker': case 'Five Diamond Awards': case 'Forbes Travel Guide': case 'Gayot.com': case 'Zomato':
      	$score = $food*20;
      	$scores['method1'] = $score;
      	$scores['method2'] = $score;
      break; 
    }
  }
  return $scores;
}


function laliste_ranking_get_guide_factor($guide, $method) {
  // get the guide coef either from survey results (default) or from fixed 'bonus' method.
  switch($guide) {
	case 'Aral Schlemmer Atlas':
		$coef =	($method == 'bonus' ? 1 : 0.4);
	break;

	case 'Der Feinschmecker':
		$coef =	($method == 'bonus' ? 1 : 0.625);
	break;

	case 'Der große Restaurant- & Hotelguide':
		$coef =	($method == 'bonus' ? 1 : 0.425);
	break;

	case 'Five Diamond Awards':
		$coef =	($method == 'bonus' ? 1.03 : 0.513);
	break;

	case 'Forbes Travel Guide':
		$coef =	($method == 'bonus' ? 1.01 : 0.678);
	break;

	case 'Gault-Millau (FR)':
		$coef =	($method == 'bonus' ? 1 : 0.711);
	break;

	case 'Gault-Millau (DE)':
		$coef =	($method == 'bonus' ? 1 : 0.711); // per instructions from Jorg!
	break;

	case 'Gayot.com':
		$coef =	($method == 'bonus' ? 1 : 0.513);
	break;

	case 'Guia Repsol':
		$coef =	($method == 'bonus' ? 1 : 0.433);
	break;

	case 'Gusto':
		$coef =	($method == 'bonus' ? 1 : 0.7125);
	break;

	case 'Michelin' :
		$coef =	($method == 'bonus' ? 1.07 : 0.806);
	break;

	case 'Tripadvisor':
		$coef =	($method == 'bonus' ? 1 : 0.612);
	break;

	case 'Varta-Führer':
		$coef =	($method == 'bonus' ? 1 : 0.5125);
	break;

	case 'Zagat':
		$coef =	($method == 'bonus' ? 1 : 0.73);
	break;

	case 'Zomato':
		$coef =	($method == 'bonus' ? 1 : 0.426);
	break;
  }
  return $coef;
}