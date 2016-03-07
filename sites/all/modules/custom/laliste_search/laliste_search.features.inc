<?php
/**
 * @file
 * laliste_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function laliste_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function laliste_search_default_search_api_index() {
  $items = array();
  $items['la_liste_solr_multilingual_index'] = entity_import('search_api_index', '{
    "name" : "LA LISTE Solr multilingual index",
    "machine_name" : "la_liste_solr_multilingual_index",
    "description" : "My multilingual index",
    "server" : "laliste_solr",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [ "restaurant" ] },
      "index_directly" : 0,
      "cron_limit" : "200",
      "search_api_et" : { "include" : "incomplete", "fallback language" : "" },
      "fields" : {
        "field_address:country" : { "type" : "text", "boost" : "3.0" },
        "field_address:locality" : { "type" : "text", "boost" : "2.0" },
        "field_address:postal_code" : { "type" : "text", "boost" : "0.5" },
        "field_restaurant_rank" : { "type" : "integer" },
        "field_restaurant_score" : { "type" : "decimal" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "string", "boost" : "0.3" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title (Fulltext)",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_address:country" : true,
              "field_address:locality" : true
            }
          }
        },
        "search_api_addressfield" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_address:country" : true,
              "field_address:locality" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_address:country" : true, "field_address:locality" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 0,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function laliste_search_default_search_api_server() {
  $items = array();
  $items['laliste_solr'] = entity_import('search_api_server', '{
    "name" : "LA LISTE Solr",
    "machine_name" : "laliste_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/laliste",
      "http_user" : "admin",
      "http_pass" : "qFY0fwoeHPrA6VuVjvkw",
      "excerpt" : 1,
      "retrieve_data" : 1,
      "highlight_data" : 1,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function laliste_search_default_search_api_sort() {
  $items = array();
  $items['la_liste_solr_multilingual_index__field_restaurant_rank'] = entity_import('search_api_sort', '{
    "index_id" : "la_liste_solr_multilingual_index",
    "field" : "field_restaurant_rank",
    "name" : "LA LISTE",
    "enabled" : "0",
    "weight" : "-100",
    "identifier" : "la_liste_solr_multilingual_index__field_restaurant_rank",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Rank" },
    "rdf_mapping" : []
  }');
  $items['la_liste_solr_multilingual_index__field_restaurant_score'] = entity_import('search_api_sort', '{
    "index_id" : "la_liste_solr_multilingual_index",
    "field" : "field_restaurant_score",
    "name" : "LA LISTE",
    "enabled" : "1",
    "weight" : "-99",
    "identifier" : "la_liste_solr_multilingual_index__field_restaurant_score",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Score" },
    "rdf_mapping" : []
  }');
  $items['la_liste_solr_multilingual_index__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "la_liste_solr_multilingual_index",
    "field" : "search_api_relevance",
    "name" : "Search keyword(s)",
    "enabled" : "0",
    "weight" : "-97",
    "identifier" : "la_liste_solr_multilingual_index__search_api_relevance",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  $items['la_liste_solr_multilingual_index__title'] = entity_import('search_api_sort', '{
    "index_id" : "la_liste_solr_multilingual_index",
    "field" : "title",
    "name" : "Alphabetical",
    "enabled" : "1",
    "weight" : "-98",
    "identifier" : "la_liste_solr_multilingual_index__title",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Title" },
    "rdf_mapping" : []
  }');
  return $items;
}
