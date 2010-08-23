<?php
// $Id$

/**
 * @file
 * HTML for an item in the single blog's block listing.
 *
 * Available variables:
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $title: A renderable array that that provides a title and link to the node.
 * - $name: Themed username of node author output from theme_username().
 *
 * The following variables are provided for contextual information.
 * - $node: Partial node object. Contains data that may not be safe.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $user: The user object of the node author.
 *
 * @see template_preprocess_single_blog_block_item()
 */
?>
<div class="<?php print $classes; ?>">

  <div class="date"><?php print $date; ?>:</div>

  <h4<?php print $title_attributes; ?>><?php print render($title); ?></h4>

  <div class="name"><?php print t('by !username', array('!username' => $name)); ?></div>

</div>
