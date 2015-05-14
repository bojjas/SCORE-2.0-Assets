<?php
/**
 * @file
 * mentoring_request.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function mentoring_request_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mentor_request';
  $context->description = 'Mentoring Request Sidebar output';
  $context->tag = 'Mentoring Request';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'mentoring/request/*' => 'mentoring/request/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'score-mentoring_request_search_block' => array(
          'module' => 'score',
          'delta' => 'mentoring_request_search_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mentoring Request');
  t('Mentoring Request Sidebar output');
  $export['mentor_request'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nearest_chapter_search';
  $context->description = 'Mentoring Request Nearest Chapter Search';
  $context->tag = 'Mentoring Request';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'score-nearest_chapter' => array(
          'module' => 'score',
          'delta' => 'nearest_chapter',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mentoring Request');
  t('Mentoring Request Nearest Chapter Search');
  $export['nearest_chapter_search'] = $context;

  return $export;
}
