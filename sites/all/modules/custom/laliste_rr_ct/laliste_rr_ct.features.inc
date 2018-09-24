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
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function laliste_rr_ct_image_default_styles() {
  $styles = array();

  // Exported image style: full-width_slider_image.
  $styles['full-width_slider_image'] = array(
    'label' => 'Full-width slider image',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1408,
          'height' => 444,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
