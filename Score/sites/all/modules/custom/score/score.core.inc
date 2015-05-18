<?php
/**
 *  POC codes for building out RPC integration.
 *  We will need to create a generic function for fetching and retrieving content using payloads as parameters.
 *  For now this will just be used to show that we can sync data between the two systems.
 */

function _score_chapter_upsert($node) {
  $legacy_nid = _get_legacy_nid($node);

  $payload = array(
    'nid' => $node->nid,
    'chapter_id' => (!empty($node->field_chapter_id['und']) ? $node->field_chapter_id['und'][0]['value'] : ''),
    'chapter_phone' => (!empty($node->field_chapter_phone['und']) ? $node->field_chapter_phone['und'][0]['value'] : ''),
    'chapter_email' => (!empty($node->field_chapter_email['und']) ? $node->field_chapter_email['und'][0]['value'] : ''),
    'chapter_name' => $node->title,
    'legacy_nid' => $legacy_nid,
  );

  $result = _post_chapter_to_core($payload);
  if ($result) {
    drupal_set_message('CORE sync: <i>' . $result['message'] . '</i>');
  }
}

function _get_legacy_nid($node) {
  return db_query('SELECT old_nid FROM {import_map} WHERE nid = :nid AND type = :type', array(':nid' => $node->nid, ':type' => $node->type))->fetchField();

}

function _post_chapter_to_core($payload) {
  $curl_handle = curl_init();
  curl_setopt($curl_handle, CURLOPT_URL, 'http://score.project/core/index.php/ChapterRestApi/chapter');
  curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl_handle, CURLOPT_POST, 1);
  curl_setopt($curl_handle, CURLOPT_POSTFIELDS, $payload);

  //execute post
  $result = curl_exec($curl_handle);
  $res = (array)json_decode($result);
  //close connection
  curl_close($curl_handle);

  return $res;
}
