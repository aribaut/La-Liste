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
  $view->name = 'homepage_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Slideshow image */
  $handler->display->display_options['fields']['field_slideshow_image']['id'] = 'field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['table'] = 'field_data_field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['field'] = 'field_slideshow_image';
  $handler->display->display_options['fields']['field_slideshow_image']['label'] = '';
  $handler->display->display_options['fields']['field_slideshow_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slideshow_image']['settings'] = array(
    'image_style' => 'full-width_slider_image',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_featured_image' => 'homepage_featured_image',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['homepage_slider'] = array(
    t('Master'),
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
    t('Block'),
  );
  $export['homepage_slider'] = $view;

  $view = new view();
  $view->name = 'la_liste_country_map';
  $view->description = 'Provides a specific restaurant map';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'LA LISTE country map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_restaurant_position';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'score_laliste';
  $handler->display->display_options['style_options']['map'] = 'leaflet-mapbox';
  $handler->display->display_options['style_options']['height'] = '545';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '2';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '2';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '5';
  $handler->display->display_options['style_options']['zoom']['scrollWheelZoom'] = 0;
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_restaurant_position']['id'] = 'field_restaurant_position';
  $handler->display->display_options['fields']['field_restaurant_position']['table'] = 'field_data_field_restaurant_position';
  $handler->display->display_options['fields']['field_restaurant_position']['field'] = 'field_restaurant_position';
  $handler->display->display_options['fields']['field_restaurant_position']['label'] = '';
  $handler->display->display_options['fields']['field_restaurant_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_restaurant_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_restaurant_position']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_restaurant_position']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_restaurant_position']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = '';
  $handler->display->display_options['fields']['field_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Restaurant stats: Rank */
  $handler->display->display_options['fields']['rank']['id'] = 'rank';
  $handler->display->display_options['fields']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['rank']['field'] = 'rank';
  $handler->display->display_options['fields']['rank']['label'] = '';
  $handler->display->display_options['fields']['rank']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rank']['element_label_colon'] = FALSE;
  /* Field: Restaurant stats: Score laliste */
  $handler->display->display_options['fields']['score_laliste']['id'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_laliste']['field'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['label'] = '';
  $handler->display->display_options['fields']['score_laliste']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['score_laliste']['alter']['text'] = ' is in the [rank]th position';
  $handler->display->display_options['fields']['score_laliste']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_laliste']['precision'] = '0';
  /* Contextual filter: Content: Address - Country */
  $handler->display->display_options['arguments']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['arguments']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_address_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_address_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_address_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_address_country']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'restaurant' => 'restaurant',
  );
  /* Filter criterion: Content: Position (field_restaurant_position:lat) */
  $handler->display->display_options['filters']['field_restaurant_position_lat']['id'] = 'field_restaurant_position_lat';
  $handler->display->display_options['filters']['field_restaurant_position_lat']['table'] = 'field_data_field_restaurant_position';
  $handler->display->display_options['filters']['field_restaurant_position_lat']['field'] = 'field_restaurant_position_lat';
  $handler->display->display_options['filters']['field_restaurant_position_lat']['operator'] = 'not empty';
  /* Filter criterion: Restaurant stats: Rank */
  $handler->display->display_options['filters']['rank']['id'] = 'rank';
  $handler->display->display_options['filters']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['filters']['rank']['field'] = 'rank';
  $handler->display->display_options['filters']['rank']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['la_liste_country_map'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t(','),
    t(' is in the [rank]th position'),
    t('All'),
    t('Block'),
  );
  $export['la_liste_country_map'] = $view;

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
  $handler->display->display_options['title'] = 'Les 1000 tables d\'exception';
  $handler->display->display_options['css_class'] = 'laliste-winners-home';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all restaurants in La Liste';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'laliste-winners-result';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'la_liste_country_map:block';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country_1']['id'] = 'field_address_country_1';
  $handler->display->display_options['fields']['field_address_country_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country_1']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country_1']['label'] = '';
  $handler->display->display_options['fields']['field_address_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_country_1']['display_name'] = 0;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['path'] = 'country/[field_address_country_1]/laliste/view';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]     <span class="field-localization">   - [field_address_locality]</span>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Restaurant stats: Score laliste */
  $handler->display->display_options['fields']['score_laliste']['id'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_laliste']['field'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_laliste']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['score_laliste']['precision'] = '3';
  /* Field: Restaurant stats: Rank */
  $handler->display->display_options['fields']['rank']['id'] = 'rank';
  $handler->display->display_options['fields']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['rank']['field'] = 'rank';
  $handler->display->display_options['fields']['rank']['element_label_colon'] = FALSE;
  /* Sort criterion: Restaurant stats: Rank */
  $handler->display->display_options['sorts']['rank']['id'] = 'rank';
  $handler->display->display_options['sorts']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['sorts']['rank']['field'] = 'rank';
  /* Contextual filter: Content: Address - Country */
  $handler->display->display_options['arguments']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['arguments']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['arguments']['field_address_country']['exception']['value'] = 'world';
  $handler->display->display_options['arguments']['field_address_country']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_address_country']['title'] = '%1 restaurants';
  $handler->display->display_options['arguments']['field_address_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_address_country']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['field_address_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_address_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_address_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_address_country']['limit'] = '0';
  /* Filter criterion: Restaurant stats: Rank */
  $handler->display->display_options['filters']['rank']['id'] = 'rank';
  $handler->display->display_options['filters']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['filters']['rank']['field'] = 'rank';
  $handler->display->display_options['filters']['rank']['operator'] = 'between';
  $handler->display->display_options['filters']['rank']['value']['min'] = '1';
  $handler->display->display_options['filters']['rank']['value']['max'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all restaurants in La Liste';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Restaurant stats: Rank */
  $handler->display->display_options['filters']['rank']['id'] = 'rank';
  $handler->display->display_options['filters']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['filters']['rank']['field'] = 'rank';
  $handler->display->display_options['filters']['rank']['operator'] = 'between';
  $handler->display->display_options['filters']['rank']['value']['min'] = '1';
  $handler->display->display_options['filters']['rank']['value']['max'] = '1000';
  $handler->display->display_options['path'] = 'country/%/laliste/view';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Restaurant Guide Ranking';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all La Liste';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Restaurant stats: Rank */
  $handler->display->display_options['filters']['rank']['id'] = 'rank';
  $handler->display->display_options['filters']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['filters']['rank']['field'] = 'rank';
  $handler->display->display_options['filters']['rank']['operator'] = 'between';
  $handler->display->display_options['filters']['rank']['value']['min'] = '1';
  $handler->display->display_options['filters']['rank']['value']['max'] = '1000';
  $translatables['laliste_rr_restaurants_country_winners_view'] = array(
    t('Default'),
    t('Les 1000 tables d\'exception'),
    t('See all restaurants in La Liste'),
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
    t('There is no data in this table.'),
    t('Country'),
    t('France'),
    t('[title]     <span class="field-localization">   - [field_address_locality]</span>'),
    t('Score laliste'),
    t('.'),
    t(','),
    t('Rank'),
    t('All'),
    t('%1 restaurants'),
    t('Page'),
    t('Block'),
    t('See all La Liste'),
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

  $view = new view();
  $view->name = 'restaurant_map';
  $view->description = 'Provides a specific restaurant map';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Restaurant node map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_restaurant_position';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'score_laliste';
  $handler->display->display_options['style_options']['map'] = 'mapbox-warden';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '16';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '10';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['zoom']['scrollWheelZoom'] = 0;
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_restaurant_position']['id'] = 'field_restaurant_position';
  $handler->display->display_options['fields']['field_restaurant_position']['table'] = 'field_data_field_restaurant_position';
  $handler->display->display_options['fields']['field_restaurant_position']['field'] = 'field_restaurant_position';
  $handler->display->display_options['fields']['field_restaurant_position']['label'] = '';
  $handler->display->display_options['fields']['field_restaurant_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_restaurant_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_restaurant_position']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_restaurant_position']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_restaurant_position']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Restaurant stats: Rank */
  $handler->display->display_options['fields']['rank']['id'] = 'rank';
  $handler->display->display_options['fields']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['rank']['field'] = 'rank';
  $handler->display->display_options['fields']['rank']['label'] = '';
  $handler->display->display_options['fields']['rank']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rank']['element_label_colon'] = FALSE;
  /* Field: Restaurant stats: Score laliste */
  $handler->display->display_options['fields']['score_laliste']['id'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_laliste']['field'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['label'] = '';
  $handler->display->display_options['fields']['score_laliste']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['score_laliste']['alter']['text'] = ' is ranked [rank] with a score of [score_laliste] points';
  $handler->display->display_options['fields']['score_laliste']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_laliste']['precision'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'restaurant' => 'restaurant',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'restaurant' => 'restaurant',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['restaurant_map'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t(','),
    t(' is ranked [rank] with a score of [score_laliste] points'),
    t('All'),
    t('Block'),
  );
  $export['restaurant_map'] = $view;

  return $export;
}
