<?php
/**
 * @file
 * laliste_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function laliste_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'laliste_rr_countries_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_countries_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_address_country' => 'field_address_country',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_address_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Restaurantguideranking: Guide ID */
  $handler->display->display_options['relationships']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['relationships']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['guide_id']['field'] = 'guide_id';
  /* Relationship: Restaurantguideranking: Ranking ID */
  $handler->display->display_options['relationships']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['relationships']['ranking_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['ranking_id']['field'] = 'ranking_id';
  /* Relationship: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['relationships']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['restaurant_id']['field'] = 'restaurant_id';
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country_1']['id'] = 'field_address_country_1';
  $handler->display->display_options['fields']['field_address_country_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country_1']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country_1']['label'] = '';
  $handler->display->display_options['fields']['field_address_country_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_country_1']['display_name'] = 0;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['path'] = 'country/[field_address_country_1]/view';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Sort criterion: Content: Address - Country */
  $handler->display->display_options['sorts']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['sorts']['field_address_country']['field'] = 'field_address_country';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'countries';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_countries_view'] = array(
    t('Default'),
    t('Restaurant Guide Ranking'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('There is no data in this table.'),
    t('restaurantguideranking.guide_id -> taxonomy_term_data.tid'),
    t('restaurantguideranking.ranking_id -> ranking.ranking_id'),
    t('restaurantguideranking.restaurant_id -> node.nid'),
    t('Country'),
    t('Page'),
  );
  $export['laliste_rr_countries_view'] = $view;

  $view = new view();
  $view->name = 'laliste_rr_restaurant_add_new';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_restaurant_add_new';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Restaurant Add';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'restaurant_id' => 'restaurant_id',
    'guide_id' => 'guide_id',
    'ranking_id' => 'ranking_id',
    'created' => 'created',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'restaurant_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'guide_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'ranking_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'updated' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Restaurantguideranking: Guide ID */
  $handler->display->display_options['relationships']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['relationships']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['guide_id']['field'] = 'guide_id';
  /* Relationship: Restaurantguideranking: Ranking ID */
  $handler->display->display_options['relationships']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['relationships']['ranking_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['ranking_id']['field'] = 'ranking_id';
  /* Relationship: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['relationships']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['restaurant_id']['field'] = 'restaurant_id';
  /* Field: Content: Title form field */
  $handler->display->display_options['fields']['title_edit']['id'] = 'title_edit';
  $handler->display->display_options['fields']['title_edit']['table'] = 'node';
  $handler->display->display_options['fields']['title_edit']['field'] = 'title_edit';
  $handler->display->display_options['fields']['title_edit']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['title_edit']['label'] = 'Name';
  /* Field: Ranking: Food form field */
  $handler->display->display_options['fields']['food']['id'] = 'food';
  $handler->display->display_options['fields']['food']['table'] = 'ranking';
  $handler->display->display_options['fields']['food']['field'] = 'food';
  $handler->display->display_options['fields']['food']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['food']['label'] = 'Food';
  /* Field: Ranking: Atmosphere form field */
  $handler->display->display_options['fields']['atmosphere']['id'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['table'] = 'ranking';
  $handler->display->display_options['fields']['atmosphere']['field'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['atmosphere']['label'] = 'Ambiance';
  /* Field: Ranking: Service form field */
  $handler->display->display_options['fields']['service']['id'] = 'service';
  $handler->display->display_options['fields']['service']['table'] = 'ranking';
  $handler->display->display_options['fields']['service']['field'] = 'service';
  $handler->display->display_options['fields']['service']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['service']['label'] = 'Service';
  /* Field: Ranking: Wine form field */
  $handler->display->display_options['fields']['wine']['id'] = 'wine';
  $handler->display->display_options['fields']['wine']['table'] = 'ranking';
  $handler->display->display_options['fields']['wine']['field'] = 'wine';
  $handler->display->display_options['fields']['wine']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['wine']['label'] = 'Wine';
  /* Field: Ranking: Value form field */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ranking';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['value']['label'] = 'Value';
  /* Field: Ranking: Votes form field */
  $handler->display->display_options['fields']['votes']['id'] = 'votes';
  $handler->display->display_options['fields']['votes']['table'] = 'ranking';
  $handler->display->display_options['fields']['votes']['field'] = 'votes';
  $handler->display->display_options['fields']['votes']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['votes']['label'] = 'Votes';
  /* Field: Restaurantguideranking: Updated */
  $handler->display->display_options['fields']['updated']['id'] = 'updated';
  $handler->display->display_options['fields']['updated']['table'] = 'restaurantguideranking';
  $handler->display->display_options['fields']['updated']['field'] = 'updated';
  /* Field: Ranking: Ranking ID */
  $handler->display->display_options['fields']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['table'] = 'ranking';
  $handler->display->display_options['fields']['ranking_id']['field'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['label'] = '';
  $handler->display->display_options['fields']['ranking_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ranking_id']['element_label_colon'] = FALSE;
  /* Contextual filter: Restaurantguideranking: Guide ID */
  $handler->display->display_options['arguments']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['arguments']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['arguments']['guide_id']['field'] = 'guide_id';
  $handler->display->display_options['arguments']['guide_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['guide_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['guide_id']['title'] = 'Adding %1 Restaurant';
  $handler->display->display_options['arguments']['guide_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['guide_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['guide_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['guide_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['guide_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['guide_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['guide_id']['validate_options']['vocabularies'] = array(
    'guides' => 'guides',
  );
  $handler->display->display_options['arguments']['guide_id']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['guide_id']['validate_options']['transform'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'restaurants/%/add';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_restaurant_add_new'] = array(
    t('Default'),
    t('Restaurant Add'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('There is no data in this table.'),
    t('restaurantguideranking.guide_id -> taxonomy_term_data.tid'),
    t('restaurantguideranking.ranking_id -> ranking.ranking_id'),
    t('restaurantguideranking.restaurant_id -> node.nid'),
    t('Name'),
    t('Food'),
    t('Ambiance'),
    t('Service'),
    t('Wine'),
    t('Value'),
    t('Votes'),
    t('Updated'),
    t('.'),
    t(','),
    t('All'),
    t('Adding %1 Restaurant'),
    t('Page'),
  );
  $export['laliste_rr_restaurant_add_new'] = $view;

  $view = new view();
  $view->name = 'laliste_rr_restaurant_guides_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_restaurant_guides_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'restaurant_id' => 'restaurant_id',
    'guide_id' => 'guide_id',
    'ranking_id' => 'ranking_id',
    'created' => 'created',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'restaurant_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'guide_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'ranking_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'updated' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Restaurantguideranking: Guide ID */
  $handler->display->display_options['relationships']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['relationships']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['guide_id']['field'] = 'guide_id';
  /* Relationship: Restaurantguideranking: Ranking ID */
  $handler->display->display_options['relationships']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['relationships']['ranking_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['ranking_id']['field'] = 'ranking_id';
  /* Relationship: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['relationships']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['restaurant_id']['field'] = 'restaurant_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['title']['label'] = 'Restaurant';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'guide_id';
  $handler->display->display_options['fields']['name']['label'] = 'Guide';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Ranking: Food form field */
  $handler->display->display_options['fields']['food']['id'] = 'food';
  $handler->display->display_options['fields']['food']['table'] = 'ranking';
  $handler->display->display_options['fields']['food']['field'] = 'food';
  $handler->display->display_options['fields']['food']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['food']['label'] = 'Food';
  /* Field: Ranking: Bonus form field */
  $handler->display->display_options['fields']['bonus']['id'] = 'bonus';
  $handler->display->display_options['fields']['bonus']['table'] = 'ranking';
  $handler->display->display_options['fields']['bonus']['field'] = 'bonus';
  $handler->display->display_options['fields']['bonus']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['bonus']['label'] = 'Bonus';
  /* Field: Ranking: Atmosphere form field */
  $handler->display->display_options['fields']['atmosphere']['id'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['table'] = 'ranking';
  $handler->display->display_options['fields']['atmosphere']['field'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['atmosphere']['label'] = 'Ambiance';
  /* Field: Ranking: Service form field */
  $handler->display->display_options['fields']['service']['id'] = 'service';
  $handler->display->display_options['fields']['service']['table'] = 'ranking';
  $handler->display->display_options['fields']['service']['field'] = 'service';
  $handler->display->display_options['fields']['service']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['service']['label'] = 'Service';
  /* Field: Ranking: Wine form field */
  $handler->display->display_options['fields']['wine']['id'] = 'wine';
  $handler->display->display_options['fields']['wine']['table'] = 'ranking';
  $handler->display->display_options['fields']['wine']['field'] = 'wine';
  $handler->display->display_options['fields']['wine']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['wine']['label'] = 'Wine List';
  /* Field: Ranking: Panorama form field */
  $handler->display->display_options['fields']['panorama']['id'] = 'panorama';
  $handler->display->display_options['fields']['panorama']['table'] = 'ranking';
  $handler->display->display_options['fields']['panorama']['field'] = 'panorama';
  $handler->display->display_options['fields']['panorama']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['panorama']['label'] = 'Panorama';
  /* Field: Ranking: Quiet form field */
  $handler->display->display_options['fields']['quiet']['id'] = 'quiet';
  $handler->display->display_options['fields']['quiet']['table'] = 'ranking';
  $handler->display->display_options['fields']['quiet']['field'] = 'quiet';
  $handler->display->display_options['fields']['quiet']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['quiet']['label'] = 'Terrace';
  /* Field: Ranking: Value form field */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ranking';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['value']['label'] = 'Value';
  /* Field: Ranking: Votes form field */
  $handler->display->display_options['fields']['votes']['id'] = 'votes';
  $handler->display->display_options['fields']['votes']['table'] = 'ranking';
  $handler->display->display_options['fields']['votes']['field'] = 'votes';
  $handler->display->display_options['fields']['votes']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['votes']['label'] = 'Votes';
  /* Field: Ranking: Link form field */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'ranking';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['link']['label'] = 'Link';
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  /* Field: Ranking: Ranking ID */
  $handler->display->display_options['fields']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['table'] = 'ranking';
  $handler->display->display_options['fields']['ranking_id']['field'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['label'] = '';
  $handler->display->display_options['fields']['ranking_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ranking_id']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Address - Country */
  $handler->display->display_options['sorts']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['sorts']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['relationship'] = 'restaurant_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'restaurant_id';
  /* Contextual filter: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['arguments']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['arguments']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['arguments']['restaurant_id']['field'] = 'restaurant_id';
  $handler->display->display_options['arguments']['restaurant_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['restaurant_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['restaurant_id']['title'] = '%1 Restaurant';
  $handler->display->display_options['arguments']['restaurant_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['restaurant_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['restaurant_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['restaurant_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['restaurant_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['restaurant_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['restaurant_id']['validate_options']['types'] = array(
    'restaurant' => 'restaurant',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['filters']['title']['operator'] = '!=';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'restaurant/%/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_restaurant_guides_view'] = array(
    t('Default'),
    t('Restaurant Guide Ranking'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('There is no data in this table.'),
    t('restaurantguideranking.guide_id -> taxonomy_term_data.tid'),
    t('restaurantguideranking.ranking_id -> ranking.ranking_id'),
    t('restaurantguideranking.restaurant_id -> node.nid'),
    t('Restaurant'),
    t('Guide'),
    t('Country'),
    t('France'),
    t('Food'),
    t('Bonus'),
    t('Ambiance'),
    t('Service'),
    t('Wine List'),
    t('Panorama'),
    t('Terrace'),
    t('Value'),
    t('Votes'),
    t('Link'),
    t('.'),
    t(','),
    t('All'),
    t('%1 Restaurant'),
    t('Page'),
  );
  $export['laliste_rr_restaurant_guides_view'] = $view;

  $view = new view();
  $view->name = 'laliste_rr_restaurants_country_fix_address_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_restaurants_country_fix_address_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'restaurant_id' => 'restaurant_id',
    'guide_id' => 'guide_id',
    'ranking_id' => 'ranking_id',
    'created' => 'created',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'restaurant_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'guide_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'ranking_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'updated' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['title']['label'] = 'Restaurant';
  /* Field: Content: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_thoroughfare']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_thoroughfare']['label'] = 'Address';
  $handler->display->display_options['fields']['field_address_thoroughfare']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_address_premise']['id'] = 'field_address_premise';
  $handler->display->display_options['fields']['field_address_premise']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_premise']['field'] = 'field_address_premise';
  $handler->display->display_options['fields']['field_address_premise']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_premise']['label'] = 'Address (suite)';
  $handler->display->display_options['fields']['field_address_premise']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Postal code */
  $handler->display->display_options['fields']['field_address_postal_code']['id'] = 'field_address_postal_code';
  $handler->display->display_options['fields']['field_address_postal_code']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_postal_code']['field'] = 'field_address_postal_code';
  $handler->display->display_options['fields']['field_address_postal_code']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_postal_code']['label'] = 'Postal code';
  $handler->display->display_options['fields']['field_address_postal_code']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = 'City';
  $handler->display->display_options['fields']['field_address_locality']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Address - Country */
  $handler->display->display_options['sorts']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['sorts']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['relationship'] = 'restaurant_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'restaurant_id';
  /* Contextual filter: Content: Address - Country */
  $handler->display->display_options['arguments']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['arguments']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['arguments']['field_address_country']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_address_country']['title'] = 'Restaurants in %1';
  $handler->display->display_options['arguments']['field_address_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_address_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_address_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_address_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_address_country']['limit'] = '0';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['filters']['title']['operator'] = '!=';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = '!=';
  $handler->display->display_options['filters']['title_1']['value'] = 'Home';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'country/correction/%/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_restaurants_country_fix_address_view'] = array(
    t('Default'),
    t('Restaurant Guide Ranking'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('There is no data in this table.'),
    t('Restaurant'),
    t('Address'),
    t('Address (suite)'),
    t('Postal code'),
    t('City'),
    t('Country'),
    t('France'),
    t('Phone'),
    t('Website'),
    t('All'),
    t('Restaurants in %1'),
    t('Page'),
  );
  $export['laliste_rr_restaurants_country_fix_address_view'] = $view;

  $view = new view();
  $view->name = 'laliste_rr_restaurants_country_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_restaurants_country_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'restaurant_id' => 'restaurant_id',
    'guide_id' => 'guide_id',
    'ranking_id' => 'ranking_id',
    'created' => 'created',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'restaurant_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'guide_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'ranking_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'updated' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Restaurantguideranking: Guide ID */
  $handler->display->display_options['relationships']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['relationships']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['guide_id']['field'] = 'guide_id';
  /* Relationship: Restaurantguideranking: Ranking ID */
  $handler->display->display_options['relationships']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['relationships']['ranking_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['ranking_id']['field'] = 'ranking_id';
  /* Relationship: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['relationships']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['restaurant_id']['field'] = 'restaurant_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['title']['label'] = 'Restaurant';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'guide_id';
  $handler->display->display_options['fields']['name']['label'] = 'Guide';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Ranking: Food form field */
  $handler->display->display_options['fields']['food']['id'] = 'food';
  $handler->display->display_options['fields']['food']['table'] = 'ranking';
  $handler->display->display_options['fields']['food']['field'] = 'food';
  $handler->display->display_options['fields']['food']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['food']['label'] = 'Food';
  /* Field: Ranking: Bonus form field */
  $handler->display->display_options['fields']['bonus']['id'] = 'bonus';
  $handler->display->display_options['fields']['bonus']['table'] = 'ranking';
  $handler->display->display_options['fields']['bonus']['field'] = 'bonus';
  $handler->display->display_options['fields']['bonus']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['bonus']['label'] = 'Bonus';
  /* Field: Ranking: Atmosphere form field */
  $handler->display->display_options['fields']['atmosphere']['id'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['table'] = 'ranking';
  $handler->display->display_options['fields']['atmosphere']['field'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['atmosphere']['label'] = 'Ambiance';
  /* Field: Ranking: Service form field */
  $handler->display->display_options['fields']['service']['id'] = 'service';
  $handler->display->display_options['fields']['service']['table'] = 'ranking';
  $handler->display->display_options['fields']['service']['field'] = 'service';
  $handler->display->display_options['fields']['service']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['service']['label'] = 'Service';
  /* Field: Ranking: Wine form field */
  $handler->display->display_options['fields']['wine']['id'] = 'wine';
  $handler->display->display_options['fields']['wine']['table'] = 'ranking';
  $handler->display->display_options['fields']['wine']['field'] = 'wine';
  $handler->display->display_options['fields']['wine']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['wine']['label'] = 'Wine List';
  /* Field: Ranking: Panorama form field */
  $handler->display->display_options['fields']['panorama']['id'] = 'panorama';
  $handler->display->display_options['fields']['panorama']['table'] = 'ranking';
  $handler->display->display_options['fields']['panorama']['field'] = 'panorama';
  $handler->display->display_options['fields']['panorama']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['panorama']['label'] = 'Panorama';
  /* Field: Ranking: Quiet form field */
  $handler->display->display_options['fields']['quiet']['id'] = 'quiet';
  $handler->display->display_options['fields']['quiet']['table'] = 'ranking';
  $handler->display->display_options['fields']['quiet']['field'] = 'quiet';
  $handler->display->display_options['fields']['quiet']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['quiet']['label'] = 'Terrace';
  /* Field: Ranking: Value form field */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ranking';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['value']['label'] = 'Value';
  /* Field: Ranking: Votes form field */
  $handler->display->display_options['fields']['votes']['id'] = 'votes';
  $handler->display->display_options['fields']['votes']['table'] = 'ranking';
  $handler->display->display_options['fields']['votes']['field'] = 'votes';
  $handler->display->display_options['fields']['votes']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['votes']['label'] = 'Votes';
  /* Field: Ranking: Link form field */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'ranking';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['link']['label'] = 'Link';
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  /* Field: Ranking: Ranking ID */
  $handler->display->display_options['fields']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['table'] = 'ranking';
  $handler->display->display_options['fields']['ranking_id']['field'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['label'] = '';
  $handler->display->display_options['fields']['ranking_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ranking_id']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Address - Country */
  $handler->display->display_options['sorts']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['sorts']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['relationship'] = 'restaurant_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'restaurant_id';
  /* Contextual filter: Content: Address - Country */
  $handler->display->display_options['arguments']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['arguments']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['arguments']['field_address_country']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_address_country']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_address_country']['title'] = 'Restaurants in %1';
  $handler->display->display_options['arguments']['field_address_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_address_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_address_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_address_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_address_country']['limit'] = '0';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['filters']['title']['operator'] = '!=';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'country/%/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_restaurants_country_view'] = array(
    t('Default'),
    t('Restaurant Guide Ranking'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('There is no data in this table.'),
    t('restaurantguideranking.guide_id -> taxonomy_term_data.tid'),
    t('restaurantguideranking.ranking_id -> ranking.ranking_id'),
    t('restaurantguideranking.restaurant_id -> node.nid'),
    t('Restaurant'),
    t('Guide'),
    t('Country'),
    t('France'),
    t('Food'),
    t('Bonus'),
    t('Ambiance'),
    t('Service'),
    t('Wine List'),
    t('Panorama'),
    t('Terrace'),
    t('Value'),
    t('Votes'),
    t('Link'),
    t('.'),
    t(','),
    t('All'),
    t('Restaurants in %1'),
    t('Page'),
  );
  $export['laliste_rr_restaurants_country_view'] = $view;

  $view = new view();
  $view->name = 'laliste_rr_restaurants_country_winners_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_restaurants_country_winners_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'LA LISTE';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'restaurant_id' => 'restaurant_id',
    'guide_id' => 'guide_id',
    'ranking_id' => 'ranking_id',
    'created' => 'created',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'restaurant_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'guide_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'ranking_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'updated' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['relationships']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['restaurant_id']['field'] = 'restaurant_id';
  /* Relationship: Restaurant stats: Restaurant id */
  $handler->display->display_options['relationships']['restaurant_id_1']['id'] = 'restaurant_id_1';
  $handler->display->display_options['relationships']['restaurant_id_1']['table'] = 'restaurant_stats';
  $handler->display->display_options['relationships']['restaurant_id_1']['field'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id_1']['relationship'] = 'restaurant_id';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Rank';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['title']['label'] = 'Restaurant';
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country_1']['id'] = 'field_address_country_1';
  $handler->display->display_options['fields']['field_address_country_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country_1']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country_1']['relationship'] = 'restaurant_id_1';
  $handler->display->display_options['fields']['field_address_country_1']['label'] = '';
  $handler->display->display_options['fields']['field_address_country_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_country_1']['display_name'] = 0;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['path'] = 'country/[field_address_country_1]/laliste/view';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Restaurant stats: Score laliste */
  $handler->display->display_options['fields']['score_laliste']['id'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_laliste']['field'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['relationship'] = 'restaurant_id_1';
  $handler->display->display_options['fields']['score_laliste']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_laliste']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['score_laliste']['precision'] = '3';
  /* Field: Restaurant stats: Score pro */
  $handler->display->display_options['fields']['score_pro']['id'] = 'score_pro';
  $handler->display->display_options['fields']['score_pro']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_pro']['field'] = 'score_pro';
  $handler->display->display_options['fields']['score_pro']['relationship'] = 'restaurant_id_1';
  $handler->display->display_options['fields']['score_pro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_pro']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['score_pro']['precision'] = '3';
  /* Field: Restaurant stats: Score pub */
  $handler->display->display_options['fields']['score_pub']['id'] = 'score_pub';
  $handler->display->display_options['fields']['score_pub']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_pub']['field'] = 'score_pub';
  $handler->display->display_options['fields']['score_pub']['relationship'] = 'restaurant_id_1';
  $handler->display->display_options['fields']['score_pub']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_pub']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['score_pub']['precision'] = '3';
  /* Sort criterion: Restaurant stats: Score laliste */
  $handler->display->display_options['sorts']['score_laliste']['id'] = 'score_laliste';
  $handler->display->display_options['sorts']['score_laliste']['table'] = 'restaurant_stats';
  $handler->display->display_options['sorts']['score_laliste']['field'] = 'score_laliste';
  $handler->display->display_options['sorts']['score_laliste']['relationship'] = 'restaurant_id_1';
  $handler->display->display_options['sorts']['score_laliste']['order'] = 'DESC';
  /* Contextual filter: Content: Address - Country */
  $handler->display->display_options['arguments']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['arguments']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['arguments']['field_address_country']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_address_country']['title'] = 'Restaurants in %1';
  $handler->display->display_options['arguments']['field_address_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_address_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_address_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_address_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_address_country']['limit'] = '0';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['filters']['title']['operator'] = '!=';
  /* Filter criterion: Restaurant stats: Popularity */
  $handler->display->display_options['filters']['popularity']['id'] = 'popularity';
  $handler->display->display_options['filters']['popularity']['table'] = 'restaurant_stats';
  $handler->display->display_options['filters']['popularity']['field'] = 'popularity';
  $handler->display->display_options['filters']['popularity']['relationship'] = 'restaurant_id_1';
  $handler->display->display_options['filters']['popularity']['operator'] = '>=';
  $handler->display->display_options['filters']['popularity']['value']['value'] = '10';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'country/%/laliste/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_restaurants_country_winners_view'] = array(
    t('Default'),
    t('LA LISTE'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('There is no data in this table.'),
    t('restaurantguideranking.restaurant_id -> node.nid'),
    t('restaurant_stats.restaurant_id -> node.nid'),
    t('Rank'),
    t('Restaurant'),
    t('Country'),
    t('France'),
    t('Score laliste'),
    t('.'),
    t(','),
    t('Score pro'),
    t('Score pub'),
    t('All'),
    t('Restaurants in %1'),
    t('Page'),
  );
  $export['laliste_rr_restaurants_country_winners_view'] = $view;

  $view = new view();
  $view->name = 'laliste_rr_restaurants_guide_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_rr_restaurants_guide_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'restaurant_id' => 'restaurant_id',
    'guide_id' => 'guide_id',
    'ranking_id' => 'ranking_id',
    'created' => 'created',
    'updated' => 'updated',
  );
  $handler->display->display_options['style_options']['default'] = -1;
  $handler->display->display_options['style_options']['info'] = array(
    'restaurant_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'guide_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'ranking_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'updated' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Restaurantguideranking: Guide ID */
  $handler->display->display_options['relationships']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['relationships']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['guide_id']['field'] = 'guide_id';
  /* Relationship: Restaurantguideranking: Ranking ID */
  $handler->display->display_options['relationships']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['relationships']['ranking_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['ranking_id']['field'] = 'ranking_id';
  /* Relationship: Restaurantguideranking: Restaurant ID */
  $handler->display->display_options['relationships']['restaurant_id']['id'] = 'restaurant_id';
  $handler->display->display_options['relationships']['restaurant_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['relationships']['restaurant_id']['field'] = 'restaurant_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['title']['label'] = 'Restaurant';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'guide_id';
  $handler->display->display_options['fields']['name']['label'] = 'Guide';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['relationship'] = 'restaurant_id';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Ranking: Food form field */
  $handler->display->display_options['fields']['food']['id'] = 'food';
  $handler->display->display_options['fields']['food']['table'] = 'ranking';
  $handler->display->display_options['fields']['food']['field'] = 'food';
  $handler->display->display_options['fields']['food']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['food']['label'] = 'Food';
  /* Field: Ranking: Bonus form field */
  $handler->display->display_options['fields']['bonus']['id'] = 'bonus';
  $handler->display->display_options['fields']['bonus']['table'] = 'ranking';
  $handler->display->display_options['fields']['bonus']['field'] = 'bonus';
  $handler->display->display_options['fields']['bonus']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['bonus']['label'] = 'Bonus';
  /* Field: Ranking: Atmosphere form field */
  $handler->display->display_options['fields']['atmosphere']['id'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['table'] = 'ranking';
  $handler->display->display_options['fields']['atmosphere']['field'] = 'atmosphere';
  $handler->display->display_options['fields']['atmosphere']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['atmosphere']['label'] = 'Ambiance';
  /* Field: Ranking: Service form field */
  $handler->display->display_options['fields']['service']['id'] = 'service';
  $handler->display->display_options['fields']['service']['table'] = 'ranking';
  $handler->display->display_options['fields']['service']['field'] = 'service';
  $handler->display->display_options['fields']['service']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['service']['label'] = 'Service';
  /* Field: Ranking: Wine form field */
  $handler->display->display_options['fields']['wine']['id'] = 'wine';
  $handler->display->display_options['fields']['wine']['table'] = 'ranking';
  $handler->display->display_options['fields']['wine']['field'] = 'wine';
  $handler->display->display_options['fields']['wine']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['wine']['label'] = 'Wine List';
  /* Field: Ranking: Panorama form field */
  $handler->display->display_options['fields']['panorama']['id'] = 'panorama';
  $handler->display->display_options['fields']['panorama']['table'] = 'ranking';
  $handler->display->display_options['fields']['panorama']['field'] = 'panorama';
  $handler->display->display_options['fields']['panorama']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['panorama']['label'] = 'Panorama';
  /* Field: Ranking: Quiet form field */
  $handler->display->display_options['fields']['quiet']['id'] = 'quiet';
  $handler->display->display_options['fields']['quiet']['table'] = 'ranking';
  $handler->display->display_options['fields']['quiet']['field'] = 'quiet';
  $handler->display->display_options['fields']['quiet']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['quiet']['label'] = 'Terrace';
  /* Field: Ranking: Value form field */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ranking';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['value']['label'] = 'Value';
  /* Field: Ranking: Votes form field */
  $handler->display->display_options['fields']['votes']['id'] = 'votes';
  $handler->display->display_options['fields']['votes']['table'] = 'ranking';
  $handler->display->display_options['fields']['votes']['field'] = 'votes';
  $handler->display->display_options['fields']['votes']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['votes']['label'] = 'Votes';
  /* Field: Ranking: Link form field */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'ranking';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['link']['label'] = 'Link';
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  /* Field: Ranking: Ranking ID */
  $handler->display->display_options['fields']['ranking_id']['id'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['table'] = 'ranking';
  $handler->display->display_options['fields']['ranking_id']['field'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['relationship'] = 'ranking_id';
  $handler->display->display_options['fields']['ranking_id']['label'] = '';
  $handler->display->display_options['fields']['ranking_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ranking_id']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Address - Country */
  $handler->display->display_options['sorts']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['sorts']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['sorts']['field_address_country']['relationship'] = 'restaurant_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'restaurant_id';
  /* Contextual filter: Restaurantguideranking: Guide ID */
  $handler->display->display_options['arguments']['guide_id']['id'] = 'guide_id';
  $handler->display->display_options['arguments']['guide_id']['table'] = 'restaurantguideranking';
  $handler->display->display_options['arguments']['guide_id']['field'] = 'guide_id';
  $handler->display->display_options['arguments']['guide_id']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['guide_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['guide_id']['title'] = '%1 Guide Restaurants';
  $handler->display->display_options['arguments']['guide_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['guide_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['guide_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['guide_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['guide_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['guide_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['guide_id']['validate_options']['vocabularies'] = array(
    'laliste_taxonomy_guides' => 'laliste_taxonomy_guides',
  );
  $handler->display->display_options['arguments']['guide_id']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['guide_id']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'restaurant_id';
  $handler->display->display_options['filters']['title']['operator'] = '!=';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'restaurants/%/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['laliste_rr_restaurants_guide_view'] = array(
    t('Default'),
    t('Restaurant Guide Ranking'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('There is no data in this table.'),
    t('restaurantguideranking.guide_id -> taxonomy_term_data.tid'),
    t('restaurantguideranking.ranking_id -> ranking.ranking_id'),
    t('restaurantguideranking.restaurant_id -> node.nid'),
    t('Restaurant'),
    t('Guide'),
    t('Country'),
    t('France'),
    t('Food'),
    t('Bonus'),
    t('Ambiance'),
    t('Service'),
    t('Wine List'),
    t('Panorama'),
    t('Terrace'),
    t('Value'),
    t('Votes'),
    t('Link'),
    t('.'),
    t(','),
    t('All'),
    t('%1 Guide Restaurants'),
    t('Page'),
  );
  $export['laliste_rr_restaurants_guide_view'] = $view;

  return $export;
}
