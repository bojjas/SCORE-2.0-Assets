<?php
/**
 * @file
 * chapters.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function chapters_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function chapters_node_info() {
  $items = array(
    'chapter' => array(
      'name' => t('Chapter'),
      'base' => 'node_content',
      'description' => t('SCORE Chapter Site'),
      'has_title' => '1',
      'title_label' => t('Chapter Name (Displayed on many pages. Example: Find a Chapter page)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
