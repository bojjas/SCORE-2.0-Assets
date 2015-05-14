<?php
/**
 * @file
 * solr_search_integration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function solr_search_integration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function solr_search_integration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function solr_search_integration_default_search_api_index() {
  $items = array();
  $items['chapters'] = entity_import('search_api_index', '{
    "name" : "SOLR - Chapters",
    "machine_name" : "chapters",
    "description" : "Chapter search index.",
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "chapter" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_chapter_address:additional" : { "type" : "text" },
        "field_chapter_address:city" : { "type" : "text" },
        "field_chapter_address:country" : { "type" : "text" },
        "field_chapter_address:country_name" : { "type" : "text" },
        "field_chapter_address:name" : { "type" : "text" },
        "field_chapter_address:postal_code" : { "type" : "text" },
        "field_chapter_address:province" : { "type" : "text" },
        "field_chapter_address:province_name" : { "type" : "text" },
        "field_chapter_address:street" : { "type" : "text" },
        "field_chapter_geo:latlon" : { "type" : "string", "real_type" : "location" },
        "group_group" : { "type" : "boolean" },
        "is_new" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "vid" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function solr_search_integration_default_search_api_server() {
  $items = array();
  $items['solr_server'] = entity_import('search_api_server', '{
    "name" : "SOLR Server",
    "machine_name" : "solr_server",
    "description" : "Apache SOLR Search Server v4.x",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "solr",
      "port" : "8983",
      "path" : "\\/solr\\/score",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
