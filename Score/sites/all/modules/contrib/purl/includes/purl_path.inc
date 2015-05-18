<?php

/**
 * Path prefixer.
 */
class purl_path implements purl_processor {

  public function method() {
    return 'path';
  }

  public function admin_form(&$form, $id) { 
  error_log('Sucharitha : '.'purl_path.admin_form '. print_r($form,true). ' Values:'. print_r($id,true));
  }

  /**
   * Detect a default value for 'q' when created.
   */
  public function detect($q) {
	  error_log('Sucharitha : '.'purl_path.detect '. print_r($q,true));
    return $q;
  }

  public function description() {
	  error_log('Sucharitha : '.'purl_path.description ');
    return t('Choose a path. May contain only lowercase letters, numbers, dashes and underscores. e.g. "my-value"');
  }

  /**
   * Tear apart the path and iterate thought it looking for valid values.
   */
  public function parse($valid_values, $q) {
    $parsed = array();
    $args = explode('/', $q);
    $arg = current($args);
    while (isset($valid_values[$arg])) {
      $parsed[$arg] = $valid_values[$arg];
      array_shift($args);
      $arg = current($args);
      if (in_array($arg, $parsed)) {
        break;
      }
    }
	error_log('Sucharitha : '.'purl_path.parse '. print_r($parsed,true));
    return purl_path_elements($this, $parsed);
  }

  /**
   * Rewrite the query string. Note that this is being passed through
   * the custom_url_rewrite_inbound() stack and may *not* directly
   * affect $_GET['q']. See purl_init() for how $_GET['q'] is affected
   * by processors.
   */
  public function adjust(&$value, $item, &$q) {
    $q = $this->remove($q, $item);
    $value = $this->remove($value, $item);
	error_log('Sucharitha : '.'purl_path.adjust '. print_r($value,true). ' Item :'. print_r($item,true).' Item :'. print_r($q,true));
  }

  /**
   * Removes specific modifier from a query string.
   *
   * @param $q
   *   The current path.
   * @param $element
   *   a purl_path_element object
   * @return path string with the modifier removed.
   */
  public function remove($q, $element) {
    $args = explode('/', $q);

    // Remove the value from the front of the query string
    if (current($args) === (string) $element->value) {
      array_shift($args);
    }
	error_log('Sucharitha : '.'purl_path.remove '. print_r($args,true));
    return implode('/', $args);
  }

  /**
   * Just need to add the value to the front of the path.
   */
  public function rewrite(&$path, &$options, $element) {

    // We attempt to remove the prefix from the path as a way to detect it's
    // presence. If the processor can remove itself than we're on a path alias
    // that contains our prefix. Then $alt will not be the same as the $path
    // and we won't do any rewriting.
    $alt = $this->remove($path, $element);

    if ($alt == $path && !_purl_skip($element, $options)) {
      $options['prefix'] = $element->value . '/' . $options['prefix'];
    }
	error_log('Sucharitha : '.'purl_path.Rewrite '. print_r($options,true));
  }
}
