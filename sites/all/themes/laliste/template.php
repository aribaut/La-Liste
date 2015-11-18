<?php

/*
 * Main template file for laliste theme
 *
**/

/*
 * Removing unecassry css files bloating our site
 **/
function laliste_css_alter(&$css) {
    unset($css[drupal_get_path('module','system').'/system.theme.css']);
    unset($css[drupal_get_path('module','system').'/system.base.css']);
    unset($css[drupal_get_path('module','system').'/system.menus.css']);
    unset($css[drupal_get_path('module','system').'/system.messages.css']);
    unset($css[drupal_get_path('module','system').'/system.admin.css']);
    unset($css[drupal_get_path('module','comment').'/comment.css']);
    unset($css[drupal_get_path('module','field').'/theme/field.css']);
    unset($css[drupal_get_path('module','search').'/search.css']);
    unset($css[drupal_get_path('module','user').'/user.css']);
    unset($css[drupal_get_path('module','node').'/node.css']);
    unset($css[drupal_get_path('module','views').'/css/views.css']);
    unset($css[drupal_get_path('module','ctools').'/css/ctools.css']);
    unset($css[drupal_get_path('module','addressfield').'/addressfield.css']);
}

/*
 * from https://www.drupal.org/node/1167712#comment-5080586
 */
function laliste_theme(&$existing, $type, $theme, $path) {
   $hooks['user_login_block'] = array(
     'template' => 'templates/user-login-block',
     'render element' => 'form',
   );
   return $hooks;
 }

/*
 * Theming the uer login block
 * from https://www.drupal.org/node/1167712#comment-9654249
 */
function laliste_preprocess_user_login_block(&$vars) {
  $vars['name'] = render($vars['form']['name']);
  $vars['pass'] = render($vars['form']['pass']);
  $vars['links'] = render($vars['form']['links']);
  $vars['submit'] = render($vars['form']['actions']['submit']);
  $vars['rendered'] = drupal_render_children($vars['form']);
}

function laliste_form_user_login_block_alter(&$form, &$form_state, $form_id) {
  $items = array();
  if (variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL)) {
    $items[] = l(t('Create Account'), 'user/register', array('attributes' => array('title' => t('Create an account.'))));
  }
  $items[] = l(t('Request Password'), 'user/password', array('attributes' => array('title' => t('Request password reset.'))));
  $form['links'] = array('#markup' => theme('item_list', array('items' => $items)));
  return $form;
}

/*
 * Remove block title
 */
function laliste_preprocess_block(&$vars) {
  if ($vars['block']->delta == 'login') {
    $vars['theme_hook_suggestions'][] = 'block__no_title';
  }
}

/**
* hook_form_FORM_ID_alter
*/
function laliste_form_search_block_form_alter(&$form, &$form_state, $form_id) {
    $form['search_block_form']['#title'] = ''; // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
    $form['search_block_form']['#default_value'] = t('Search'); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = ''; // Change the text on the submit button
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/img/search_icon.png');

    // Add extra attributes to the text box
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = '".t('Search')."';}";
    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == '".t('Search')."') {this.value = '';}";
    // Prevent user from searching the default text
    $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";

    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['search_block_form']['#attributes']['placeholder'] = t('Search');
}
?>
