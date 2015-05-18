<?php
/**
 * @file
 * chapters.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function chapters_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_events_custom|node|chapter|form';
  $field_group->group_name = 'group_chapter_events_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events section',
    'weight' => '5',
    'children' => array(
      0 => 'field_chapter_image_event',
      1 => 'field_chapter_event_text',
      2 => 'field_chapter_image_customevent',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Events section',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-events-custom field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_events_custom|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_mentor_custom|node|chapter|form';
  $field_group->group_name = 'group_chapter_mentor_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mentoring Section',
    'weight' => '4',
    'children' => array(
      0 => 'field_chapter_image_mentor',
      1 => 'field_chapter_mentor_text',
      2 => 'field_chapter_image_custommentor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mentoring Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-mentor-custom field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_mentor_custom|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_slide_events|node|chapter|form';
  $field_group->group_name = 'group_chapter_slide_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events Slide',
    'weight' => '8',
    'children' => array(
      0 => 'field_chapter_slide_customevent',
      1 => 'field_chapter_slide_event',
      2 => 'field_chapter_slide_event_top',
      3 => 'field_chapter_slide_event_mid',
      4 => 'field_chapter_slide_event_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Events Slide',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-slide-events field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_slide_events|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_slide_mentoring|node|chapter|form';
  $field_group->group_name = 'group_chapter_slide_mentoring';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mentoring Slide',
    'weight' => '7',
    'children' => array(
      0 => 'field_chapter_slide_custommentor',
      1 => 'field_chapter_slide_mentor',
      2 => 'field_chapter_slide_mentor_top',
      3 => 'field_chapter_slide_mentor_mid',
      4 => 'field_chapter_slide_mentor_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mentoring Slide',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-slide-mentoring field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_slide_mentoring|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_slide_templates|node|chapter|form';
  $field_group->group_name = 'group_chapter_slide_templates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Templates Slide',
    'weight' => '9',
    'children' => array(
      0 => 'field_chapter_slide_customtpl',
      1 => 'field_chapter_slide_tpl',
      2 => 'field_chapter_slide_tpl_top',
      3 => 'field_chapter_slide_tpl_mid',
      4 => 'field_chapter_slide_tpl_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Templates Slide',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-slide-templates field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_slide_templates|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_social|node|chapter|form';
  $field_group->group_name = 'group_chapter_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media Links',
    'weight' => '10',
    'children' => array(
      0 => 'field_chapter_linkedin',
      1 => 'field_chapter_facebook',
      2 => 'field_chapter_twitter',
      3 => 'field_chapter_youtube',
      4 => 'field_chapter_instagram',
      5 => 'field_chapter_blog_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Media Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-social field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_social|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chapter_tpl_custom|node|chapter|form';
  $field_group->group_name = 'group_chapter_tpl_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Templates section',
    'weight' => '6',
    'children' => array(
      0 => 'field_chapter_image_template',
      1 => 'field_field_chapter_tpl_text',
      2 => 'field_chapter_image_customtpl',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Templates section',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-chapter-tpl-custom field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_chapter_tpl_custom|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crm_fields|node|chapter|form';
  $field_group->group_name = 'group_crm_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CRM Fields',
    'weight' => '22',
    'children' => array(
      0 => 'field_legacy_website',
      1 => 'field_legacy_chartered_date',
      2 => 'field_legacy_termination_date',
      3 => 'field_legacy_status',
      4 => 'field_chapter_district',
      5 => 'field_chapter_region',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'CRM Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-crm-fields field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_crm_fields|node|chapter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|chapter|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'chapter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '3',
    'children' => array(
      0 => 'field_header_media_type',
      1 => 'field_chapter_image',
      2 => 'field_chapter_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Header',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-header field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_header|node|chapter|form'] = $field_group;

  return $export;
}
