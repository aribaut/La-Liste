<?php
/**
 * @file
 * laliste_rr_ct.data_default.inc
 */

/**
 * Implements hook_data_default().
 */
function laliste_rr_ct_data_default() {
  $export = array();

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Ranking';
  $data_table->name = 'ranking';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'ranking_id' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'description' => '',
      ),
      'score' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'trust' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'popularity' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'food' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'bonus' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'wine' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'service' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'atmosphere' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'panorama' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'quiet' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'value' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'votes' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'link' => array(
        'type' => 'varchar',
        'size' => 'normal',
        'length' => '255',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'ranking',
    'primary key' => array(
      0 => 'ranking_id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'ranking_id' => array(
        'label' => 'Ranking ID',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'food' => array(
        'label' => 'Food',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'wine' => array(
        'label' => 'Wine',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'service' => array(
        'label' => 'Service',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'atmosphere' => array(
        'label' => 'Atmosphere',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'value' => array(
        'label' => 'Value',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'votes' => array(
        'label' => 'Votes',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'bonus_id' => array(
        'label' => 'Bonus',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'created' => array(
        'label' => 'Created',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
      ),
      'updated' => array(
        'label' => 'Updated',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
      ),
      'bonus' => array(
        'label' => '',
      ),
      'panorama' => array(
        'label' => '',
      ),
      'quiet' => array(
        'label' => '',
      ),
      'link' => array(
        'label' => 'Link',
      ),
    ),
    'join' => array(
      'restaurantguideranking' => array(
        'left_field' => 'ranking_id',
        'field' => 'ranking_id',
        'inner_join' => '0',
      ),
    ),
  );
  $export['ranking'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Restaurant stats';
  $data_table->name = 'restaurant_stats';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'restaurant_id' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'description' => '',
      ),
      'rank' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'score_laliste' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'score_pro' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'score_pub' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'popularity' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'views' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'restaurant_stats',
    'primary key' => array(
      0 => 'restaurant_id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'restaurant_id' => array(),
      'score_laliste' => array(),
      'score_pro' => array(),
      'score_pub' => array(),
      'popularity' => array(),
      'views' => array(),
      'created' => array(),
      'updated' => array(),
    ),
    'join' => array(
      'node' => array(
        'left_field' => 'nid',
        'field' => 'restaurant_id',
        'inner_join' => '0',
      ),
    ),
  );
  $export['restaurant_stats'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Restaurantguideranking';
  $data_table->name = 'restaurantguideranking';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'restaurant_id' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'description' => '',
      ),
      'guide_id' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'description' => '',
      ),
      'ranking_id' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'restaurantguideranking',
    'primary key' => array(
      0 => 'restaurant_id',
      1 => 'guide_id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'restaurant_id' => array(
        'label' => 'Restaurant ID',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'guide_id' => array(
        'label' => 'Guide ID',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'ranking_id' => array(
        'label' => 'Ranking ID',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'created' => array(
        'label' => 'Created',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
      ),
      'updated' => array(
        'label' => 'Updated',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
      ),
    ),
    'join' => array(
      'node' => array(
        'left_field' => 'nid',
        'field' => 'restaurant_id',
        'inner_join' => '0',
      ),
      'taxonomy_term_data' => array(
        'left_field' => 'tid',
        'field' => 'guide_id',
        'inner_join' => '0',
      ),
      'ranking' => array(
        'left_field' => 'ranking_id',
        'field' => 'ranking_id',
        'inner_join' => '0',
      ),
    ),
  );
  $export['restaurantguideranking'] = $data_table;

  return $export;
}
