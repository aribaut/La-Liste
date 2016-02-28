<?php

/**
 * @file
 * Display Suite 2 column template.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col search-result <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
  <div class="search-container">
    <?php print $right; ?>
    <?php if(isset($address_full)):?>
      <div class="field-address">
        <p class="address"><?php print $address_full;?></p>
      </div>
    <?php endif; ?>
    <div class="simple">
    <?php if (isset($country_code)): ?>
        <div class="search-country">
          <a href="<?php print $GLOBALS['base_url'].'/country/'.$country_code.'/laliste/view'?>">
            <?php print theme('countryicons_icon', array('code' =>  $country_code, 'iconset' =>  'gosquared_flat_large')); ?>
          </a>
        </div>
    <?php endif; ?>
    <?php if (isset($rank)): ?>
      <div class="search-rank">
        <p class="rank"><?php print $rank;?></p>
      </div>
    <?php endif; ?>
    <?php if (isset($score)): ?>
      <div class="search-score">
        <p class="score"><?php print $score;?></p>
      </div>
    <?php endif; ?>
    </div>
  </div>
  </<?php print $right_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
