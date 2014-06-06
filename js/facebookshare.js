/**
 * @file
 */

Drupal.behaviors.facebookshare = {
  attach: function (settings) {
    jQuery('.facebookshare').once('fb').each(function() {
      jQuery(this).facebook("likebutton", {
        url: window.location.href,
        layout: Drupal.settings.facebookshare[this.id].layout,
        share: Drupal.settings.facebookshare[this.id].share,
        action: Drupal.settings.facebookshare[this.id].action,
        show_faces: Drupal.settings.facebookshare[this.id].show_faces,
        css_class : "absolutebutton"
      });
    });
  }
};
