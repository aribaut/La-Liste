<?php
/**
 * @file
 * laliste_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function laliste_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'laliste_layout_homepage_context';
  $context->description = 'Default Homepage for LA LISTE';
  $context->tag = 'homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'header',
          'weight' => '-9',
        ),
        'views-homepage_slider-block' => array(
          'module' => 'views',
          'delta' => 'homepage_slider-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-laliste_search_view-page' => array(
          'module' => 'views',
          'delta' => '-exp-laliste_search_view-page',
          'region' => 'content',
          'weight' => '-8',
        ),
        'laliste_homepage-home_highlight' => array(
          'module' => 'laliste_homepage',
          'delta' => 'home_highlight',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-cbbe77509a0d5dfa927448406b230347' => array(
          'module' => 'views',
          'delta' => 'cbbe77509a0d5dfa927448406b230347',
          'region' => 'content',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default Homepage for LA LISTE');
  t('homepage');
  $export['laliste_layout_homepage_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'laliste_layout_restaurant_node_page_context';
  $context->description = 'Provides a layout for a restaurant node';
  $context->tag = 'layout';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'restaurant' => 'restaurant',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-10',
        ),
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'header',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides a layout for a restaurant node');
  t('layout');
  $export['laliste_layout_restaurant_node_page_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'laliste_sidewide_context';
  $context->description = 'Provides a sitewide context';
  $context->tag = 'sitewide';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'header',
          'weight' => '-19',
        ),
        'views--exp-laliste_search_view-page' => array(
          'module' => 'views',
          'delta' => '-exp-laliste_search_view-page',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides a sitewide context');
  t('sitewide');
  $export['laliste_sidewide_context'] = $context;

  return $export;
}
