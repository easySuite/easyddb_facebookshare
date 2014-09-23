<?php
/**
 * @file
 * Facebook share pane for ctools.
 */

$plugin = array(
  'title' => t('Facebook share'),
  'description' => t('Container for Facebook buttons'),
  'category' => t('Page elements'),
  'single' => TRUE,
  'render callback' => 'artesis_facebookshare_plugin_render',
  'edit form' => 'artesis_facebookshare_plugin_edit_form',
);

/**
 * Plugin content renderer.
 */
function artesis_facebookshare_plugin_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'artesis_facebookshare';
  $block->content = artesis_facebookshare_content($conf);

  return $block;
}

/**
 * Returns an edit form for the content type.
 */
function artesis_facebookshare_plugin_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form += artesis_facebookshare_settings_form($conf);

  return $form;
}

/**
 * Plugin edit form submit handler.
 *
 * Saves the data from the form.
 */
function artesis_facebookshare_plugin_edit_form_submit($form, &$form_state) {
  $form_state['conf']['layout'] = $form_state['input']['layout'];
  $form_state['conf']['share'] = $form_state['input']['share'];
  $form_state['conf']['action'] = $form_state['input']['action'];
  $form_state['conf']['id'] = $form_state['input']['id'];
  $form_state['conf']['show_faces'] = $form_state['input']['show_faces'];
}
