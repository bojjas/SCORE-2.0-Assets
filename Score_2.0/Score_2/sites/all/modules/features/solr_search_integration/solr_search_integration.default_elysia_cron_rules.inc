<?php
/**
 * @file
 * solr_search_integration.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function solr_search_integration_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'search_api_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['search_api_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'search_api_solr_cron';
  $cron_rule->disable = TRUE;
  $cron_rule->rule = '*/5 * * * *';
  $cron_rule->weight = 5;
  $cron_rule->context = '5';
  $cron_rules['search_api_solr_cron'] = $cron_rule;

  return $cron_rules;

}
