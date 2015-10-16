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
			// Do we have a corresponding restaurant in the stats table?
			$nid = db_query("
			SELECT restaurant_id FROM {restaurant_stats} WHERE restaurant_id = :nid
				", array(':nid' => $row->nid))->fetchField();
			// We insert if no records exist
			if(!$nid) {
			  db_insert('restaurant_stats')
	    	  ->fields(array(
	      		'restaurant_id' => $row->nid,
	      		'score' => floatval($scores['method1']),
            'popularity' => $scores['popularity'],
	      		'created' => time(),
	      		'updated' => time(),
	    	  ))
	    	  ->execute();
			}
			else {
			  // If record already exists, we update it
			  db_update('restaurant_stats')
	  		  ->fields(array(
	    	    'score' => floatval($scores['method1']),
            'popularity' => $scores['popularity'],
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
	echo "\nLALISTE RANKING IS UP TO DATE!\n";

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
  // counting number of score records for each restaurant
  $n=0;
  foreach($results as $row) {
  	// let's calculate scores based on ecach guide's rule.
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
  // We have all recorded scores for a given restaurant, 
  // we insert them and we can compute the compunded scores with each guide's reliability factor
  foreach($scores as $score) {
  	if(isset($score['method1']) && $score['method1']!=0) {

      // we get the guide's relaibility factor (trustworthiness) along with the guide type
  	  $guide_ranking = laliste_ranking_get_guide_factor($score['guide'],$method);

      // Default case for user review sites : We set their trust factor to 1
      if (isset($guide_ranking) && !isset($guide_ranking['trust'])) {
        $guide_ranking['trust'] = 1;
      }

      // Let's update the ranking table with the raw score for each entry (i.e. before guide coefficient apply) 
      db_update('ranking')
        ->fields(array(
          'score' => floatval($score['method1']),
          'trust' => $guide_ranking['trust'],
          'popularity' => $guide_ranking['popularity'],
          'updated' => time(),
          )
        )
        ->condition('ranking_id', intval($score['ranking_id']))
        ->execute();
  	}
  	else {
  		$n=$n-1;
  	}
  }
  // We now divide to obtain the median score for both methods and associated popularity.
  if($n>0) {

    // we select the max trust and apply same grade and trust to all other guides
    $dominant_ranking = db_query("
      SELECT trust, score, popularity FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND popularity = 5 ORDER BY trust DESC LIMIT 1", array(':restaurant_id' => $restaurant_id))->fetchObject();

    // We only consider a dominant guide who has a score equal or above 95
    if($dominant_ranking->popularity == 5 && $dominant_ranking->score >= 95) {
      db_query("
        UPDATE {ranking} 
        LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id 
        SET score = :score, trust = :trust 
        WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND score >= :score AND popularity = 5", 
        array(
          ':score' => $dominant_ranking->score, 
          ':trust' => $dominant_ranking->trust,
          ':restaurant_id' => $restaurant_id,
          )
        );
    }

    // compounded scores & popularity via MySQL!
    $compounded = db_query("
      SELECT SUM(score*trust) AS score, ROUND(SUM(popularity),1) AS popularity
      FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id 
      WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND trust IS NOT null AND score IS NOT null", array(':restaurant_id' => $restaurant_id))->fetchObject();

    // getting the median score value and sum of popularity score
    $median_score['method1']    = $compounded->score/$n;
    $median_score['popularity'] = $compounded->popularity;

    // we now send back the rounded score to the main stat table
    return($median_score);
  }
  else return -1; // no guide rule setup for this dataset
}

/*
** The business rules are here!
** For now we have one model
** Model 1 : Cuisine is 80% of the score
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
/*
      case '50 Best': case 'Opiniated about dining': case 'Elite Traveler':
        $score = ($food>=1 && $food <=20) ? 105 : 0;
        $score = ($food>20 && $food <=50) ? 103 : 0;
        $score = ($food>50 && $food <=100) ? 101 : 0;
        $scores['method1'] = $scores['method2'] = $score;
      break;
*/
      case '50 Mejores Restaurantes de América Latina':
        // Not used for algorithm
      break;

      case 'The AA Restaurant Guide Automobile Association':
        $score =   ($food == 5 ? 80 : 0);
        $score +=  ($food == 4 ? 70 : 0);
        $score +=  ($food == 3 ? 60 : 0);
        $score += ($wine == 1 ? 20 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'A la Carte':
        $score = $food;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Blue Ribbon':
        $score =   ($food == 3 ? 100 : 0);
        $score +=  ($food == 2 ? 80 : 0);
        $score +=  ($food == 1 ? 60 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'The Brisbane Times Good Food': // to be adjusted cleaned up
        $score =   ($food == 3 ? 100 : 0);
        $score +=  ($food == 2 ? 80 : 0);
        $score +=  ($food == 1 ? 60 : 0);
      break;

      case 'Guide Delta':
        $score =   ($food == 4 ? 80 : 0);
        $score +=  ($food == 3 ? 70 : 0);
        $score +=  ($food == 2 ? 60 : 0);
        $score +=  ($food == 1 ? 50 : 0);
        $score += ($wine == 1 ? 8 : 0);
        $score += ($atmosphere == 1 ? 8 : 0);
        $score += ($quiet == 1 ? 2 : 0);
        $score += ($value == 1 ? 2 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Degusta':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
        $scores['method1'] = $scores['method2'] = $score;
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

      case 'Dining City':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'DininginDoha':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Dubai Eating':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Eatability': // mise a jour guide document v1.45
        $score =  $food*8;
        $score += $atmosphere;
        $score += $service;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Espresso': 
        $score = $food*5;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Falstaff':
        $score = $food;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Foursquare':
        $score = $food*10;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Gambero Rosso':
        $score =  $food+17; // Yup, the food is rated out of 60. So add 17 + bonus to reach 80.
        $score +=  ($bonus == 1 ? 3 : 0);
        $score +=  $wine/2;
        $score +=  $service/2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Gault-Millau (AT)':
        // method1
        $score1 =   ($food == 19 ? 80 : 0);
        $score1 +=  ($food == 18 ? 75 : 0);
        $score1 +=  ($food == 17 ? 70 : 0);
        $score1 +=  ($food == 16 ? 65 : 0);
        $score1 +=  ($food == 15 ? 60 : 0);
        $score1 += ($service == 1 ? 20 : 0);
        $scores['method1'] = $score1;
        // method2
        $score2 =   ($food == 19 ? 75 : 0);
        $score2 +=  ($food == 18 ? 70 : 0);
        $score2 +=  ($food == 17 ? 65 : 0);
        $score2 +=  ($food == 16 ? 60 : 0);
        $score2 +=  ($food == 15 ? 55 : 0);
        $score2 += ($service == 1 ? 20 : 0);
        $scores['method2'] = $score2;
      break;

      case 'Gault-Millau (AU)': // data to be cleaned up
        $score =   ($food == 5 ? 100 : 0);
        $score +=  ($food == 4 ? 90 : 0);
        $score +=  ($food == 3 ? 80 : 0);
        $score +=  ($food == 2 ? 70 : 0);
        $score +=  ($food == 1 ? 55 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Gault-Millau (BE)':
        $score =   ($food == 19.5 ? 80 : 0);
        $score +=  ($food == 19 ? 77 : 0);
        $score +=  ($food == 18.5 ? 74 : 0);
        $score +=  ($food == 18 ? 72 : 0);
        $score +=  ($food == 17 ? 67 : 0);
        $score +=  ($food == 16 ? 62 : 0);
        $score += ($bonus == 1 ? 5 : 0);
        $score += ($wine == 1 ? 15 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Gault-Millau (CH)':
        $score =   ($food == 19 ? 100 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15 ? 60 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Gault-Millau (DE)':
        // method 1
        $score1 +=  ($food == 19.5 ? 80 : 0);
        $score1 +=  ($food == 19 ? 77 : 0);
        $score1 +=  ($food == 18 ? 72 : 0);
        $score1 +=  ($food == 17 ? 67 : 0);
        $score1 +=  ($food == 16 ? 62 : 0);
        $score1 += ($service == 1 ? 5 : 0);
        $score1 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
        $scores['method1'] = $score1;
        // method2
        $score1 +=  ($food == 19.5 ? 75 : 0);
        $score1 +=  ($food == 19 ? 72 : 0);
        $score1 +=  ($food == 18 ? 67 : 0);
        $score1 +=  ($food == 17 ? 63 : 0);
        $score1 +=  ($food == 16 ? 60 : 0);
        $score1 += ($service == 1 ? 10 : 0);
        $score1 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
        $scores['method2'] = $score2;
      break;

      case 'Gault-Millau (FR)':
        $score =  ($food == 5 ? 100 : 0);
        $score +=  ($food == 4.5 ? 95 : 0);
        $score +=  ($food == 4 ? 90 : 0);
        $score +=  ($food == 3.5 ? 85 : 0);
        $score +=  ($food == 3 ? 80 : 0);
        $score +=  ($food == 2 ? 70 : 0);
        $score +=  ($food == 1 ? 55 : 0);
      	$scores['method2'] = $scores['method1'] = $score;
      break;

      case 'Gault-Millau (NL)':
        $score +=  ($food == 19.5 ? 80 : 0);
        $score +=  ($food == 19 ? 77 : 0);
        $score +=  ($food == 18.5 ? 74 : 0);
        $score +=  ($food == 18 ? 72 : 0);
        $score +=  ($food == 17.5 ? 69 : 0);
        $score +=  ($food == 17 ? 67 : 0);
        $score +=  ($food == 16 ? 62 : 0);
        $score +=  ($bonus == 1 ? 5 : 0); // bonus bio
        $score +=  ($wine == 1 ? 5 : 0);
        $score +=  ($service == 1 ? 10 : 0); // coup de coeur
        $scores['method2'] = $scores['method1'] = $score;
      break;

      case 'Gayot.com':
        $score +=  ($food == 19 ? 100 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15 ? 60 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Guia Repsol':
        $score = ($food == 3 ? 100 : 0);
        $score += ($food == 2 ? 80 : 0);
        $score += ($food == 1 ? 60 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'The Good Food Guide':
        $score =  ($food == 10 ? 80 : 0);
        $score += ($food == 9 ? 75 : 0);
        $score += ($food == 8 ? 70 : 0);
        $score += ($food == 7 ? 65 : 0);
        $score += ($food == 6 ? 60 : 0);
        $score += ($food == 5 ? 55 : 0);
        $score += ($food == 4 ? 50 : 0);
        $score += ($food == 3 ? 45 : 0);
        $score += ($wine == 1 ? 20 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Guía Gourmet':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Guía Prestigio':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Guía Summum':
        //TBD
      break;

      case 'Guia4rodas':
        $score =  ($food == 3 ? 80 : 0);
        $score += ($food == 2 ? 70 : 0);
        $score += ($food == 1 ? 60 : 0);
        $score += $atmosphere*4;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'GuíaOleo':
        $score = $food*2.666;
        $score += $service/3;
        $score += $atmosphere/3;
        $scores['method1'] = $scores['method2'] = $score;
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

      case 'Harden\'s':
        $score = $food*16;
        $score += $atmosphere*2;
        $score += $service*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'La Suisse Gourmande':
        $score =  ($food == 100 ? 100 : 0);
        $score +=  ($food == 90 ? 90 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Lekker':
        $score =  ($food == 1 ? 100 : 0);
        $score += (($food > 1 && $food <= 5) ? 98 : 0);
        $score += (($food >= 6 && $food <= 10) ? 95 : 0);
        $score += (($food >= 11 && $food <= 20) ? 90 : 0);
        $score += (($food >= 21 && $food <= 40) ? 85 : 0);
        $score += (($food >= 41 && $food <= 60) ? 80 : 0);
        $score += (($food >= 61 && $food <= 80) ? 75 : 0);
        $score += (($food >= 81 && $food <= 100) ? 70 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Maclean’s Canada’s best restaurant':
        // TBD - bonus national level?
      break;

      case 'Michelin' :
      	// method1
      	$score1 =  ($food == 3 ? 80 : 0);
      	$score1 += ($food == 2 ? 70 : 0);
      	$score1 += ($food == 1 ? 60 : 0);
      	$score1 += ($food == '0,5' ? 50 : 0); // Bib gourmand notation
        $score1 += ($food == 0 ? 40 : 0);
      	$score1 += ($wine == 1 ? 5 : 0);
      	$score1 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
      	$scores['method1'] = $score1;
      	// method2
      	$score2 =  ($food == 3 ? 75 : 0);
      	$score2 +=  ($food == 2 ? 70 : 0);
      	$score2 +=  ($food == 1 ? 60 : 0);
      	$score2 +=  ($food == 0 ? 50 : 0);
      	$score2 += ($wine == 1 ? 10 : 0);
      	$score2 += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
      	$scores['method2'] = $score2;
      break;

      case 'Michelin Restaurants (FR)': case 'Michelin Restaurants (DE)':
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

      case "New York Times":
        $score = $food*25;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Queremos comer':
        $score = $food*5;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Resto Tunisie':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Rossouw\'s Restaurants':
        $score = $food*16;
        $score += ($wine == 1 ? 10 : 0);
        $score += ($service == 1 ? 10 : 0);
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Schlemmer Atlas':
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

      case 'Singapore Tatler': case 'Philippine Tatler': case 'Malaysia Tatler': case 'Hong Kong Tatler':
        $score = $food*16;
        $score += $wine;
        $score += $atmosphere;
        $score += $service*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Tabelog':
        $score = $food*20;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Thailand Tatler Best restaurants':
        $score = $food*8;
        $score += $wine/2;
        $score += $atmosphere/2;
        $score += $service*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Timeout Mexico':
        $score = $food*20;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'The Sydney Morning Herald Good Food Guide':
        $score1 = $food*5;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Tripadvisor':
        if(isset($votes) && $votes >= 50) {
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
        }
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

      case 'Verema': // @todo to be verified
        // method1
        $score1 = $food*8;
        $score1 += $wine;
        $score1 += $atmosphere;
        $scores['method1'] = $score1;
        // method2
        $score2 = $food*7.5;
        $score2 += $wine/2;
        $score2 += $atmosphere*1.5;
        $scores['method2'] = $score2;
      break;

      case 'Viajeros':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
        $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Where to eat in Canada':
          $score =  ($food == 3 ? 100 : 0);
          $score +=  ($food == 2 ? 80 : 0);
          $score +=  ($food == 1 ? 60 : 0);
          $scores['method1'] = $scores['method2'] = $score;
      break;

      case 'Vacay.ca':
        // TBD - bonus au niveau national?
      break;

      case 'White Guide':
        // TBD
      break;

      case 'Zagat':
        // method1
        $score1 = $food*2.666;
        $score1 += $atmosphere/3;
        $score1 += $service/3;
        $scores['method1'] = $score1;
        // method2
        $score2 = $food*2.5;
        $score2 += $atmosphere/3;
        $score2 += $service/2;
        $scores['method2'] = $score2;
      break;

      case 'Der Feinschmecker': 
      case 'Five Diamond Awards': 
      case 'Forbes Travel Guide': 
      case 'Resto.be': 
      case 'Yelp': 
      case 'Zomato': 
      	$score = $food*20;
      	$scores['method1'] = $scores['method2'] = $score;
      break; 
    }
  }
  return $scores;
}

/*
** Implements data structure for Guides. Will need to be associated to Drupal Taxonomy.
*/
function laliste_ranking_get_guide_factor($guide_name, $method) {
  // get the guide relaibility factor from survey results (default) or from fixed 'bonus' method from drush cmd line.
  switch($guide_name) {
/*
  case '50 Best': case 'Opiniated about dining': case 'Elite Traveler':
    $guide_data['type']   = 'list';
  break;
*/
  case '50 Mejores Restaurantes de América Latina':
    // Not used for algorithm
  break;

  case 'The AA Restaurant Guide Automobile Association':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.5);
    $guide_data['type']   = 'guide';
  break;

  case 'A la Carte':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.6); // arbitrary
    $guide_data['type']   = 'guide';
  break;

  case 'Blue Ribbon':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.6); // arbitrary
    $guide_data['type']   = 'guide';
  break;

  case 'The Brisbane Times Good Food':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.7);
    $guide_data['type']   = 'publication';
  break;

  case 'Guide Delta':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.35);
    $guide_data['type']   = 'guide';
  break;

  case 'Degusta':
    $guide_data['type']   = 'user';
  break;

	case 'Der Feinschmecker':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.524);
    $guide_data['type']   = 'guide';
	break;

	case 'Der große Restaurant- & Hotelguide':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.421);
    $guide_data['type']   = 'guide';
	break;

  case 'Dining City':
    $guide_data['type']   = 'user';
  break;

  case 'DininginDoha':
    $guide_data['type']   = 'user';
  break;

  case 'Dubai Eating':
    $guide_data['type']   = 'user';
  break;

  case 'Eatability':
    //$guide_data['trust'] = ($method == 'bonus' ? 1 : 0.56);
    $guide_data['type']   = 'user';
  break;

  case 'Espresso':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.719);
    $guide_data['type']   = 'guide';
  break;

	case 'Five Diamond Awards':
		$guide_data['trust'] =	($method == 'bonus' ? 1.03 : 0.513);
    $guide_data['type']   = 'guide';
	break;

  case 'Falstaff': // considered a site
    //$guide_data['trust'] = ($method == 'bonus' ? 1 : 0.567); // germany. 5.333 for Austria
    $guide_data['type']   = 'user';
  break;

	case 'Forbes Travel Guide':
		$guide_data['trust'] =	($method == 'bonus' ? 1.01 : 0.678);
    $guide_data['type']   = 'publication';
	break;

  case 'Foursquare':
    $guide_data['type']   = 'user';
  break;

  case 'Gambero Rosso':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.686);
    $guide_data['type']   = 'guide';
  break;

  case 'Gault-Millau (AT)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.783);
    $guide_data['type']   = 'guide';
  break;

  case 'Gault-Millau (AU)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.8);
    $guide_data['type']   = 'guide';
  break;

  case 'Gault-Millau (BE)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.6);
    $guide_data['type']   = 'guide';
  break;

  case 'Gault-Millau (CH)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.666);
    $guide_data['type']   = 'guide';
  break;

  case 'Gault-Millau (DE)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.552);
    $guide_data['type']   = 'guide';
  break;

	case 'Gault-Millau (FR)':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.711);
    $guide_data['type']   = 'guide';
	break;

  case 'Gault-Millau (NL)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.72);
    $guide_data['type']   = 'guide';
  break;

	case 'Gayot.com':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.513);
    $guide_data['type']   = 'guide';
	break;

  case 'The Good Food Guide':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.433);
    $guide_data['type']   = 'guide';
  break;

  case 'Guía Gourmet':
    $guide_data['type']   = 'user';
  break;

  case 'Guía Prestigio':
    $guide_data['type']   = 'user';
  break;

  case 'Guía Summum':
    $guide_data['type']   = 'user';
  break;

	case 'Guia Repsol':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.636);
    $guide_data['type']   = 'guide';
	break;

  case 'Guia4rodas':
    //$guide_data['trust'] =  ($method == 'bonus' ? 1 : xxx);
    $guide_data['type']   = 'guide';
  break;

  case 'GuíaOleo':
    $guide_data['type']   = 'user';
  break;

	case 'Gusto':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.569);
    $guide_data['type']   = 'guide';
	break;

  case 'Harden\'s':
    // user site
    //$guide_data['trust'] = ($method == 'bonus' ? 1 : 0.5);
    $guide_data['type']   = 'user';
  break;

  case 'La Suisse Gourmande':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.48);
    $guide_data['type']   = 'guide';
  break;

  case 'Lekker':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0); // ouch!
    $guide_data['type']   = 'guide';
  break;

  case 'Maclean’s Canada’s best restaurant':
    // TBD
  break;

	case 'Michelin':
		$guide_data['trust'] =	($method == 'bonus' ? 1.07 : 0.806);
    $guide_data['type']   = 'guide';
	break;

  case 'Michelin Restaurants (DE)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.7);
    $guide_data['type']   = 'guide';
  break; 

  case 'Michelin Restaurants (FR)':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.695);
    $guide_data['type']   = 'guide';
  break;

  case "New York Times":
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.85);
    $guide_data['type']   = 'publication';
  break;

  case 'Opiniated about dining':
     $guide_data['type']   = 'list';
  break;

  case 'Philippine Tatler':
    //TBD
  break;

  case 'Queremos comer':
    $guide_data['type']   = 'user';
  break;

  case 'Resto.be':
    //$guide_data['trust'] = ($method == 'bonus' ? 1 : 0.4);
    $guide_data['type']   = 'user';
  break;

  case 'Resto Tunisie':
    $guide_data['type']   = 'user';
  break;

  case 'Rossouw\'s Restaurants':
    //TBD
  break;

  case 'Schlemmer Atlas':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.464);
    $guide_data['type']   = 'guide';
  break;

  case 'Singapore Tatler':
    // TBD
  break;

  case 'The Sydney Morning Herald Good Food Guide':
    // TBD
  break;

  case 'Tabelog':
    $guide_data['type']   = 'user';
  break;

  case 'Thailand Tatler Best restaurants':
    // TBD
  break;

  case 'Timeout Mexico':
    $guide_data['type']   = 'user';
  break;

	case 'Tripadvisor':
		//$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.612);
    $guide_data['type']   = 'user';
	break;

	case 'Varta-Führer':
		$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.464);
    $guide_data['type']   = 'guide';
	break;

  case 'Verema':
    //$guide_data['trust'] = ($method == 'bonus' ? 1 : 0.457);
    $guide_data['type']   = 'user';
  break;

  case 'Where to eat in Canada':
    $guide_data['trust'] = ($method == 'bonus' ? 1 : 0.775);
    $guide_data['type']   = 'guide';
  break;

  case 'Yelp':
    //$guide_data['trust'] = ($method == 'bonus' ? 1 : 0.45);
    $guide_data['type']   = 'user';
  break;

  case 'Vacay.ca':
    // TBD
  break;

  case 'Viajeros':
    $guide_data['type']   = 'user';
  break;

  case 'White Guide':
    // TBD
  break;

	case 'Zagat':
		//$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.744);
    $guide_data['type']   = 'user';
	break;

	case 'Zomato':
		//$guide_data['trust'] =	($method == 'bonus' ? 1 : 0.426);
    $guide_data['type']   = 'user';
	break;
  }
  // We calculate the popularity publication score
  switch ($guide_data['type']) {
    case 'guide' :       $guide_data['popularity'] = 5;   break;
    case 'publication' : $guide_data['popularity'] = 1;   break;
    case 'list' :        $guide_data['popularity'] = 1;   break;
    case 'user' :        $guide_data['popularity'] = 0.2; break;
  }
  // Let's return all results
  return $guide_data;
}