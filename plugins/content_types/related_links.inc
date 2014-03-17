<?php

/**
 * @file
 * content_type plugin to show related links on a node with the
 * field_collection_related_links field.
 */

$plugin = array(
  'title' => t('Related links'),
  'description' => t('Show related links based on settings on the node.'),
  'content_types' => array('related_links'),
  'single' => TRUE,
  'render callback' => 'ting_genre_page_related_links_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Ting'),
);

/**
 * Render callback for this plugin
 */
function ting_genre_page_related_links_content_type_render($subtype, $conf, $args, $context) {
  // Since we require the node context, we can be sure it's always there.
  $node = $context->data;
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $block = new stdClass();
  $content = array();
  if ($node_wrapper->type->value() == 'genre_page') {
    $related_links = $node_wrapper->field_collection_related_links->value();
    foreach ($related_links as $related_link) {
      $rl_wrapper = entity_metadata_wrapper('field_collection_item', $related_link);
      $options = array('sanitize' => TRUE);
      $title = $rl_wrapper->field_related_link_title->value($options);
      $url = $rl_wrapper->field_related_link_url->value($options);
      $image = $rl_wrapper->field_related_link_image->value($options);
      $image = theme('image_style', array(
        'style_name' => 'ding_primary_small',
        'path' => $image['uri'],
        'alt' => $image['alt'],
      ));
      $content = $image;
      file_put_contents("/home/drupalpro/debug/debug1.txt", print_r($image, TRUE), FILE_APPEND);
    }
  }
  $block->content = $content;
  return $block;
}

/**
 * 'Edit' callback for the content type.
 */
function ting_genre_page_related_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

