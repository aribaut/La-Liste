<?php
/**
 * @file
 * laliste_rr_ct.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function laliste_rr_ct_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_flexslider';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'image_style' => '',
  );
  $export['image__default__file_field_flexslider'] = $file_display;

  return $export;
}
