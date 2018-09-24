<?php
/**
 * @file
 * laliste_publication_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function laliste_publication_content_type_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('Contains all publication details about LA LISTE.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
