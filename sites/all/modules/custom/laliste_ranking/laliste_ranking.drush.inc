<?php

/**
* Implements hook_drush_command().
*/
function laliste_ranking_drush_command() {
  return array(
  	'update-laliste' => array(
  	  'description' => t('Update All the Restaurant Scores.'),
  	  'arguments' => array(
          'method' => 'Method used for computation of LA LISTE',
        ),
  	  'alias' => array('upll'),
    ),
    'update-scores-search' => array(
      'description' => t('Update Restaurants with LA LISTE scores for Search'),
      'alias' => array('upsc'),
    ),
    'translate-restaurant-nodes' => array(
      'description' => t('Translate Restaurant nodes'),
      'alias' => array('translate'),
    ),
  );
}

/**
* Compute LA LISTE.
*/
function drush_laliste_ranking_update_laliste($pro = false) {
  module_load_include('inc', 'laliste_ranking');
  laliste_ranking_update($val);
}

/**
 * Update Restaurants scores for Search
 */
function drush_laliste_ranking_update_scores_search() {
  module_load_include('inc', 'laliste_ranking');
  update_scores_search();
}

/**
 * Create translations for all restaurant nodes
 */
function drush_laliste_ranking_translate_restaurant_nodes() {
  module_load_include('inc', 'laliste_ranking');
  translate_restaurant_nodes();
}
