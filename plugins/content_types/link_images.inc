<?php

$plugin = array(
  'title' => t('Image links'),
  'description' => t('Show a link with images'),
  'single' => TRUE,
  'content_types' => array('link_images'),
  'render callback' => 'link_images_content_type_render',
  'category' => t('Ting'),
  'render last' => TRUE,
);

/**
 * Render the ting search results amount block.
 */
function link_images_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = 'Test';
  return $block;
}


/**
 * Enable admin settings page
 */
function ting_genre_page_link_images_content_type_edit_form($form, &$form_state) {
  return $form;
}

