<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="restaurant-top-section">
  <?php print render($content['field_restaurant_image']); ?>
  <div class="restaurant-overlay">
    <?php if (isset($rank)): ?>
      <?php if (true): ?>
        <hr class="half-length"><span class="tiny-rank"><?php print $rank; ?></span><hr class="half-length">
      <?php endif;?>
    <?php else: ?>
      <hr class="full-length">
    <?php endif; ?>
    <!-- restaurant-overlay -->
  </div>
</div>
<div class="restaurant-info-container">
  <div class="restaurant-info-map">
    <?php print views_embed_view('restaurant_map', 'block', $node->nid); ?>
  </div>
  <div class="restaurant-info-right-pane">
    <div class="restaurant-rank-big">
    <?php if (isset($prev_link)): ?><a href="<?php print $prev_link; ?>"><i class="fa fa-angle-left"></i></a><?php endif; ?>
      <div class="restaurant-country">
        <?php if (isset($country_icon) && isset($country_code)): ?>
        <div class="country simple">
          <a href="<?php print $country_view_url; ?>"><ul class="country-restaurant-flag"><li class='<?php print strtolower($country_code);?>' src='<?php print $country_icon;?>'></li></ul></a>
        </div>
        <?php endif; ?>
        <?php if (isset($rank)): ?><div class="simple"><p class="rank"><?php print $rank; ?></p></div><?php endif; ?>
        <?php if (isset($score)): ?><div class="simple"><p class="score"><?php print $score; ?></p></div><?php endif; ?>
      </div>
      <?php if (isset($next_link)): ?><a href="<?php print $next_link; ?>"><i class="fa fa-angle-right"></i></a><?php endif; ?>
      <div class="restaurant-title">
        <?php if ($title): ?><h1 id="node-title"><?php print $title; ?></h1><?php endif; ?>
      </div>
    </div>
    <div class="restaurant-details-container">
      <div class="restaurant-details">
        <ul>
          <?php if (isset($cooking_type)): ?>
          <li><span class="info-title"><?php print t('Cooking Type');?>:</span><p class="info-content"><?php print t($cooking_type); ?></p></li>
          <?php endif; ?>
          <?php if (isset($address_full)): ?>
          <li><span class="info-title"><?php print t('Address');?>:</span><p class="info-content"><?php print t($address_full); ?></p></li>
          <?php endif; ?>
          <?php if (isset($phone)): ?>
            <li><span class="info-title"><?php print t('Phone');?>:</span><p class="info-content"><?php print $phone; ?></p></li>
          <?php endif; ?>
          <?php if (isset($website_url)): ?>
            <li><span class="info-title"><?php print t('Internet');?>:</span><p class="info-content"><a href="<?php print $website_url; ?>" target="_blank"><?php print $website_host; ?></a></p></li>
          <?php endif; ?>
          <?php if (isset($tags)): ?>
            <?php $n = count($tags); $i=0; ?>
            <li><span class="info-title"><?php print t('Keywords');?>:</span><p class="info-content">
            <?php foreach($tags as $tag): ?><?php print t($tag); $i++; ?> <?php if ($i<$n): ?><?php print '|' ?><?php endif; ?> <?php endforeach; ?></p></li>
          <?php endif; ?>
        </ul>
      </div>
    </div>
  </div>
</div>
<div class="Grid">
   <div class="guides-container">
   <?php if (isset($guides)): ?>
      <?php foreach($guides as $guide_name => $guide_url): ?>
        <?php if (isset($guide_url)): ?>
          <a class="guide-box" href="<?php print $guide_url ?>" target="_blank"><?php print $guide_name; ?></a>
        <?php else: ?>
          <div class="guide-box"><?php print $guide_name; ?></div>
        <?php endif; ?>
      <?php endforeach; ?>
   <?php endif; ?>
   </div>
</div>
<div class="restaurant-user-actions-container">
   <div class="restaurant-user-action-share">
    <div class="restaurant-user-action-row1">
      <p><?php print t('Share'); ?></p>
    </div>
    <div class="restaurant-user-action-row2">
      <?php print render($content['addtoany']); ?>
    </div>
   </div>
   <div class="restaurant-user-action-add-list">
    <p></p>
   </div>
</div>
