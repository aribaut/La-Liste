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
<div class="Grid Grid--full large-Grid--fit" style="position: relative;">
  <img class="restaurant-media" src="<?php print base_path() . path_to_theme(); ?>/img/photo-restaurant.png">
  <div class="restaurant-overlay">
    <hr class="half-length"><?php if ($rank): ?><span class="tiny-rank"><?php print $rank; ?><sup>e</sup></span><?php endif; ?><hr class="half-length">
    <?php if ($title): ?><h1 id="node-title"><?php print $title; ?></h1><?php endif; ?>
    <div class="Grid Grid--full large-Grid--fit restaurant-country">
      <div class="country"><?php if (isset($country_icon)): ?><?php print $country_icon; ?><?php endif; ?></div>
      <div class="restaurant-address">
        <?php if (isset($address1)): ?><span><?php print $address1; ?></br></span><?php endif; ?>
        <?php if (isset($address2)): ?><span><?php print $address2; ?></br></span><?php endif; ?>
        <?php if (isset($postal_code)): ?><span><?php print $postal_code; ?></span><?php endif; ?>
        <?php if (isset($city)): ?><span><?php print $city; ?></br></span><?php endif; ?>
        <?php if (isset($country_name)): ?><span><?php print $country_name; ?></span><?php endif; ?>
      </div>
    </div>
    <hr class="full-length">
  </div>
</div>
<div class="Grid Grid--full large-Grid--fit restaurant-info-container">
  <div class="Grid Grid-cell Grid--center u-small-full u-med-full u-large-1of3 laliste-box laliste-box-bg laliste-box-height-med">
    <?php //if ($content['field_rank']): ?>
        <?php //render($content['field_rank']); ?>
        <?php if ($rank): ?><p class="rank"><?php print $rank; ?><sup>e</sup></p><?php endif; ?>
    <?php //endif; ?>
  </div>
  <div class="Grid Grid-cell Grid--center laliste-box no-hcenter laliste-box-bg laliste-box-height-med u-textLeft">
    <div class="restaurant-info">
      <ul>
        <?php if (isset($cooking_type)): ?>
        <li><span class="info-title"><?php print t('Type de cuisine');?>:</span> <span class="info-content"><?php print t($cooking_type); ?></span></li>
        <?php endif; ?>
        <?php if (isset($website)): ?>
          <li><span class="info-title"><?php print t('Site Internet');?>:</span> <span class="info-content"><a href="<?php print $website; ?>" target="_blank"><?php print $website; ?></a></span></li>
        <?php endif; ?>
        <?php if (isset($phone)): ?>
          <li><span class="info-title"><?php print t('Téléphone');?>:</span> <span class="info-content"><?php print $phone; ?></span></li>
        <?php endif; ?>
        <?php if (isset($tags)): ?>
          <?php $n = count($tags); $i=0; ?>
          <li><span class="info-title"><?php print t('Mots-Clefs');?>:</span> <span class="info-content">
          <?php foreach($tags as $tag): ?><?php print t($tag); $i++; ?> <?php if ($i<$n): ?><?php print '|' ?><?php endif; ?> <?php endforeach; ?></span></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
</div>
<div class="Grid Grid--full large-Grid--fit">
   <div class="Grid Grid-cell Grid--center Grid--1of5 food-box-container">
   <?php if (isset($guides)): ?>
      <?php foreach($guides as $guide): ?>
      <a class="food-guide-box" href="#"><?php print $guide; ?></a>
      <?php endforeach; ?>
   <?php endif; ?>
   </div>
</div>
<div class="Grid Grid--full large-Grid--fit restaurant-info-container">
   <div class="Grid Grid-cell Grid--center u-small-full u-med-full u-large-1of3 laliste-box laliste-box-bg laliste-box-height-tall">
    <p class="restaurant-user-actions">Partager</p>
   </div>
   <div class="Grid Grid-cell Grid--center laliste-box laliste-box-bg laliste-box-height-tall">
    <p class="restaurant-user-actions">Ajouter à ma liste</p>
   </div>
</div>
