<?php
/**
 * @file
 * laliste_liste_ct.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function laliste_liste_ct_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'laliste_liste_restaurants_view';
  $view->description = 'Default view for data table Restaurant Guide Ranking';
  $view->tag = 'data table';
  $view->base_table = 'node';
  $view->human_name = 'laliste_liste_restaurants_view';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['css_class'] = 'laliste-winners-home';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all restaurants in La Liste';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'laliste-winners-result';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'There is no data in this table.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_liste_restaurants_target_id']['id'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['relationships']['field_liste_restaurants_target_id']['table'] = 'field_data_field_liste_restaurants';
  $handler->display->display_options['relationships']['field_liste_restaurants_target_id']['field'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['relationships']['field_liste_restaurants_target_id']['label'] = 'ref from field_liste_restaurants';
  /* Champ: Contenu: Address - Country */
  $handler->display->display_options['fields']['field_address_country_1']['id'] = 'field_address_country_1';
  $handler->display->display_options['fields']['field_address_country_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country_1']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country_1']['relationship'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['fields']['field_address_country_1']['label'] = '';
  $handler->display->display_options['fields']['field_address_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_country_1']['display_name'] = 0;
  /* Champ: Contenu: Address - Country */
  $handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address_country']['relationship'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_address_country']['alter']['path'] = 'country/[field_address_country_1]/laliste/view';
  $handler->display->display_options['fields']['field_address_country']['empty'] = 'France';
  $handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
  /* Champ: Contenu: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_locality']['relationship'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['fields']['field_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_address_locality']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_locality']['alter']['text'] = '<span class="field-localization">   - [field_address_locality]</span>';
  $handler->display->display_options['fields']['field_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_locality']['element_default_classes'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]     [field_address_locality]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Restaurant stats: Score laliste */
  $handler->display->display_options['fields']['score_laliste']['id'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['table'] = 'restaurant_stats';
  $handler->display->display_options['fields']['score_laliste']['field'] = 'score_laliste';
  $handler->display->display_options['fields']['score_laliste']['relationship'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['fields']['score_laliste']['exclude'] = TRUE;
  $handler->display->display_options['fields']['score_laliste']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['score_laliste']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['score_laliste']['precision'] = '3';
  /* Champ: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Rank';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Contextual filter: Contenu: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'liste' => 'liste',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  /* Filter criterion: Restaurant stats: Rank */
  $handler->display->display_options['filters']['rank']['id'] = 'rank';
  $handler->display->display_options['filters']['rank']['table'] = 'restaurant_stats';
  $handler->display->display_options['filters']['rank']['field'] = 'rank';
  $handler->display->display_options['filters']['rank']['operator'] = 'between';
  $handler->display->display_options['filters']['rank']['value']['min'] = '1';
  $handler->display->display_options['filters']['rank']['value']['max'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Consulter toute La Liste';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Contenu: Address (field_address:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'field_liste_restaurants_target_id';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $translatables['laliste_liste_restaurants_view'] = array(
    t('Default'),
    t('See all restaurants in La Liste'),
    t('Apply'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('There is no data in this table.'),
    t('ref from field_liste_restaurants'),
    t('Country'),
    t('France'),
    t('<span class="field-localization">   - [field_address_locality]</span>'),
    t('[title]     [field_address_locality]'),
    t('Score laliste'),
    t('.'),
    t(','),
    t('Rank'),
    t('Tout'),
    t('Block'),
    t('Consulter toute La Liste'),
  );
  $export['laliste_liste_restaurants_view'] = $view;

  return $export;
}
