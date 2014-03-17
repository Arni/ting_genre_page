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
  $node = $context->data;
}

/**
 * 'Edit' callback for the content type.
 */
function ting_genre_page_related_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

