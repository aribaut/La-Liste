<?php

/**
 * @file
 *
 * A Views' field handler for editing a wine related field.
 *
 */
class laliste_rr_ct_field_handler_wine_edit extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields = array(
        'wine' => array(
            'table' => 'ranking',
            'field' => 'wine',
      ),
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render the field contents.
   *
   * @param $values
   * @return string
   */
  function render($values) {
    // Render a Views form item placeholder.
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  /**
   * Add to and alter the form.
   */
  function views_form(&$form, &$form_state) {
    // Create a container for our replacements
    $form[$this->options['id']] = array(
        '#type' => 'container',
        '#tree' => TRUE,
    );
    // Iterate over the result and add our replacement fields to the form.
    foreach($this->view->result as $row_index => $row) {
      // Add a text field to the form.  This array convention
      // corresponds to the placeholder HTML comment syntax.
      $form[$this->options['id']][$row_index] = array(
          '#type' => 'textfield',
          '#default_value' => $row->{$this->aliases['wine']},
          '#element_validate' => array(),
          '#size' => 4,
          //'#attributes' => array('disabled' => 'disabled'),
          //'#required' => TRUE,
      );
    }

    // Submit to the current page if not a page display.
    if ($this->view->display_handler->plugin_name != 'page') {
      $form['#action'] = current_path();
    }
  }

  /**
   * Form submit method.
   */
  function views_form_submit($form, &$form_state) {
    // Determine which nodes we need to update.
    $updates = array();
    foreach($this->view->result as $row_index => $row) {
      $value = $form_state['values'][$this->options['id']][$row_index];
      if ($row->{$this->aliases['wine']} != $value) {
        $updates[$row->{'ranking_restaurantguideranking_ranking_id'}] = $value;
      }
    }

    // Grab the rows we need to update and update them.
    foreach($updates as $id => $value) {
      // update ranking table with new value
      $num_updated = db_update('ranking')
          ->fields(array(
              'wine' => $value,
              'updated' => time(),
          ))
          ->condition('ranking_id', $id, '=')
          ->execute();
    }

    //@TODO
    //drupal_set_message(t('Updated @num wine.', array('@num' => sizeof($updates))));
    if (isset($num_updated)) {
      drupal_set_message(t('Updated @num wine.', array('@num' => $num_updated)));
    }
  }

}



/**
 * Validation callback for the wine element.
 *
 * @param $element
 * @param $form_state
 */
function laliste_rr_ct_field_handler_wine_edit_validate($element, &$form_state) {
  // Only allow titles where the first character is capitalized.
  //if (!ctype_upper(substr($element['#value'], 0, 1))) {
    //form_error($element, t('All titles must be capitalized.'));
  //}
}
