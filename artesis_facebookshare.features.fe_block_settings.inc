<?php
/**
 * @file
 * artesis_facebookshare.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function artesis_facebookshare_default_fe_block_settings() {
  $export = array();

  // alpha_basetheme
  $theme = array();

  $theme['artesis_facebookshare-facebook_share'] = array(
    'module' => 'artesis_facebookshare',
    'delta' => 'facebook_share',
    'theme' => 'alpha_basetheme',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '<none>',
    'cache' => 8,
  );

  $export['alpha_basetheme'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();

  // Custom code to propagate alpha_basetheme settings to all available themes.
  foreach($themes as $theme_key => $_theme) {
    if (!empty($themes[$theme_key]->status)) {
      $theme['artesis_facebookshare-facebook_share']['theme'] = $theme_key;
      $export[$theme_key] = $theme;
    }
  }

  return $export;
}
