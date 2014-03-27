<?php
/**
 * @file
 * Facebook share pane for ctools.
 */

$plugin = array(
  'title' => t('Facebook share'),
  'description' => t('Container for Facebook buttons'),
  'single' => TRUE,
  'render callback' => 'artesis_facebookshare_plugin_render',
  'edit form' => 'artesis_facebookshare_plugin_edit_form',
);

/**
 * Plugin content renderer.
 */
function artesis_facebookshare_plugin_render($subtype, $conf, $panel_args, $context) {
  drupal_add_js(
    array('artesis_facebookshare' =>
      array(
        'layout' => $conf['layout'],
        'action' => $conf['action'],
        'share' => empty($conf['share']) ? "false" : $conf['share'],
      ),
    ),
    'setting'
  );

  $path = drupal_get_path('module', 'artesis_facebookshare');
  drupal_add_js($path . '/js/jquery.facebook.min.js');
  drupal_add_js($path . '/js/artesis_facebookshare.js');

  $block = new stdClass();
  $block->module = 'artesis_facebookshare';
  $block->content = '<div class="artesis_facebookshare"></div>';

  return $block;
}

/**
 * Returns an edit form for the content type.
 *
 * We're not actually doing anything here, but we need to have this hook
 * for this content type to work.
 */
function artesis_facebookshare_plugin_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['layout'] = array(
    '#type' => 'select',
    '#options' => array(
      'standard' => t('Standard'),
      'box_count' => t('Box count'),
      'button_count' => t('Button count'),
      'button' => t('Button'),
    ),
    '#title' => t('Layout'),
    '#default_value' => isset($conf['layout']) ? $conf['layout'] : 0,
  );

  $form['action'] = array(
    '#type' => 'select',
    '#options' => array(
      'like' => t('Like'),
      'recommend' => t('Recommend'),
    ),
    '#title' => t('Action'),
    '#default_value' => isset($conf['action']) ? $conf['action'] : 0,
  );

  $form['share'] = array(
    '#type' => 'checkbox',
    '#return_value' => "true",
    '#default_value' => isset($conf['share']) ? $conf['share'] : "false",
    '#title' => t('Enable share button'),
  );

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
}
