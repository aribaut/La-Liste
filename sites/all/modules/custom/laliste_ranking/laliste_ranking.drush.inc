<?php

/**
* Implements hook_drush_command().
*/
function laliste_ranking_drush_command() {
  return array(
	'update-laliste' => array(
	  'description' => dt('Update All the Restaurant Scores.'),
	  'arguments' => array(
        'method' => 'Method used for computation of LA LISTE',
      ),
	  'alias' => array('upll'),
    ),
  );
}

/**
* Compute LA LISTE.
*/
function drush_laliste_ranking_update_laliste($val = false) {
  module_load_include('inc', 'laliste_ranking');
  laliste_ranking_update($val);
}
