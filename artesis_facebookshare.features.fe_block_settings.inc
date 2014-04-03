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

  $export['version'] = '2.0';

  $export['artesis_facebookshare-facebook_share'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'facebook_share',
    'module' => 'artesis_facebookshare',
    'node_types' => array(),
    'pages' => '<front>
admin/*',
    'roles' => array(),
    'themes' => array(
      'ddbasic' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'ddbasic',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
