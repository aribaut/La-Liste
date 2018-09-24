<?php
/**
 * @file
 * laliste_homepage_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function laliste_homepage_content_type_node_info() {
  $items = array(
    'homepage_featured_image' => array(
      'name' => t('Homepage Featured Image'),
      'base' => 'node_content',
      'description' => t('Provides a carrousel type content block view powered by Flexslider library.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
