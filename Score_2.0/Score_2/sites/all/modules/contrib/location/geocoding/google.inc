<?php

/**
 * @file
 * Google geocoder.
 */

/**
 *
 * Google now supports geocoding for all countries:
 * https://developers.google.com/maps/coverage
 */
function google_geocode_country_list() {
  $countries = location_get_iso3166_list();
  return array_keys($countries);
}

/**
 * Return general information about this geocoder.
 */
function google_geocode_info() {
  return array(
    'name' => 'Google Maps',
    'url' => 'http://maps.google.com',
    'tos' => 'http://www.google.com/help/terms_local.html',
    'general' => TRUE,
  );
}

/**
 * Perform a geocode on a location array.
 * @param $location
 *   The location array to process.
 * @return
 *   an associative array with keys 'lat' and 'lon' containing the coordinates.
 */
function google_geocode_location($location = array()) {

  $query = array(
    'region' => $location['country'],
    'address' => _google_geocode_flatten($location),
    'sensor' => 'false', // Required by TOS.
  );

  $url = url('http://maps.googleapis.com/maps/api/geocode/json', array(
    'query' => $query,
    'external' => TRUE,
  ));

  $http_reply = drupal_http_request($url);
  $data = json_decode($http_reply->data);

  if ($data->status != 'OK') {
    watchdog('location', 'Google geocoding returned status code: %status_code for the query url: %url', array('%status_code' => $data->status, '%url' => $url));
    return NULL;
  }

  $location = $data->results[0]->geometry->location;

  return array('lat' => $location->lat, 'lon' => $location->lng);
}

/**
 * General settings for this geocoder.
 */
function google_geocode_settings() {
  $form = array();

  $country = arg(4);
  if ($country) {
    $form['location_geocode_' . $country . '_google_accuracy_code'] = array(
      '#type' => 'select',
      '#title' => t('Google Maps Geocoding Accuracy for %country', array('%country' => $country ) ),
      '#default_value' => variable_get('location_geocode_' . $country . '_google_accuracy_code', variable_get('location_geocode_google_minimum_accuracy', '3')),
      '#options' => location_google_geocode_accuracy_codes(),
      '#description' => t('The minimum required accuracy for the geolocation data to be saved.'),
    );
  }
  return $form;
}

function _google_geocode_flatten($location = array()) {
  // Check if its a valid address
  if (empty($location)) {
    return '';
  }

  $address = '';
  if (!empty($location['street'])) {
    $address .= $location['street'];
  }

  if (!empty($location['city'])) {
    if (!empty($address)) {
      $address .= ', ';
    }

    $address .= $location['city'];
  }

  // Using province short code regularlyy gives no results.
  if (!empty($location['province_name'])) {
    if (!empty($address)) {
      $address .= ', ';
    }
    $address .= $location['province_name'];
  }

  if (!empty($location['postal_code'])) {
    if (!empty($address)) {
      $address .= ', ';
    }
    $address .= $location['postal_code'];
  }

  if (!empty($location['country'])) {
    if (!empty($address)) {
      $address .= ', ';
    }
    $address .= $location['country'];
  }

  return $address;
}

/**
 * Gets a components string to pass to the google geocode API.
 *
 * This is required to get more accurate results because sometimes when passing
 * in a small piece of information, like a country code only, it could also
 * match a different part of an address for another country as the highest
 * match.
 *
 * See https://developers.google.com/maps/documentation/geocoding/#ComponentFiltering
 * for details.
 *
 * @param array $location
 *   A location array.
 *
 * @return string
 *   A components string formatted as per the docs page linked to above.
 */
function _google_geocode_get_components($location = array()) {
  // Check if its a valid address
  if (empty($location)) {
    return '';
  }

  $components = array();
  if (!empty($location['city'])) {
    $components[] = 'locality:' . $location['city'];
  }
  if (!empty($location['province_name'])) {
    $components[] = 'administrative_area:' . $location['province_name'];
  }
  if (!empty($location['postal_code'])) {
    $components[] = 'postal_code:' . $location['postal_code'];
  }
  if (!empty($location['country'])) {
    $components[] = 'country:' . $location['country'];
  }

  return implode('|', $components);
}
