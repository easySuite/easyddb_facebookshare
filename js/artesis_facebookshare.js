/**
 * @file
 */

Drupal.behaviors.artesis_facebookshare = {
  attach: function (settings) {
    jQuery('.artesis_facebookshare').once('fb').facebook("likebutton", {
      url: window.location.href,
      layout: Drupal.settings.artesis_facebookshare.layout,
      share: Drupal.settings.artesis_facebookshare.share,
      action: Drupal.settings.artesis_facebookshare.action
    });
  }
};
