<?php
/**
 * @file
 * mentoring_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mentoring_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
