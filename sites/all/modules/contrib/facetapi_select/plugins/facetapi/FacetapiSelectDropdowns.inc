<?php

/**
 * @file
 * Contains FacetapiSelectDropdowns class.
 */

/**
 * Widget that renders facets as dropdowns.
 */
class FacetapiSelectDropdowns extends FacetapiWidgetLinks {
  private $urls_cache = array();

  /**
   * Renders the links.
   */
  public function execute() {
    static $count = 0;
    $count++;
    $element = &$this->build[$this->facet['field alias']];
    $settings = $this->settings;

    $variables = $this->buildItems($element);

    if (!empty($variables['options'])) {
      $default_option_label = !empty($settings->settings['default_option_label']) ? filter_xss_admin($settings->settings['default_option_label']) : t('--Choose--');
      $variables['default_option_label'] = theme('facetapi_select_select_option', array(
        'facet_text' => $default_option_label,
        'show_count' => FALSE
      ));
    }

    $element = drupal_get_form('facetapi_select_facet_form', $variables, $count);
  }

  /**
   * Build the active items and the options array for the provided facetapi element.
   *
   * @param array $element
   *   The facetapi element as provided by execute().
   *
   * @return array
   *   An array that contains the options and active items arrays.
   */
  protected function buildItems($element, $depth = 0) {
    $settings = $this->settings;
    $variables = array('active_items' => array(), 'options' => array());

    $is_active = FALSE;
    $url = NULL;
    foreach ($element as $value => $item) {
      $is_active = FALSE;
      $url = $this->getUrl($item);
      $item['#markup'] = str_repeat('-', $depth) . ' ' . $item['#markup'];

      if ($item['#active']) {
        // We use $element[$value] so we don't get the "--" in front of the text
        // since it is already tiered for the active links.
        $variables['active_items'][$url]['data'] = $this->buildActiveLink($element[$value]);
        $is_active = TRUE;
      }
      else {
        $variables['options'][$url] = $this->buildSelectOption($item);
      }

      if ($this->shouldExpandChildren($is_active, $item)) {
        $this->appendChildren($variables, $item, $depth, $is_active);
      }
    }

    // When there are currently no options and the current active item has children
    // let's add the children as options.
    if ($is_active && empty($variables['options']) && !empty($item['#item_children'])) {
      $this->appendChildren($variables, $item, $depth);
    }

    return $variables;
  }

  /**
   * Determine if we should expand the children for the current active item.
   *
   * @param array $is_active
   *   Dictates if the current item is active.
   * @param array $item
   *   The current item we are processing.
   *
   * @return boolean
   *   Returns TRUE if we should expand the items children and FALSE otherwise.
   */
  protected function shouldExpandChildren($is_active, $item) {
    $element = &$this->build[$this->facet['field alias']];
    $settings = $this->settings;

    $has_siblings = count($element) > 1;
    $has_children = !empty($item['#item_children']);
    $is_expanded = (bool) $settings->settings['show_expanded'];
    $is_active_and_has_siblings = ($is_active && $has_siblings);

    return (($is_expanded || $is_active_and_has_siblings) && $has_children);
  }

  /**
   * Append children to the active items and options for the facet.
   *
   * @param array $variables
   *   The variables array as provided by FacetapiSlectDropdowns::getItems().
   * @param array $item
   *   The facet item to use for retrieving the children.
   * @param int $depth
   *   The current depth of the childen.
   * @param array $is_active
   *   Dictates if the current item is active.
   *
   * @return void
   */
  protected function appendChildren(array &$variables, array $item, $depth = 0, $is_active = FALSE) {
    $tmpItems = $this->buildItems($item['#item_children'], ++$depth);

    if (!empty($tmpItems['active_items'])) {
      $variables['active_items'][$this->getUrl($item)]['children'] = $tmpItems['active_items'];
    }

    if (!empty($tmpItems['options'])) {
      // We only ever want to add an OpGroup when there are child options and
      // the current item is active.
      if ($is_active) {
        $this->appendOpGroupheader($variables, $item);
      }
      $variables['options'] += $tmpItems['options'];
    }
  }

  /**
   * Append the OpGroup header to the options array for active items so that
   * they should not selectable.
   *
   * @param array $variables
   *   The variables array as provided by FacetapiSlectDropdowns::getItems().
   * @param array $item
   *   The item to build the opgroup header for.
   *
   * @return void
   */
  function appendOpGroupheader(array &$variables, array $item) {
    if (!empty($item) && isset($variables['active_items'][$this->getUrl($item)])) {
      $text = $this->buildSelectOption($item);
      $variables['options'][$text] = array();
    }
  }

  /**
   * Build an individual active item link.
   *
   * @param array $item
   *   The facet item to build as an active link.
   * @param string $path
   *   The path to use for the link as determined by the facetapi_select settings.
   *
   * @return string
   *   The built active link based on the specified item.
   */
  protected function buildActiveLink(array $item) {
    // We call theme directly here because we will be adding these items to a
    // theme_list() build array as the items.
    return theme('facetapi_link_active', array(
      'text' => $item['#markup'],
      'count' => $item['#count'],
      'path' => $item['#path'],
      'options' => array(
        'query' => $item['#query'],
        'attributes' => array(
          'class' => 'facetapi-active',
          'id' => drupal_html_id('facetapi-link'),
          'rel' => 'nofollow',
        ),
        // Because the path has already been through url(), mark it as external.
        'html' => TRUE,
      )
    ));
  }

  /**
   * Build an indiviudal select option.
   *
   * @param array $item
   *   The facet item to use for to build the select option for.
   *
   * @return string
   *   The themed individual select option text.
   */
  protected function buildSelectOption(array $item) {
    return theme('facetapi_select_select_option', array(
      'facet_text' => $item['#markup'],
      'facet_count' => $item['#count'],
      'show_count' => isset($this->settings->settings['hide_facet_count']) ? !$this->settings->settings['hide_facet_count'] : TRUE,
    ));
  }

  /**
   * Retrieve the url for the specified facet item.
   *
   * @param array $item
   *   The facet item to use for retrieving the url.
   * @param boolean $append_query (optional)
   *   Determines if the query should be appended to the return url.
   */
  protected function getUrl(array $item, $append_query = TRUE) {
    if (!isset($this->urls_cache[$item['#path']])) {
      $path = !empty($this->settings->settings['submit_page']) ? $this->settings->settings['submit_page'] : $item['#path'];
      $path = strpos($item['#path'], $path) === 0 ? $item['#path'] : $path;
      $this->urls_cache[$item['#path']] = $path;
    }

    $query = ($append_query) ? $item['#query'] : array();
    return url($this->urls_cache[$item['#path']], array('query' => $query));
  }

  public function settingsForm(&$form, &$form_state) {
    parent::settingsForm($form, $form_state);

    $states = array(
      'visible' => array(
        'select[name="widget"]' => array('value' => $this->id),
      ),
    );

    $form['widget']['widget_settings']['links'][$this->id]['default_option_label'] = array(
      '#title' => t('Default Option Label'),
      '#type' => 'textfield',
      '#default_value' => !empty($this->settings->settings['default_option_label']) ? $this->settings->settings['default_option_label'] : '',
      '#states' => $states,
    );
    $form['widget']['widget_settings']['links'][$this->id]['submit_page'] = array(
      '#type' => 'textfield',
      '#title' => t('Force this facet to submit to a specific search page'),
      '#description' => t('This facet will always submit to the page it is on if left empty.'),
      '#default_value' => !empty($this->settings->settings['submit_page']) ? $this->settings->settings['submit_page'] : '',
      '#states' => $states,
    );
    $form['widget']['widget_settings']['links'][$this->id]['hide_facet_count'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide the facet count'),
      '#default_value' => !empty($this->settings->settings['hide_facet_count']) ? $this->settings->settings['hide_facet_count'] : FALSE,
      '#states' => $states,
    );
  }
}
