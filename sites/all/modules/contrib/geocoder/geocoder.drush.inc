<?php

/**
 * @file
 * File to define drush hooks for geocoder.
 */

/**
 * Implements hook_drush_command().
 */
function geocoder_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['geocoder-backfill'] = array(
    'description' => "Geocodes all entities that have a geocoder widget but no geodata.",
    'options' => array(
      'force' => 'Force the geocode to run, even if there is already geodata',
      'limit' => array(
        'description' => 'Limit the number of entities to geocode at one time, per bundle',
        'example-value' => 'LIMIT',
        'value' => 'required',
      ),
      'only-entity' => array(
        'description' => 'Limit geocoding to a specific entity type (node, user, etc.).',
        'example-value' => 'node',
      ),
      'only-bundle' => array(
        'description' => 'Limit geocoding to a single bundle type. Must be used in conjunction with the `only-entity` flag. (ex: node type, when node is the entity type).',
        'example-value' => 'story',
      ),
      'idlist' => array(
        'description' => 'Limit geocoding to a comma delimited list of ids.',
        'example-value' => '123,456,789',
      ),
      'min-id' => array(
        'description' => 'Limit geocoding to entity ids greater than or equal to this value.',
        'example-value' => '100',
      ),
      'max-id' => array(
        'description' => 'Limit geocoding to entity ids less than or equal to this value.',
        'example-value' => '100000',
      ),
    ),
  );

  return $items;
}

/**
 * Drush command callback.
 */
function drush_geocoder_backfill() {
  $force_reload = drush_get_option('force');
  $all_entity_info = entity_get_info();
  $limit = drush_get_option('limit', 0);
  $only_entity_type = drush_get_option('only-entity');
  $only_bundle_type = drush_get_option('only-bundle');
  $idlist = drush_get_option('idlist') ? explode(',', drush_get_option('idlist')) : array();
  $min_id = drush_get_option('min-id');
  $max_id = drush_get_option('max-id');
  if ($only_bundle_type && !$only_entity_type) {
    drush_set_error('geocoder-backfill', 'The `only-entity` flag must be specified if the `only-bundle` is specified.');
  }
  $current_limit = $limit;

  foreach ($all_entity_info as $entity_type => $entity_info) {
    // If the request was for a single entity type, make sure the current type matches.
    if (!isset($only_entity_type) || (isset($only_entity_type) && $entity_type == $only_entity_type)) {
      // Stop when $current_limit is zero, unless $limit is also zero.
      if (isset($entity_info['fieldable']) && (!$limit || $current_limit > 0)) {
        foreach ($entity_info['bundles'] as $bundle_name => $bundle_info) {
          foreach (field_info_instances($entity_type, $bundle_name) as $field_name => $field_instance) {
            if (!isset($only_bundle_type) || isset($only_bundle_type) && $only_bundle_type == $bundle_name) {
              $field_info = field_info_field($field_name);
              if ($field_instance['widget']['type'] === 'geocoder') {
                $entity_load = $entity_info['load hook'];
                $query = db_select($entity_info['base table'], 'geo_ent')
                  ->fields('geo_ent', array($entity_info['entity keys']['id']));
                // Users don't have a column for the bundle.
                if ($entity_type != 'user') {
                  $query->condition($entity_info['entity keys']['bundle'], $bundle_name);
                }
                if (!$force_reload) {
                  if(!empty($entity_info['entity keys']['revision'])) {
                    $join_condition = 'geo_ent.' . $entity_info['entity keys']['revision'] . '=geo.revision_id';
                  }
                  else {
                    $join_condition = 'geo_ent.' . $entity_info['entity keys']['id'] . '=geo.entity_id';
                  }
                  $query->leftJoin('field_data_' . $field_instance['field_name'], 'geo', $join_condition);
                  $query->condition('geo.entity_id', NULL, 'IS NULL');
                }

                if (!empty($idlist)) {
                  $query->condition('geo_ent.' . $entity_info['entity keys']['id'], array(':ids' => $idlist));
                }

                if ($min_id) {
                  $query->condition('geo_ent.' . $entity_info['entity keys']['id'], $min_id, '>=');
                }

                if ($max_id) {
                  $query->condition('geo_ent.' . $entity_info['entity keys']['id'], $max_id, '<=');
                }

                $query->orderBy('geo_ent.' . $entity_info['entity keys']['id'], 'DESC');

                if ($limit) {
                  $query->range(0, $current_limit);
                }

                $results = $query->execute();
                while ($id = $results->fetchField()) {
                  $entity = $entity_load($id);
                  $langcode = field_language($entity_type, $entity, $field_name);
                  $items = field_get_items($entity_type, $entity, $field_name, $langcode);

                  // Check for values and if there are no values, reload the entity.
                  $reload = FALSE;
                  if ($field_info['type'] == 'geofield') {
                    if ($force_reload || (empty($items['wkt']) && empty($items['geom']))) {
                      $reload = TRUE;
                    }
                  }
                  elseif ($field_info['type'] == 'location') {
                    if ($force_reload || empty($items['latitude'])) {
                      $reload = TRUE;
                    }
                  }
                  elseif ($field_info['type'] == 'geolocation') {
                    if ($force_reload || empty($items['lat'])) {
                      $reload = TRUE;
                    }
                  }
                  if ($reload) {
                    $current_limit--;
                    if ($entity_type != 'user') {
                      $entity->original = array();
                    }
                    usleep(200000);
                    entity_save($entity_type, $entity);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
