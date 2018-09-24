<?php unset($form['name']['#description']); ?>
<?php unset($form['pass']['#description']); ?>
<?php //unset($form['captcha']['#description']); ?>
<h1>Login on LA LISTE</h1>
<div class="main-login-form">
  <div class=""><?php print render($form['name']); ?></div>
  <div class=""><?php print render($form['pass']); ?></div>
</div>
<?php print drupal_render($form['actions']); ?>
<?php print drupal_render_children($form) ?>
