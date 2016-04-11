<?php unset($form['account']['name']['#description']); ?>
<?php unset($form['account']['mail']['#description']); ?>
<?php unset($form['account']['pass']['#description']); ?>
<?php unset($form['captcha']['#description']); ?>
<?php unset($form['field_first_name']); ?>
<?php unset($form['field_last_name']); ?>
<h1>Register on LA LISTE</h1>
<div class="main-register-form">
  <h2>Setup your basic account:</h2>
  <div class=""><?php print render($form['account']['mail']); ?></div>
  <div class=""><?php print render($form['account']['name']); ?></div>
  <div class=""><?php print render($form['account']['pass']); ?></div>
  <div class=""><?php print render($form['captcha']); ?></div>
</div>
<?php print drupal_render($form['actions']); ?>
<?php print drupal_render_children($form) ?>
