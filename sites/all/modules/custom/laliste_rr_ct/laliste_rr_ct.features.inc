<?php
/**
 * @file
 * laliste_rr_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function laliste_rr_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "data" && $api == "data_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function laliste_rr_ct_node_info() {
  $items = array(
    'restaurant' => array(
      'name' => t('Restaurant'),
      'base' => 'node_content',
      'description' => t('This defines a restaurant entry.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
