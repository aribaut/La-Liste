<?php
/**
 * @file
 * laliste_search.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function laliste_search_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|restaurant|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'restaurant';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|restaurant|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function laliste_search_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|restaurant|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'restaurant';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_restaurant_image',
      ),
      'right' => array(
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_restaurant_image' => 'left',
      'title' => 'right',
    ),
    'limit' => array(
      'field_restaurant_image' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 1,
  );
  $export['node|restaurant|search_result'] = $ds_layout;

  return $export;
}
