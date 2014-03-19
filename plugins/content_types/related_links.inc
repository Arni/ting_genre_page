<?php

/**
 * @file
 * content_type plugin to show related links on a node with the
 * field_collection_related_links field.
 */

$plugin = array(
  'title' => t('Related links'),
  'description' => t('Show related links based on field values from the node.'),
  'content_types' => array('related_links'),
  'single' => TRUE,
  'render callback' => 'ting_genre_page_related_links_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node', array('type' => 'genre_page')),
  'category' => t('Ting'),
);

/**
 * Render callback for this plugin
 */
function ting_genre_page_related_links_content_type_render($subtype, $conf, $args, $context) {
  // Since we require the node context, we can be sure it's always there.
  $node = $context->data;
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $related_links = $node_wrapper->field_collection_related_links->value();
  $link_items = array();
  // Loop through the field collection entitites and prepare the link items.
  foreach ($related_links as $link) {
    $fc_wrapper = entity_metadata_wrapper('field_collection_item', $link);
    $title = $fc_wrapper->field_related_link_title->value();
    $url = $fc_wrapper->field_related_link_url->value();
    $image = $fc_wrapper->field_related_link_image->value();
    $image = ting_genre_page_related_links_prepare_image($link);
    $link_items[] = array(
      'title' => $title,
      'url' => $url,
      'image' => $image,
    );
  }
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'ting_genre_page_link_group',
    '#link_items' => $link_items,    
  );
  return $block;
}

/**
 * 'Edit' callback for the content type.
 */
function ting_genre_page_related_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Helper function to setup adaptive image formatter render array.
 */
function ting_genre_page_related_links_prepare_image($entity) {
  return field_view_field('field_collection_item', $entity, 'field_related_link_image', array(
    'label' => 'hidden',
    'type' => 'cs_adaptive_image',
    'settings' => array(
      'image_link' => '', // We take care of the linking in the template.
      'styles' => array(
        'breakpoint_1' => 768,
        'style_1' => 'ting_related_links_medium',
        'breakpoint_2' => 480,
        'style_2' => 'ting_related_links_small',
        'max_style' => 'ting_related_links_large',
        'fallback_style' => 'large', // Use a Drupal default style as fallback
      ),
    ),
  ));
}

