<?php
/**
 * @file
 * laliste_liste_ct.features.inc
 */

/**
 * Implements hook_node_info().
 */
function laliste_liste_ct_node_info() {
  $items = array(
    'liste' => array(
      'name' => t('Liste'),
      'base' => 'node_content',
      'description' => t('Provides a listing of restaurants.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
