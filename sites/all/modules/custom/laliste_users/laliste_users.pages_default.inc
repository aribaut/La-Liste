<?php
/**
 * @file
 * laliste_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function laliste_users_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__laliste';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'La Liste user page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'laliste',
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b0d648cf-6e1e-4f20-aff2-241b38549b93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9ee6e107-af36-4a68-819f-9fd4d85c7e77';
    $pane->panel = 'left';
    $pane->type = 'token';
    $pane->subtype = 'user:picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9ee6e107-af36-4a68-819f-9fd4d85c7e77';
    $display->content['new-9ee6e107-af36-4a68-819f-9fd4d85c7e77'] = $pane;
    $display->panels['left'][0] = 'new-9ee6e107-af36-4a68-819f-9fd4d85c7e77';
    $pane = new stdClass();
    $pane->pid = 'new-0ae06fa3-dd0c-432a-ae5e-faa4d63d9466';
    $pane->panel = 'right';
    $pane->type = 'token';
    $pane->subtype = 'user:field_first_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0ae06fa3-dd0c-432a-ae5e-faa4d63d9466';
    $display->content['new-0ae06fa3-dd0c-432a-ae5e-faa4d63d9466'] = $pane;
    $display->panels['right'][0] = 'new-0ae06fa3-dd0c-432a-ae5e-faa4d63d9466';
    $pane = new stdClass();
    $pane->pid = 'new-2091931b-e6f7-44a1-b6eb-04ed2dd62cc5';
    $pane->panel = 'right';
    $pane->type = 'token';
    $pane->subtype = 'user:field_last_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2091931b-e6f7-44a1-b6eb-04ed2dd62cc5';
    $display->content['new-2091931b-e6f7-44a1-b6eb-04ed2dd62cc5'] = $pane;
    $display->panels['right'][1] = 'new-2091931b-e6f7-44a1-b6eb-04ed2dd62cc5';
    $pane = new stdClass();
    $pane->pid = 'new-3cc53f4a-20af-4b9c-b7ed-8a1955dbf481';
    $pane->panel = 'right';
    $pane->type = 'token';
    $pane->subtype = 'user:field_user_address';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3cc53f4a-20af-4b9c-b7ed-8a1955dbf481';
    $display->content['new-3cc53f4a-20af-4b9c-b7ed-8a1955dbf481'] = $pane;
    $display->panels['right'][2] = 'new-3cc53f4a-20af-4b9c-b7ed-8a1955dbf481';
    $pane = new stdClass();
    $pane->pid = 'new-34817e5b-1f2e-48be-be86-05553e3cac15';
    $pane->panel = 'right';
    $pane->type = 'token';
    $pane->subtype = 'user:field_user_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '34817e5b-1f2e-48be-be86-05553e3cac15';
    $display->content['new-34817e5b-1f2e-48be-be86-05553e3cac15'] = $pane;
    $display->panels['right'][3] = 'new-34817e5b-1f2e-48be-be86-05553e3cac15';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view__laliste'] = $handler;

  return $export;
}
