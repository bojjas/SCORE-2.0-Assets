<?php
/**
 * @file
 * site.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function site_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function site_node_info() {
  $items = array(
    'site' => array(
      'name' => t('Site'),
      'base' => 'node_content',
      'description' => t('A site for SCORE content and users'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
