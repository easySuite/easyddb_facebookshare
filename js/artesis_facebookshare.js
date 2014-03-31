/**
 * @file
 */

Drupal.behaviors.artesis_facebookshare = {
  attach: function (settings) {
    jQuery('.artesis_facebookshare').once('fb').each(function() {
      jQuery(this).facebook("likebutton", {
        url: window.location.href,
        layout: Drupal.settings.artesis_facebookshare[this.id].layout,
        share: Drupal.settings.artesis_facebookshare[this.id].share,
        action: Drupal.settings.artesis_facebookshare[this.id].action,
        show_faces: Drupal.settings.artesis_facebookshare[this.id].show_faces,
        css_class : "absolutebutton"
      });
    });
  }
};
