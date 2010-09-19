<?php
// $Id$

/**
 * @file
 * Page callback file for the single blog module.
 */

/**
 * Menu callback; displays a Drupal page containing recent blog entries.
 */
function single_blog_page_last() {
  $build = array();

  $query = db_select('node', 'n')->extend('PagerDefault');
  $nids = $query
    ->fields('n', array('nid', 'sticky', 'created'))
    ->condition('type', SINGLE_BLOG_NODE_TYPE)
    ->condition('status', 1)
    ->orderBy('sticky', 'DESC')
    ->orderBy('created', 'DESC')
    ->limit(variable_get('default_nodes_main', 10))
    ->addTag('node_access')
    ->execute()
    ->fetchCol();

  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
    $build += node_view_multiple($nodes);
    $build['pager'] = array(
      '#theme' => 'pager',
      '#weight' => 5,
    );
  }
  else {
    drupal_set_message(t('No blog entries have been created.'));
  }
  drupal_add_feed('blog/feed', t('RSS - blog'));

  return $build;
}

/**
 * Menu callback; displays an RSS feed containing recent blog entries.
 */
function blog_feed_last() {
  $nids = db_select('node', 'n')
    ->fields('n', array('nid', 'created'))
    ->condition('type', 'blog')
    ->condition('status', 1)
    ->orderBy('created', 'DESC')
    ->range(0, variable_get('feed_default_items', 10))
    ->addTag('node_access')
    ->execute()
    ->fetchCol();

  $channel['title'] = t('!site_name blog', array('!site_name' => variable_get('site_name', 'Drupal')));
  $channel['link'] = url('blog', array('absolute' => TRUE));

  node_feed($nids, $channel);
}
