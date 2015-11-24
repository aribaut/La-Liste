<?php
/**
 * @file
 * Include file for LaListe Ranking Cron/Drush Computation.
 */

/*
 * Mettre un coefficient de fiabilité de 0.5 pour tout les sites participatifs des restaurants qui n'ont que des sites participatifs comme source
 */

/*
** Update all restaurant scores from today's date
*  $pro corresponds to the professional score weight (default to 60%)
*/
function laliste_ranking_update($pro) {
  $guide_not_present = $inserted = 0;
  // let's clear the restaurant stats
  $clear_restaurant_stats = db_query("DELETE FROM {restaurant_stats}");
  // let's clear the ranking scores and popularity
  $clear_ranking_scores = db_query("UPDATE {ranking} SET score=NULL, trust=NULL, popularity=NULL");
	// for all restaurants enabled (default) to be on LA LISTE, compute their scores
	$results = db_query("
	 SELECT nid from {node} LEFT JOIN {field_data_field_restaurant_disabled} disabled ON disabled.entity_id=node.nid
   WHERE disabled.entity_id IS NULL OR disabled.field_restaurant_disabled_value = 0");
	foreach($results as $row) {
		$scores = array();
		$scores = laliste_ranking_compute_restaurant_ranking_score($row->nid, $val);
		// We ONLY treat scores where we have existing business rules
		if($scores != -1) {
			// Do we have a corresponding restaurant in the stats table?
			$stats = db_query("
			SELECT * FROM {restaurant_stats} WHERE restaurant_id = :nid
				", array(':nid' => $row->nid))->fetchObject();
			// We insert if no records exist
			if(!$stats->restaurant_id) {
			  db_insert('restaurant_stats')
	    	  ->fields(array(
	      		'restaurant_id' => $row->nid,
	      		'score_laliste' => floatval($scores['global']),
            'score_pro' => floatval($scores['pro']),
            'score_pub' => floatval($scores['pub']),
            'popularity' => $scores['popularity'],
	      		'created' => time(),
	      		'updated' => time(),
	    	  ))
	    	  ->execute();
          $inserted++;
			}
      // we update records only if the score is changed
			else {
			  db_update('restaurant_stats')
	  		  ->fields(array(
	    	    'score_laliste' => floatval($scores['global']),
            'score_pro' => floatval($scores['pro']),
            'score_pub' => floatval($scores['pub']),
            'popularity' => $scores['popularity'],
	    	    'updated' => time(),
	  		    )
	  		  )
	  		  ->condition('restaurant_id', $row->nid)
	  		  ->execute();
		    }
		}
	 else {
	    	// guide catch error counter
        $guide_not_present++;
        //$guide = db_query("select name from taxonomy_term_data ttd LEFT join restaurantguideranking rgr on rgr.guide_id=ttd.tid where rgr.restaurant_id=:nid", array(':nid' => $row->nid))->fetchObject();
        //echo $guide->name."\n";
	 }
	}
  // we calculate all the ranks
  $ranks = db_query("
    SELECT @curRank := @curRank + 1 AS rank, restaurant_id FROM (SELECT @curRank := 0) r, restaurant_stats LEFT JOIN node ON node.nid = restaurant_stats.restaurant_id  WHERE popularity >= 10 ORDER BY score_laliste DESC LIMIT 1000");
  // we update the stats table
  foreach($ranks as $row) {
    db_update('restaurant_stats')
    ->fields(array(
      'rank' => $row->rank,
      )
    )
    ->condition('restaurant_id', $row->restaurant_id)
    ->execute();
  }
  // error handling
  $score_errors = db_query("SELECT count(*) FROM {ranking} WHERE score > 100")->fetchField();
	echo "LALISTE RANKING IS UP TO DATE!\n";
  echo "================================\n";
  echo "Number of score ranking over 100 : ".$score_errors."\n";
  echo "Number of new records added : ".$inserted."\n";
  echo "Number of records having no food guide entry : ".$guide_not_present."\n";
}

/*
** Calculate the score for each ranking record.
*/
function laliste_ranking_compute_restaurant_ranking_score($restaurant_id, $pro) {

  // for all ranking rows, calculate the score according to guide rule and update row
  $restaurant_rankings = db_query("
    SELECT {restaurantguideranking}.guide_id, {ranking}.ranking_id,
    REPLACE(CAST(food AS CHAR), ',', '.') AS food,
    REPLACE(CAST(bonus AS CHAR), ',', '.') AS bonus,
    REPLACE(CAST(wine AS CHAR), ',', '.') AS wine,
    REPLACE(CAST(service AS CHAR), ',', '.') AS service,
    REPLACE(CAST(atmosphere AS CHAR), ',', '.') AS atmosphere,
    REPLACE(CAST(panorama AS CHAR), ',', '.') AS panorama,
    REPLACE(CAST(quiet AS CHAR), ',', '.') AS quiet,
    value,
    votes
    FROM {ranking}
    LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id
    WHERE {restaurantguideranking}.restaurant_id = :restaurant_id", array(':restaurant_id' => $restaurant_id));
  // counting number of score records for each restaurant
  $n=0;
  foreach($restaurant_rankings as $ranking) {
    $ranking_score = array();
  	// let's calculate scores based on ecach guide's rule.
  	if(isset($ranking->guide_id)) {
  	  $ranking_score = generate_score(
  	  	$ranking->ranking_id,
  	  	$ranking->guide_id,
  	  	$ranking->food+0,
  	  	$ranking->bonus+0,
  	  	$ranking->wine+0,
  	  	$ranking->service+0,
  	  	$ranking->atmosphere+0,
  	  	$ranking->panorama+0,
  	  	$ranking->quiet+0,
  	  	$ranking->value+0,
  	  	$ranking->votes+0
  	  );
      // increment our internal counter
  	  $n=$n+1;
      // if we have a score we can proceeed
      if(isset($ranking_score['score']) && !empty($ranking_score['score']) && !is_null($ranking_score['score'])) {

        // we get the guide's reliability factor (trustworthiness) along with the guide type
        $guide_ranking = laliste_ranking_get_guide_factor($ranking_score['guide']);

        // Default case for user review sites : We set their trust factor to 1
        if(isset($guide_ranking) && ($guide_ranking['type'] == 'user')) {
          $guide_ranking['trust'] = 1;
        }

        // we don't count lists as there bonus is calculated after the counpounded total
        if($ranking_score['score'] < 0) {
          $n=$n-1;
        }

        // calculate the float score
        $score =  floatval($ranking_score['score']);
        // Let's update the ranking table with the raw score for each entry (i.e. before guide coefficient apply)
        db_update('ranking')
          ->fields(array(
            'score' => $score,
            'trust' => $guide_ranking['trust'],
            'popularity' => $guide_ranking['popularity'],
            'updated' => time(),
            )
          )
        ->condition('ranking_id', intval($ranking_score['ranking_id']))
        ->execute();
      }
      else {
        $n=$n-1;
      }
  	}
  }
  // We now divide to obtain the median score with the associated popularity.
  if($n>0) {
    // we select the max trust and apply same grade and trust to all other guides
    $dominant_ranking = db_query("
      SELECT trust, score, popularity FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND popularity = 5 AND score > 0 ORDER BY trust DESC LIMIT 1", array(':restaurant_id' => $restaurant_id))->fetchObject();

    // We only consider a dominant guide who has a score equal or above 93
    if($dominant_ranking->popularity == 5 && $dominant_ranking->score >= 93) {
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
    // compounded scores & popularity via MySQL! for * guides * only
    $compounded_pro = db_query("
      SELECT SUM(score*trust) AS score_pro, ROUND(SUM(popularity),1) AS popularity, count(*) AS n
      FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id
      WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND trust IS NOT null AND score > 0 and popularity >= 5", array(':restaurant_id' => $restaurant_id))->fetchObject();
    // compounded scores & popularity via MySQL! for * public sites * only
    $compounded_pub = db_query("
      SELECT SUM(score*trust) AS score_pub, ROUND(SUM(popularity),1) AS popularity, count(*) AS n
      FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id
      WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND trust IS NOT null AND score > 0 AND popularity >= 0.2 AND popularity < 1", array(':restaurant_id' => $restaurant_id))->fetchObject();
    // do we have a list bonus to add to the coupounded pro score?
    $list_bonus = db_query("
      SELECT score as score_list
      FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id
      WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND score > 0 AND popularity >= 1.5 AND popularity < 5",array(':restaurant_id' => $restaurant_id));
    // do we have a trusted publication bonus to add to the coupounded pro score?
    $trusted_bonus = db_query("
      SELECT score AS score_trusted
      FROM {ranking} LEFT JOIN {restaurantguideranking} ON {restaurantguideranking}.ranking_id = {ranking}.ranking_id
      WHERE {restaurantguideranking}.restaurant_id = :restaurant_id AND score > 0 AND popularity >= 1 AND popularity < 1.5",array(':restaurant_id' => $restaurant_id));
    // calculating the pro median score
    if($compounded_pro->n > 0) {
      $median_pro = $compounded_pro->score_pro/$compounded_pro->n;
    }
    // calculating the public median score
    if($compounded_pub->n > 0) {
      $median_pub = $compounded_pub->score_pub/$compounded_pub->n;
    }
    // calculating the sum of all popularities
    $popularity = $compounded_pro->popularity + $compounded_pub->popularity;
    // calculating the lists bonuses that adds to the pro score
    foreach($list_bonus as $bonus) {
        $median_pro += $bonus->score_list; $popularity += 1.5; break;
    }
    // calculating the trusted publications bonuses that adds to the pro score
    foreach($trusted_bonus as $bonus) {
        $median_pro += $bonus->score_trusted; $popularity += 1; break;
    }
    // combining the pro and public scores for a LA LISTE score
    $median = $median_pro * 0.75 + $median_pub * 0.25;
    // assigning scores values and sum of popularity score to the stats table
    $median_score = array();
    $median_score['global']     = $median;
    $median_score['pro']        = $median_pro;
    $median_score['pub']        = $median_pub;
    $median_score['popularity'] = $popularity;
    return($median_score);
  }
  else return -1; // no guide rule setup for this dataset
}

/*
** The business rules are here!
**
** Model used: Cuisine weight for 80% of the total score
*/
function generate_score($ranking_id, $guide_id, $food, $bonus, $wine, $service, $atmosphere, $panorama, $quiet, $value, $votes) {
  $ranking = array();
  // We extract the taxonomy term to identify the guide
  if(isset($guide_id)) {
    $term = taxonomy_term_load($guide_id);
    $guide = $term->name;
  }
  if(isset($guide)) {
  	// We set the guide to calculate the associated coefficient upon return to function call
    $ranking['guide'] = $guide;
    $ranking['ranking_id'] = $ranking_id;

    switch($guide) {

      case '50 Best':
      case 'Opiniated about dining':
      case 'Elite Traveler':
      case 'Vacay.ca':
      case 'The Daily Meal - 101 best restaurants':
      case 'James Beard Awards':
      case 'Maclean’s Canada’s best restaurant':
        $score = ($food>=1 && $food <=20) ? 0.03 : 0;
        $score += ($food>20 && $food <=50) ? 0.02 : 0;
        $score += ($food>50 && $food <=100) ? 0.01 : 0;
      break;

      case 'The AA Restaurant Guide Automobile Association':
        $score =   ($food == 5 ? 95 : 0);
        $score +=  ($food == 4 ? 85 : 0);
        $score +=  ($food == 3 ? 75 : 0);
        $score +=  ($food == 2 ? 65 : 0);
        $score +=  ($wine == 1 ? 5 : 0);
      break;

      case 'A la Carte':
        $score =  $atmosphere-20;
        $score += ($wine == 3 ? 20 : 0);
        $score += ($wine == 2 ? 10 : 0);
        $score += ($wine == 1 ? 6.7 : 0);
      break;

      case 'Alpha Guide': case 'Athinorama':
        $score =   ($food == 20 ? 100 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16.5 ? 75 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15.5 ? 65 : 0);
        $score +=  ($food == 15 ? 60 : 0);
      break;

      case 'AndyHayler.com (trusted source)':
        $score = ($bonus==20) ? 100 : 0;
        $score += ($bonus==19) ? 95 : 0;
        $score += ($bonus==18) ? 90 : 0;
        $score += ($bonus==17) ? 85 : 0;
        $score += ($bonus==16) ? 80 : 0;
        $score += ($bonus==15) ? 75 : 0;
        $score += ($bonus==14) ? 70 : 0;
        $score += ($bonus==13) ? 65 : 0;
        $score += ($bonus==12) ? 60 : 0;
      break;

      case 'Blue Ribbon':
        $score =   ($food == 3 ? 100 : 0);
        $score +=  ($food == 2 ? 80 : 0);
        $score +=  ($food == 1 ? 60 : 0);
        $score += $bonus;
      break;

      case 'The Brisbane Times Good Food':
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
      break;

      case 'De Danske Spiseguiden':
        $score =   ($food == 5 ? 100 : 0);
        $score +=  ($food == 4 ? 90 : 0);
        $score +=  ($food == 3 ? 80 : 0);
        $score +=  ($food == 2 ? 70 : 0);
        $score +=  ($food == 1 ? 60 : 0);
      break;

      case 'Degusta':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
      break;

      case 'Der große Restaurant- & Hotelguide':
      	if ($bonus == 1) {
      	  $score =  ($food == 5 ? 80 : 0);
      	  $score +=  ($food == 4 ? 73 : 0);
      	}
      	elseif(!isset($bonus) || $bonus == 0) {
      	  $score =  ($food == 5 ? 77 : 0);
      	  $score +=  ($food == 4 ? 70 : 0);
      	}
      	$score += $service*3;
      	$score += ($wine == 3 ? 5 : 0);
      	$score += ($wine == 2 ? 3 : 0);
      	$score += ($wine == 1 ? 1 : 0);
      break;

      case 'Diningcity.hu':
        $score = $food*20;
      break;

      case 'Dining City':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
      break;

      case 'DininginDoha':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
      break;

      case 'Dianping':
        $score =  ($food == 3 ? 100 : 0);
        $score += ($food == 2 ? 90 : 0);
        $score += ($food == 1 ? 80 : 0);
      break;

      case 'Dubai Eating':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
      break;

      case 'Eatability':
        $score =  $food*8;
        $score += $atmosphere;
        $score += $service;
      break;

      case 'Eesti Maitsed':
        //TBD
      break;

      case 'Espresso':
        $score = $food*5;
      break;

      case 'Etterem.hu':
        $score = $food*20;
      break;

      case 'Falstaff':
        $score = $food;
      break;

      case 'Five Diamond Awards':
        $score =   ($food == 5 ? 100 : 0);
        $score +=  ($food == 4 ? 60 : 0);
      break;

      case 'Forbes Travel Guide':
        $score =   ($food == 5 ? 100 : 0);
        $score +=  ($food == 4 ? 65 : 0);
        $score +=  ($food == 3 ? 50 : 0);
      break;

      case 'Foursquare':
        $score = $food*10;
      break;

      case 'Gambero Rosso':
        $score =  $food+17; // Yup, the food is rated out of 60. So add 17 + bonus to reach 80.
        $score +=  ($bonus == 1 ? 3 : 0);
        $score +=  $wine/2;
        $score +=  $service/2;
      break;

      case 'Gault-Millau (AT)': // 95 max
        $score =   ($food == 19 ? 75 : 0);
        $score +=  ($food == 18 ? 70 : 0);
        $score +=  ($food == 17 ? 65 : 0);
        $score +=  ($food == 16 ? 60 : 0);
        $score +=  ($food == 15 ? 55 : 0);
        $score += ($service == 1 ? 20 : 0);
      break;

      case 'Gault-Millau (AU)': // data to be cleaned up
        $score =   ($food == 5 ? 100 : 0);
        $score +=  ($food == 4 ? 90 : 0);
        $score +=  ($food == 3 ? 80 : 0);
        $score +=  ($food == 2 ? 70 : 0);
        $score +=  ($food == 1 ? 55 : 0);
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
      break;

      case 'Gault-Millau (CH)':
        $score =   ($food == 19 ? 100 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15 ? 60 : 0);
      break;

      case 'Gault-Millau (DE)':
        $score +=  ($food == 19.5 ? 80 : 0);
        $score +=  ($food == 19 ? 77 : 0);
        $score +=  ($food == 18 ? 72 : 0);
        $score +=  ($food == 17 ? 67 : 0);
        $score +=  ($food == 16 ? 62 : 0);
        $score += ($service == 1 ? 5 : 0);
        $score += ($bonus == 1 ? $atmosphere*3 : $atmosphere*2);
      break;

      case 'Gault-Millau (FR)':
        $score =  ($food == 5 ? 95 : 0);
        $score +=  ($food == 4 ? 85 : 0);
        $score +=  ($food == 3 ? 75 : 0);
        $score +=  ($food == 2 ? 65 : 0);
        $score +=  ($food == 1 ? 55 : 0);
        $score += ($wine == 1 ? 5 : 0);
      break;

      case 'Gault-Millau (HU)':
        $score +=  ($food == 19 ? 100 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15 ? 60 : 0);
        $score +=  ($food == 14 ? 60 : 0);
      break;

      case 'Gault-Millau (JP)':
        $score =  ($food == 5 ? 100 : 0);
        $score +=  ($food == 4.5 ? 95 : 0);
        $score +=  ($food == 4 ? 90 : 0);
        $score +=  ($food == 3.5 ? 85 : 0);
        $score +=  ($food == 3 ? 80 : 0);
        $score +=  ($food == 2 ? 70 : 0);
        $score +=  ($food == 1 ? 55 : 0);
        $score += $bonus;
      break;

      case 'Gault-Millau (MA)':
        $score +=  ($food == 16.5 ? 75 : 0);
        $score +=  ($food == 16 ? 70 : 0);
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
      break;

      case 'Gault-Millau (PL)':
        $score =   ($food == 19 ? 100 : 0);
        $score =   ($food == 18.5 ? 95 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17.5 ? 85 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16.5 ? 75 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15.5 ? 66 : 0);
        $score +=  ($food == 15 ? 60 : 0);
      break;

      case 'Gayot.com':
        $score +=  ($food == 19 ? 100 : 0);
        $score +=  ($food == 18 ? 90 : 0);
        $score +=  ($food == 17 ? 80 : 0);
        $score +=  ($food == 16 ? 70 : 0);
        $score +=  ($food == 15 ? 60 : 0);
      break;

      case 'Google Reviews':
        $score = $food*20;
      break;

      case 'Guia Repsol':
        $score =  ($food == 3 ? 80 : 0);
        $score += ($food == 2 ? 70 : 0);
        $score += ($food == 1 ? 60 : 0);
        $score += $wine*2;
        $score += $service*2;
      break;

      case 'The Good Food Guide':
        $score =  ($food == 10 ? 95 : 0);
        $score += ($food == 9 ? 85 : 0);
        $score += ($food == 8 ? 75 : 0);
        $score += ($food == 7 ? 70 : 0);
        $score += ($food == 6 ? 65 : 0);
        $score += ($food == 5 ? 60 : 0);
        $score += ($food == 4 ? 55 : 0);
        $score += ($food == 3 ? 50 : 0);
        $score += ($wine == 1 ? 5 : 0);
      break;

      case 'Guía Gourmet':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
      break;

      case 'Guia Josimar Melo':
        $score =  ($food == 3 ? 100 : 0);
        $score += ($food == 2 ? 80 : 0);
        $score += ($food == 1 ? 60 : 0);
      break;

      case 'Guía Prestigio':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
      break;

      case 'Guía Summum':
        $score = $food*10;
      break;

      case 'Guia4rodas':
        $score =  ($food == 3 ? 80 : 0);
        $score += ($food == 2 ? 70 : 0);
        $score += ($food == 1 ? 60 : 0);
        $score += $atmosphere*4;
      break;

      case 'GuíaOleo':
        $score = $food*2.666;
        $score += $service/3;
        $score += $atmosphere/3;
      break;

      case 'Gusto':
        // raw
      	if ($bonus == 1) {
      	  $score =  ($food == 10 ? 80 : 0);
      	  $score +=  ($food == 9 ? 73 : 0);
      	  $score +=  ($food == 8 ? 63 : 0);
      	}
      	elseif(!isset($bonus) || $bonus == 0) {
      	  $score =  ($food == 10 ? 77 : 0);
      	  $score +=  ($food == 9 ? 70 : 0);
      	  $score +=  ($food == 8 ? 60 : 0);
      	}
      	elseif($bonus == -1) {
      	  $score =  ($food == 10 ? 74 : 0);
      	  $score +=  ($food == 9 ? 67 : 0);
      	}
      	$score += $atmosphere*4;
      	 // service?
      break;

      case 'Harden\'s':
        $score = $food*16;
        $score += $atmosphere*2;
        $score += $service*2;
      break;

      case 'James Beard Awards':
      case 'Afisha.ru':
        $score = $food*10;
      break;

      case 'La Suisse Gourmande':
        $score =  ($food == 100 ? 100 : 0);
        $score +=  ($food == 90 ? 90 : 0);
      break;

      case "La fourchette":
        $score = $food*10;
      break;

      case "L'Internaute":
        $score = $food*16;
        $score += $atmosphere;
        $score += $bonus;
        $score += $service*2;
      break;

      case 'Michelin' :
      case 'Michelin (JP)':
      	$score =  ($food == 3 ? 80 : 0);
      	$score += ($food == 2 ? 70 : 0);
      	$score += ($food == 1 ? 60 : 0);
      	$score += ($food == '0,5' ? 50 : 0); // Bib gourmand notation
        if (is_null($score) || empty($score)) { // we count all variations of no stars
          $food += 40;
        }
      	$score += ($wine == 1 ? 7.5 : 0);
      	$score += ($bonus == 1 ? $atmosphere*2.5 : $atmosphere*1.5);
      break;

      case 'Michelin Restaurants (FR)':
      case 'Michelin Restaurants (DE)':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
      break;

      case "New York Times":
        $score = $food*25;
      break;

      case 'Poland 100 best restaurants':
        $score =  ($food == 3 ? 100 : 0);
        $score +=  ($food == 2 ? 80 : 0);
        $score +=  ($food == 1 ? 60 : 0);
      break;

      case 'Queremos comer':
        $score = $food*5;
      break;

      case 'Resto Tunisie':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
      break;

      case 'Rossouw\'s Restaurants':
        $score = $food*16;
        $score += ($wine == 1 ? 10 : 0);
        $score += ($service == 1 ? 10 : 0);
      break;

      case 'Schlemmer Atlas':
        $score = $food*16;
        $score +=  ($wine == 1 ? 5 : 0);
        $score +=  ($service == 1 ? 15 : 0);
      break;

      case 'Singapore Tatler':
      case 'Philippines Tatler':
      case 'Malaysia Tatler':
      case 'Hong Kong Tatler':
        $score = $food*16;
        $score += $wine;
        $score += $atmosphere;
        $score += $service*2;
      break;

      case 'Tabelog':
        $score = $food*20;
      break;

      case 'Thailand Tatler Best restaurants':
        $score = $food*8;
        $score += $wine/2;
        $score += $atmosphere/2;
        $score += $service;
      break;

      case 'Timeout' :
      case 'Timeout Mexico':
      case 'Time Out (CN)':
      case 'Time Out (RU)':
        $score = $food*20;
        $score += $bonus;
      break;

      case 'Timeout Food Awards':
      case 'Timeout Bahrein Restaurant Awards':
      case 'Timeout Food Awards Doha':
      case 'Timeout Abu Dhabi Restaurant Awards':
      case 'Timeout Food Awards Dubai':
      case 'Timeout Israel Eating & Drinking Awards':
      case 'Timeout KL Food Awards':
      case 'Timeout Melbourne Food Awards':
      case 'Timeout Sidney Food Awards':
        $score =  ($food == 1 ? 100 : 0);
        $score += ($food == 2 ? 90 : 0);
        $score += ($food == 3 ? 80 : 0);
      break;

      case 'The Sydney Morning Herald Good Food Guide':
        $score =  ($food == 3 ? 100 : 0);
        $score +=  ($food == 2 ? 80 : 0);
        $score +=  ($food == 1 ? 60 : 0);
      break;

      case 'Traveltipz.ru':
        $score = $food*20;
      break;

      case 'Tripadvisor':
      case 'Diningcity.cn':
        	$score = $food*16;
        	$score += $service*2;
        	$score += $atmosphere*2;
      break;

      case 'Varta-Führer':
      	if ($bonus) {
      	  $score =  ($food == 5 ? 80 : 0);
      	  $score +=  ($food == 4 ? 70 : 0);
      	  $score +=  ($food == 3 ? 60 : 0);
      	}
      	else {
      	  $score =  ($food == 5 ? 75 : 0);
      	  $score +=  ($food == 4 ? 65 : 0);
      	  $score +=  ($food == 3 ? 55 : 0);
      	}
      	$score += ($atmosphere == 1 ? 10 : 0);
      	$score += ($service == 1 ? 10 : 0);
      break;

      case 'Verema': // @todo to be verified
        // raw
        $score = $food*8;
        $score += $wine;
        $score += $atmosphere;
      break;

      case 'Viajeros':
        $score = $food*16;
        $score += $service*2;
        $score += $atmosphere*2;
      break;

      case 'Via restó':
        $score = $food*8;
        $score += $service;
        $score += $atmosphere;
      break;

      case 'voyage.michelin.fr (trusted source)':
        $score =  ($food==3) ? 0.03 : 0;
        $score += ($food==2) ? 0.02 : 0;
        $score += ($food==1) ? 0.01 : 0;
      break;

      case 'Wine Spectator (trusted source)':
        $score = ($wine==3) ? 0.03 : 0;
        $score += ($wine==2) ? 0.02 : 0;
        $score += ($wine==1) ? 0.01 : 0;
      break;

      case 'Where to eat in Canada':
        $score =  ($food == 3 ? 100 : 0);
        $score +=  ($food == 2 ? 80 : 0);
        $score +=  ($food == 1 ? 60 : 0);
      break;

      case 'White Guide':
        $score =  ($bonus == 39 ? 80 : 0);
        $score += ($bonus == 38 ? 75 : 0);
        $score += ($bonus == 37 ? 70 : 0);
        $score += ($bonus == 36 ? 65 : 0);
        $score += ($bonus == 35 ? 60 : 0);
        $score += ($bonus == 34 ? 55 : 0);
        $score += ($bonus == 33 ? 50 : 0);
        if($score) {
          $score += $service/2.5;
          $tmp = $food - ($bonus+$service); // complicated calculation!
          $score += ($tmp * 4/7)/4; // for wine
          $score += ($tmp * 3/7)/3; // for ambiance
        }
      break;

      case 'White Guide (DK)':
        $score =  ($bonus == 39 ? 80 : 0);
        $score += ($bonus == 38 ? 70 : 0);
        $score += ($bonus == 37 ? 60 : 0);
        $score += ($bonus == 36 ? 50 : 0);
        $score += ($bonus == 35 ? 50 : 0);
        if($score) {
          $score += $service/2.5;
          $tmp = $food - ($bonus+$service); // complicated calculation!
          $score += ($tmp * 4/7)/4; // for wine
          $score += ($tmp * 3/7)/3; // for ambiance
        }
      break;

      case 'Yelp':
          $score = $food*20;
      break;

      case 'Zagat':
        // raw
        $score = $food*2.666;
        $score += $atmosphere/3;
        $score += $service/3;
      break;

      case 'Der Feinschmecker':
      case 'Openrice':
      case 'OpenTable':
      case 'Resto.be':
      case 'Salir a Comer':
      case 'Veja':
      case 'Zomato':
      	$score = $food*20;
      break;
    }
  }
  // we only count user sites with 20+ reviews. Discard the rest
  if($votes > 0 && $votes < 20) {
    $score = null;
  }
  $ranking['score'] = $score;
  return $ranking;
}

/*
** Implements data structure for Guides. Will need to be associated to Drupal Taxonomy.
*/
function laliste_ranking_get_guide_factor($guide_name) {
  // get the guide relaibility factor from survey results (default) or from fixed 'bonus' method from drush cmd line.
  switch($guide_name) {

  case '50 Best': case 'Opiniated about dining': case 'Elite Traveler': case 'Vacay.ca':
  case 'The Daily Meal - 101 best restaurants': case 'James Beard Awards':
    $guide_data['type']  = 'list';
  break;

  case 'The AA Restaurant Guide Automobile Association':
    $guide_data['trust'] = 0.609;
    $guide_data['type']  = 'guide';
  break;

  case 'A la Carte':
    $guide_data['trust'] = 0.588;
    $guide_data['type']  = 'guide';
  break;

  case 'AndyHayler.com (trusted source)':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'Blue Ribbon':
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['type']  = 'guide';
  break;

  case 'Openrice':
    $guide_data['type']  = 'user';
  break;

  case 'Eesti Maitsed':
    $guide_data['type']  = 'guide';
  break;

  case 'James Beard Awards':
    $guide_data['type']  = 'publication';
  break;

  case 'Afisha.ru':
    $guide_data['type']  = 'user';
  break;

  case 'Poland 100 best restaurants':
    $guide_data['type']  = 'guide';
  break;

  case 'Alpha Guide':
    $guide_data['type']  = 'guide';
  break;

  case 'Athinorama':
    $guide_data['type']  = 'guide';
  break;

  case 'The Brisbane Times Good Food':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'De Danske Spiseguiden':
    $guide_data['trust'] = 0.5;
    $guide_data['type']  = 'guide';
  break;

  case 'Guide Delta':
    $guide_data['trust'] = 0.35;
    $guide_data['type']  = 'guide';
  break;

  case 'Degusta':
    $guide_data['type']  = 'user';
  break;

	case 'Der Feinschmecker':
		$guide_data['trust'] =	0.574;
    $guide_data['type']  = 'guide';
	break;

	case 'Der große Restaurant- & Hotelguide':
		$guide_data['trust'] =	0.41;
    $guide_data['type']  = 'guide';
	break;

  case 'Dianping':
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['type']  = 'guide';
    $guide_data['trust'] =  0.7;
  break;

  case 'Dining City':
    $guide_data['type']  = 'user';
  break;

  case 'Diningcity.cn':
    $guide_data['type']  = 'user';
  break;

  case 'Diningcity.hu':
    $guide_data['type']  = 'user';
  break;

  case 'DininginDoha':
    $guide_data['type']  = 'user';
  break;

  case 'Dubai Eating':
    $guide_data['type']  = 'user';
  break;

  case 'Eatability':
    $guide_data['type']  = 'user';
  break;

  case 'Espresso':
    $guide_data['trust'] = 0.708;
    $guide_data['type']  = 'guide';
  break;

  case 'Etterem.hu':
    $guide_data['type']  = 'user';
  break;

  case 'Falstaff':
    $guide_data['type']  = 'user';
  break;

	case 'Five Diamond Awards':
		$guide_data['trust'] =	0.61;
    $guide_data['type']  = 'guide';
	break;

	case 'Forbes Travel Guide':
    $guide_data['trust'] =  0.61;
    $guide_data['type']  = 'guide';
	break;

  case 'Foursquare':
    $guide_data['type']  = 'user';
  break;

  case 'Gambero Rosso':
    $guide_data['trust'] = 0.706;
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (AT)':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (AU)':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (BE)':
    $guide_data['trust'] = 0.6;
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (CH)':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (DE)':
    $guide_data['trust'] = 0.603;
    $guide_data['type']  = 'guide';
  break;

	case 'Gault-Millau (FR)':
		$guide_data['trust'] =	0.709;
    $guide_data['type']  = 'guide';
	break;

  case 'Gault-Millau (HU)':
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (JP)':
    $guide_data['trust'] =  0.8; // arbitrary
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (MA)':
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (NL)':
    $guide_data['type']  = 'guide';
  break;

  case 'Gault-Millau (PL)':
    $guide_data['type']  = 'guide';
  break;

	case 'Gayot.com':
		$guide_data['trust'] =	0.586;
    $guide_data['type']  = 'guide';
	break;

  case 'The Good Food Guide':
    $guide_data['trust'] = 0.661;
    $guide_data['type']  = 'guide';
  break;

  case 'Google Reviews':
    $guide_data['type']  = 'user';
  break;

  case 'Guía Gourmet':
    $guide_data['type']  = 'user';
  break;

  case 'Guia Josimar Melo':
    $guide_data['type']  = 'guide';
  break;

  case 'Guía Prestigio':
    $guide_data['type']  = 'user';
  break;

  case 'Guía Summum':
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['type']  = 'guide';
  break;

	case 'Guia Repsol':
		$guide_data['trust'] =	0.66;
    $guide_data['type']  = 'guide';
	break;

  case 'Guia4rodas':
    $guide_data['trust'] =  0.718;
    $guide_data['type']  = 'guide';
  break;

  case 'GuíaOleo':
    $guide_data['type']  = 'user';
  break;

	case 'Gusto':
		$guide_data['trust'] =	0.598;
    $guide_data['type']  = 'guide';
	break;

  case 'Harden\'s':
    $guide_data['type']  = 'user';
  break;

  case 'La Suisse Gourmande':
    $guide_data['trust'] = 0.63;
    $guide_data['type']  = 'guide';
  break;

  case "La fourchette":
    $guide_data['type']  = 'user';
  break;

  case "L'Internaute":
    $guide_data['type']  = 'user';
  break;

  case 'Maclean’s Canada’s best restaurant':
    $guide_data['type']  = 'list';
  break;

	case 'Michelin':
		$guide_data['trust'] =	0.791;
    $guide_data['type']  = 'guide';
	break;

  case 'Michelin (JP)':
    $guide_data['trust'] =  0.791; // arbitrary - test only
    $guide_data['type']  = 'guide';
  break;

  case 'Michelin Restaurants (DE)':
    $guide_data['type']  = 'user';
  break;

  case 'Michelin Restaurants (FR)':
    $guide_data['type']  = 'user';
  break;

  case "New York Times":
    $guide_data['trust'] = 0.741;
    $guide_data['type']  = 'guide';
  break;

  case 'OpenTable':
    $guide_data['type']  = 'user';
  break;

  case 'Opiniated about dining':
     $guide_data['type'] = 'list';
  break;

  case 'Philippines Tatler':
    $guide_data['type']  = 'guide';
  break;

  case 'Queremos comer':
    $guide_data['type']  = 'user';
  break;

  case 'Resto.be':
    $guide_data['type']  = 'user';
  break;

  case 'Resto Tunisie':
    $guide_data['type']  = 'user';
  break;

  case "Rossouw's Restaurants":
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['trust'] = 0.46;
    $guide_data['type']  = 'guide';
  break;

  case 'Salir a Comer':
    $guide_data['type']  = 'user';
  break;

  case 'Schlemmer Atlas':
    $guide_data['trust'] = 0.466;
    $guide_data['type']  = 'guide';
  break;

  case 'Singapore Tatler':
    $guide_data['trust'] = 0.55;
    $guide_data['type']  = 'guide';
  break;

  case 'The Sydney Morning Herald Good Food Guide':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'Tabelog':
    $guide_data['type']  = 'user';
  break;

  case 'Thailand Tatler Best restaurants':
    $guide_data['trust'] = 0.7;
    $guide_data['type']  = 'guide';
  break;

  case 'Timeout':
    $guide_data['trust'] = 0.6;
    $guide_data['type']  = 'guide';
  break;

  case 'Timeout Food Awards': // chine
  case 'Timeout Bahrein Restaurant Awards':
  case 'Timeout Food Awards Doha':
  case 'Timeout Abu Dhabi Restaurant Awards':
  case 'Timeout Food Awards Dubai':
  case 'Timeout KL Food Awards':
  case 'Timeout Israel Eating & Drinking Awards':
  case 'Timeout Food & Drink Awards Istanbul':
    $guide_data['type']  = 'guide';
    $guide_data['unique'] = true;; // special case for being unique guide in country
  break;

  case 'Timeout Melbourne Food Awards':
  case 'Timeout Sidney Food Awards':
    $guide_data['type']  = 'guide';
  break;

  case 'Timeout Mexico':
  case 'Time Out (CN)':
  case 'Time Out (RU)':
    $guide_data['unique'] = true; // special case for being unique guide in country
    $guide_data['type']  = 'guide';
  break;

  case 'Traveltipz.ru':
    $guide_data['type'] = 'user';
  break;

	case 'Tripadvisor':
    $guide_data['type']  = 'user';
	break;

	case 'Varta-Führer':
		$guide_data['trust'] = 0.498;
    $guide_data['type']  = 'guide';
	break;

  case 'Verema':
    $guide_data['type']  = 'user';
  break;

  case 'Where to eat in Canada':
    $guide_data['trust'] = 0.68;
    $guide_data['type']  = 'guide';
  break;

  case 'Yelp':
    $guide_data['type']  = 'user';
  break;

  case 'Veja':
    $guide_data['type']  = 'guide';
  break;

  case 'Viajeros':
    $guide_data['type']  = 'user';
  break;

  case 'Via restó':
    $guide_data['type']  = 'user';
  break;

  case 'voyage.michelin.fr (trusted source)':
    $guide_data['type']  = 'publication';
  break;

  case 'Wine Spectator (trusted source)':
    $guide_data['type']  = 'publication';
  break;

  case 'White Guide':
  case 'White Guide (DK)':
    $guide_data['trust'] = 0.733;
    $guide_data['type']  = 'guide';


	case 'Zagat':
    $guide_data['type']  = 'user';
	break;

	case 'Zomato':
    $guide_data['type']  = 'user';
	break;
  }
  // We calculate the popularity publication score if not set
  if (!isset($guide_data['popularity'])) {
    switch ($guide_data['type']) {
      case 'guide' :       $guide_data['popularity'] = 5;   break;
      case 'list' :        $guide_data['popularity'] = 1.5; break;
      case 'publication' : $guide_data['popularity'] = 1;   break;
      case 'user' :        $guide_data['popularity'] = 0.2; break;
    }
  }
  // default trust factor to 0.5
  if($guide_data['type']  == 'guide' && !isset($guide_data['trust'])) {
    $guide_data['trust'] = 0.5;
  }
  // special handling for countries with only 1 guide
  if($guide_data['unique']) {
    $guide_data['popularity'] *= 2;
  }
  // Let's return all results and mark not set trust to -1 for debug
  if (!isset($guide_data['trust']) || empty($guide_data['trust'])) {
    $guide_data['trust'] = -1;
  }
  return $guide_data;
}
