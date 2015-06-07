<?php

/**
 * Implements hook_views_data_alter().
 *
 * @param $data
 *   Information about Views' tables and fields.
 */
function laliste_rr_ct_views_data_alter(&$data) {
  // Add the Title form field to the view
  $data['node']['title_edit'] = array(
      'field' => array(
          'title' => t('Title form field'),
          'help' => t('Edit the node title'),
          'handler' => 'laliste_rr_ct_field_handler_title_edit',
      ),
  );
  // Add the Food form field to the view
  $data['ranking']['food'] = array(
      'field' => array(
          'title' => t('Food form field'),
          'help' => t('Edit the node food'),
          'handler' => 'laliste_rr_ct_field_handler_food_edit',
          'relationship' => array(
              'base' => 'restaurantguideranking', // Table we're joining to.
              'base field' => 'ranking_id', // Field on the joined table.
              'field' => 'food', // Real field name on the 'foo' table.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for relationship'),
              'title' => t('Title seen when adding relationship'),
              'help' => t('More information about relationship.'),
          ),
      ),
  );
  // Add the Atmosphere form field to the view
  $data['ranking']['atmosphere'] = array(
      'field' => array(
          'title' => t('Atmosphere form field'),
          'help' => t('Edit the node atmosphere'),
          'handler' => 'laliste_rr_ct_field_handler_atmosphere_edit',
          'relationship' => array(
              'base' => 'restaurantguideranking', // Table we're joining to.
              'base field' => 'ranking_id', // Field on the joined table.
              'field' => 'atmosphere', // Real field name on the 'foo' table.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for relationship'),
              'title' => t('Title seen when adding relationship'),
              'help' => t('More information about relationship.'),
          ),
      ),
  );
  // Add the Service form field to the view
  $data['ranking']['service'] = array(
      'field' => array(
          'title' => t('Service form field'),
          'help' => t('Edit the node service'),
          'handler' => 'laliste_rr_ct_field_handler_service_edit',
          'relationship' => array(
              'base' => 'restaurantguideranking', // Table we're joining to.
              'base field' => 'ranking_id', // Field on the joined table.
              'field' => 'service', // Real field name on the 'foo' table.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for relationship'),
              'title' => t('Title seen when adding relationship'),
              'help' => t('More information about relationship.'),
          ),
      ),
  );
  // Add the Service form field to the view
  $data['ranking']['wine'] = array(
      'field' => array(
          'title' => t('Wine form field'),
          'help' => t('Edit the restaurant wine ranking'),
          'handler' => 'laliste_rr_ct_field_handler_wine_edit',
          'relationship' => array(
              'base' => 'restaurantguideranking', // Table we're joining to.
              'base field' => 'ranking_id', // Field on the joined table.
              'field' => 'wine', // Real field name on the 'foo' table.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for relationship'),
              'title' => t('Title seen when adding relationship'),
              'help' => t('More information about relationship.'),
          ),
      ),
  );
  // Add the Service form field to the view
  $data['ranking']['value'] = array(
      'field' => array(
          'title' => t('Value form field'),
          'help' => t('Edit the restaurant value ranking'),
          'handler' => 'laliste_rr_ct_field_handler_value_edit',
          'relationship' => array(
              'base' => 'restaurantguideranking', // Table we're joining to.
              'base field' => 'ranking_id', // Field on the joined table.
              'field' => 'value', // Real field name on the 'foo' table.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for relationship'),
              'title' => t('Title seen when adding relationship'),
              'help' => t('More information about relationship.'),
          ),
      ),
  );
  // Add the Service form field to the view
  $data['ranking']['votes'] = array(
      'field' => array(
          'title' => t('Votes form field'),
          'help' => t('Edit the restaurant votes ranking'),
          'handler' => 'laliste_rr_ct_field_handler_votes_edit',
          'relationship' => array(
              'base' => 'restaurantguideranking', // Table we're joining to.
              'base field' => 'ranking_id', // Field on the joined table.
              'field' => 'votes', // Real field name on the 'foo' table.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for relationship'),
              'title' => t('Title seen when adding relationship'),
              'help' => t('More information about relationship.'),
          ),
      ),
  );

}

/**
 * Views handling of custom created SQL tables
 */
/*
function laliste_rr_ct_views_data() {
  $data = array();

  // First, the entry $data['example_table']['table'] describes properties of
  // the actual table – not its content.

  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data ['ranking']['table']['group'] = t('LaListe Base Table');

  // Define this as a base table – a table that can be described in itself by
  // views (and not just being brought in as a relationship). In reality this
  // is not very useful for this table, as it isn't really a distinct object of
  // its own, but it makes a good example.
  $data ['ranking']['table']['base'] = array(
      'field' => 'ranking_id', // This is the identifier field for the view.
      'title' => t('Ranking table'),
      'help' => t('Ranking table contains restaurants ranked and can be related to restaurant nodes.'),
      'weight' => -10,
  );

  // Describes the ranking table
  $data['ranking'] = array(
      'table' => array(
          'base' => array(
              'field' => 'ranking_id',
              'title' => 'Ranking',
              'help' => 'TODO: please describe the items in this table!',
          ),
          'group' => 'Ranking',
      ),
      'ranking_id' => array(
          'title' => 'Ranking Id',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
      ),
      'food' => array(
          'title' => 'Food',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => FALSE,
          ),
      ),
      'wine' => array(
          'title' => 'Wine',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => FALSE,
          ),
      ),
      'service' => array(
          'title' => 'Service',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => FALSE,
          ),
      ),
      'atmosphere' => array(
          'title' => 'Atmosphere',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => FALSE,
          ),
      ),
      'value' => array(
          'title' => 'Value',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => FALSE,
          ),
      ),
      'votes' => array(
          'title' => 'Votes',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => FALSE,
          ),
      ),
      'bonus_id' => array(
          'title' => 'Bonus Id',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
      ),
      'created' => array(
          'title' => 'Created',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_date',
              'click sortable' => TRUE,
          ),
          'sort' => array(
              'handler' => 'views_handler_sort_date',
          ),
          'filter' => array(
              'handler' => 'views_handler_filter_date',
          ),
      ),
      'updated' => array(
          'title' => 'Updated',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
      ),
  );

  // Describes the main lookup table

  // First, the entry $data['example_table']['table'] describes properties of
  // the actual table – not its content.

  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data ['restaurantguideranking']['table']['group'] = t('LaListe Base Table');

  // Define this as a base table – a table that can be described in itself by
  // views (and not just being brought in as a relationship). In reality this
  // is not very useful for this table, as it isn't really a distinct object of
  // its own, but it makes a good example.
  $data ['restaurantguideranking']['table']['base'] = array(
      'field' => 'restaurant_id', // This is the identifier field for the view.
      'title' => t('Restaurant Guide Lookup Table'),
      'help' => t('Example table contains example content and can be related to nodes.'),
      'weight' => -10,
  );

  // This table references the {node} table. The declaration below creates an
  // 'implicit' relationship to the node table, so that when 'node' is the base
  // table, the fields are automatically available.
  $data ['restaurantguideranking']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
      'taxonomy_term_data' => array(
          'left_field' => 'tid',
          'field' => 'guide_id',
      ),
      'node' => array(
          'left_field' => 'nid',
          'field' => 'restaurant_id',
      ),
      'ranking' => array(
          'left_field' => 'ranking_id',
          'field' => 'ranking_id',
      ),
  );

  $data['restaurantguideranking'] = array(
      'table' => array(
          'base' => array(
              'field' => 'restaurant_id',
              'title' => 'Restaurantguideranking',
              'help' => 'TODO: please describe the items in this table!',
          ),
          'group' => 'Restaurantguideranking',
      ),
      'restaurant_id' => array(
          'title' => 'Restaurant Id',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
          'relationship' => array(
              'base' => 'node', // The name of the table to join with.
              'base field' => 'nid', // The name of the field on the joined table.
            // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for the relationship'),
              'title' => t('Title shown when adding the relationship'),
              'help' => t('More information on this relationship'),
          ),
      ),
      'guide_id' => array(
          'title' => 'Guide Id',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
          'relationship' => array(
              'base' => 'taxonomy_term_data', // The name of the table to join with.
              'base field' => 'tid', // The name of the field on the joined table.
              // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for the relationship'),
              'title' => t('Title shown when adding the relationship'),
              'help' => t('More information on this relationship'),
          ),
      ),
      'ranking_id' => array(
          'title' => 'Ranking Id',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
          'relationship' => array(
              'base' => 'ranking', // The name of the table to join with.
              'base field' => 'ranking_id', // The name of the field on the joined table.
            // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
              'handler' => 'views_handler_relationship',
              'label' => t('Default label for the relationship'),
              'title' => t('Title shown when adding the relationship'),
              'help' => t('More information on this relationship'),
          ),
      ),
      'created' => array(
          'title' => 'Created',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_date',
              'click sortable' => TRUE,
          ),
          'sort' => array(
              'handler' => 'views_handler_sort_date',
          ),
          'filter' => array(
              'handler' => 'views_handler_filter_date',
          ),
      ),
      'updated' => array(
          'title' => 'Updated',
          'help' => 'TODO: please describe this field!',
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
          ),
      ),
  );


  return $data;
}
*/