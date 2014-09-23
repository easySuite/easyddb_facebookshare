<?php
/**
 * @file
 * facebookshare.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function facebookshare_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['facebookshare-facebook_share'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'facebook_share',
    'module' => 'facebookshare',
    'node_types' => array(),
    'pages' => '<front>
admin/*
node/add
node/add/*
node/*/edit
node/*/delete
node/*/clone*
taxonomy/term/*/edit
taxonomy/term/*/delete',
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
      'hjorbib' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hjorbib',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}