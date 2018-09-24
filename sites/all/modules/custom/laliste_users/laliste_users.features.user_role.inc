<?php
/**
 * @file
 * laliste_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function laliste_users_user_default_roles() {
  $roles = array();

  // Exported role: laliste user.
  $roles['laliste user'] = array(
    'name' => 'laliste user',
    'weight' => 5,
  );

  return $roles;
}
