<?php
/**
 * @file
 * mentoring_request.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mentoring_request_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create mentoring_request'.
  $permissions['create mentoring_request'] = array(
    'name' => 'create mentoring_request',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'score',
  );

  return $permissions;
}
