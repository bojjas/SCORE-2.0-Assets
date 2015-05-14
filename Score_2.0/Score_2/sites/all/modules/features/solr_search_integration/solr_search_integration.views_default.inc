<?php
/**
 * @file
 * solr_search_integration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solr_search_integration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'geoip_chapter_lookup';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_chapters';
  $view->human_name = 'GeoIP Chapter Lookup';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_chapters';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_chapters';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Address Geo: LatLong Pair (indexed) */
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['id'] = 'field_chapter_geo_latlon';
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['table'] = 'search_api_index_chapters';
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['field'] = 'field_chapter_geo_latlon';
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['label'] = 'Distance from Search';
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['show_distance_to_point'] = TRUE;
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['conversion_factor'] = '1.60926939169617';
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['field_chapter_geo_latlon']['precision'] = '0';
  /* Sort criterion: Address Geo: LatLong Pair (indexed) */
  $handler->display->display_options['sorts']['field_chapter_geo_latlon']['id'] = 'field_chapter_geo_latlon';
  $handler->display->display_options['sorts']['field_chapter_geo_latlon']['table'] = 'search_api_index_chapters';
  $handler->display->display_options['sorts']['field_chapter_geo_latlon']['field'] = 'field_chapter_geo_latlon';
  /* Filter criterion: Address Geo: LatLong Pair (indexed) */
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['id'] = 'field_chapter_geo_latlon';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['table'] = 'search_api_index_chapters';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['field'] = 'field_chapter_geo_latlon';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['operator'] = '-';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['expose']['operator_id'] = 'field_chapter_geo_latlon_op';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['expose']['label'] = 'Address';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['expose']['operator'] = 'field_chapter_geo_latlon_op';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['expose']['identifier'] = 'field_chapter_geo_latlon';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['plugin'] = 'geocoder';
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['plugin-geocoder'] = array(
    'geocoder_handler' => 'google',
    'geocoder_handler_options' => array(
      'geometry_type' => 'point',
      'all_results' => 0,
      'reject_results' => array(
        'APPROXIMATE' => 0,
        'GEOMETRIC_CENTER' => 0,
        'RANGE_INTERPOLATED' => 0,
        'ROOFTOP' => 0,
      ),
    ),
  );
  $handler->display->display_options['filters']['field_chapter_geo_latlon']['radius_options'] = '- -
5 5 km
10 10 km
16.09 10 mi
100 100 km';
  $export['geoip_chapter_lookup'] = $view;

  return $export;
}
