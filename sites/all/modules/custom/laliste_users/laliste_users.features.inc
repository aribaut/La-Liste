<?php
/**
 * @file
 * laliste_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function laliste_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function laliste_users_image_default_styles() {
  $styles = array();

  // Exported image style: mid_size_thumb.
  $styles['mid_size_thumb'] = array(
    'label' => 'Mid Size Thumb',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_picture.
  $styles['profile_picture'] = array(
    'label' => 'Profile Picture',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
