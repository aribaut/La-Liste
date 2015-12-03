<?php
/**
 * @file
 * laliste_roles_and_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function laliste_roles_and_permissions_user_default_roles() {
  $roles = array();

  // Exported role: chief editor.
  $roles['chief editor'] = array(
    'name' => 'chief editor',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
