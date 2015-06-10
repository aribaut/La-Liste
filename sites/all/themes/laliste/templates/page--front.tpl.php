<?php
/**
 * @file
 * Returns the HTML for the Drupal home page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">

  <header class="header" id="header" role="banner">

      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
      <?php endif; ?>

  </header>

  <div id="main">

    <div id="content" class="column" role="main" style="padding-left:60px;">
      <hr style="margin-left: 160px;border-color: #888;margin-top: 0px;margin-bottom: 40px;">
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 100;font-size: 20pt; color: #CCC;">
        DISTINGUER<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;LES MEILLEURS<br/>
      </span>
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 100;font-size: 20pt; color: #CCC;">
        RESTAURANTS DU MONDE<br/>
      </span>
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 300;font-size: 11pt; line-height: 100%;">
        EN COMPILANT PLUS DE 200 GUIDES GASTRONOMIQUES EXISTANTS<br/>
        ET PLUSIEURS SITES EN LIGNE SELON UNE MÉTHODOLOGIE TRANSPARENTE :<br/>
      </span>
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 100;font-size: 20pt; color: #CCC; line-height: 105%;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TELLE EST L’AMBITION<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;DE <span style="color: #888; font-weight: 400;">LA LISTE,</span><br/>
      </span>
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 100;font-size: 11pt;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;DONT LE PREMIER PALMARÈS SERA DÉVOILÉ CET AUTOMNE.
      </span>

      <div style="width:800px;color:#666;padding-top:40px;">
        <p>Hier encore réservée à une élite, la gastronomie mondiale est en pleine mutation. Dans tous les pays, elle est entrée par le divertissement et l’image dans la vie quotidienne, tandis que de nouvelles cultures culinaires ne cessent d’émerger, renouvelant avec bonheur les codes du « plus ancien des arts ».</p>
        <p>Les guides, arbitres du bon goût, récompensent les hauts lieux de la gastronomie selon des critères divers. Ils sélectionnent aussi des tables modestes. Les sites d’avis en ligne révèlent des opinions multiples et parfois contradictoires.</p>
        <p>Cette diversité sans précédent est une chance pour les gourmets. Elle fait aussi naître un besoin croissant de références objectives pour les consommateurs. C’est à ce besoin que répondra <span style="font-weight: bold;">LA LISTE</span>, le « classement des classements » gastronomiques inspiré par les travaux du Conseil de promotion du tourisme.</p>
        <p>La méthodologie engagée par <span style="font-weight: bold;">LA LISTE</span> est basée sur des algorithmes continuellement mis à jour. Cette démarche n’entend pas figer une vérité absolue, mais poser des points de repères dignes de confiance. <span style="font-weight: bold;">LA LISTE</span> sera à la gastronomie ce que l’ATP est au tennis ou le Classement de Shanghai aux universités : un indicateur de qualité clair, fiable et internationalement reconnu, établi en toute transparence selon des critères objectifs.</p>
        <p>Il sera élaboré en deux étapes :</p>
        <ul>
          <li>Une enquête d’abord menée auprès de milliers de professionnels de la gastronomie permettra d’évaluer la notoriété des guides existants dans le monde, ainsi que des principaux sites d’avis en ligne.</li>
          <li>Les évaluations des restaurants sélectionnés seront pondérées en fonction des résultats de l’enquête. Sur cette base, un classement des 1 000 meilleurs restaurants du monde sera établi. Les choix de <span style="font-weight: bold;">LA LISTE</span> porteront aussi sur l’hospitalité, les arts de la table, le service, la gamme de prix et la cave.</li>
        </ul>
        <p style="padding-bottom:20px;">Le palmarès final de <span style="font-weight: bold;">LA LISTE</span> sera dévoilé en octobre à Paris, lors d’une manifestation internationale où seront mises à l’honneur, à travers les chefs primés, les différentes pratiques culinaires qui font la richesse de la gastronomie mondiale.</p>
      </div>

      <hr style="margin-left: 200px;border-color: #888;margin-bottom: 40px;">
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 100;font-size: 20pt; color: #CCC;">
        ET VOUS,<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;SEREZ-VOUS SUR<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #888; font-weight: 400;">LA LISTE ?</span><br/>
      </span>
      <span style="font-family: 'Merriweather Sans', sans-serif; font-weight: 300;font-size: 11pt;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RENDEZ-VOUS EN OCTOBRE POUR LE SAVOIR !<br/>
      </span>
      <div style="margin-bottom:80px;"></div>

    </div>
  </div>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
