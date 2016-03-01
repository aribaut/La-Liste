<?php

/**
 * @file
 * Contains SearchApiAddressfield.
 */

/**
 * Processor for appending full text value of administrative_area (state)
 * to its abbreviation (i.e., "CA" => "CA California").
 */
class SearchApiAddressfield extends SearchApiAbstractProcessor {

  public function configurationForm() {
    $form = parent::configurationForm();
    $form += array(
      'address_field' => array(
        '#markup' => '<p>There are no configurations for Address field processor in its current version,
                    as it only appends full text value of administrative_area (state) to its abbreviation
                    (i.e., "CA" => "CA California").</p>
                    <p>Make sure that both fields are added to index (administrative_area and country).</p>',
      ),
    );
    unset($form['fields']);

    return $form;
  }

  public function preprocessIndexItems(array &$items) {
    foreach ($items as &$item) {
      foreach ($item as $name => &$field) {
        // Don't preprocess the field with an empty value
        if (!empty($field['value'])) {

          $field_name = explode(":", $name);
          $field_info = field_read_fields(array('field_name' => $field_name[0]));
          // Only process fields of addressfield type
          if (!empty($field_info) && $field_info[$field_name[0]]['type'] == "addressfield") {

            // Process administrative_area (State) sub-field
            if (isset($field_name[1]) && $field_name[1] == "administrative_area") {

              // Get country code
              $country_code = reset(explode(" ", $item[$field_name[0] . ':country']['value']));
              module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
              $administrative_areas = addressfield_get_administrative_areas($country_code);

              if (!empty($administrative_areas)) {
                // Append administrative_area full value to abbreviation
                $field['value'] .= " " . $administrative_areas[$field['value']];
                $this->processField($field['value'], $field['type']);
              }
            }
          }
        }
      }
    }
  }
}