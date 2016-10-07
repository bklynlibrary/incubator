<?php
/**
 * @file
 * incubator.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function incubator_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create incubator_submission content'.
  $permissions['create incubator_submission content'] = array(
    'name' => 'create incubator_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any incubator_submission content'.
  $permissions['delete any incubator_submission content'] = array(
    'name' => 'delete any incubator_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own incubator_submission content'.
  $permissions['delete own incubator_submission content'] = array(
    'name' => 'delete own incubator_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in incubator_locations'.
  $permissions['delete terms in incubator_locations'] = array(
    'name' => 'delete terms in incubator_locations',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in incubator_strategic_plan'.
  $permissions['delete terms in incubator_strategic_plan'] = array(
    'name' => 'delete terms in incubator_strategic_plan',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in incubator_target_audience'.
  $permissions['delete terms in incubator_target_audience'] = array(
    'name' => 'delete terms in incubator_target_audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any incubator_submission content'.
  $permissions['edit any incubator_submission content'] = array(
    'name' => 'edit any incubator_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own incubator_submission content'.
  $permissions['edit own incubator_submission content'] = array(
    'name' => 'edit own incubator_submission content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in incubator_locations'.
  $permissions['edit terms in incubator_locations'] = array(
    'name' => 'edit terms in incubator_locations',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in incubator_strategic_plan'.
  $permissions['edit terms in incubator_strategic_plan'] = array(
    'name' => 'edit terms in incubator_strategic_plan',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in incubator_target_audience'.
  $permissions['edit terms in incubator_target_audience'] = array(
    'name' => 'edit terms in incubator_target_audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'participate in workflow'.
  $permissions['participate in workflow'] = array(
    'name' => 'participate in workflow',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'incubator moderator' => 'incubator moderator',
      'incubator participant' => 'incubator participant',
      'incubator patron' => 'incubator patron',
    ),
    'module' => 'workflow',
  );

  return $permissions;
}
