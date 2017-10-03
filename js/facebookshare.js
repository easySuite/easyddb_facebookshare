/**
 * @file
 */
(function($) {
  Drupal.behaviors.facebookshare = {
  attach: function (settings) {
    if ($(document).find('body').hasClass('node-type-ding-news')) {
      $('.pane-facebookshare-facebook-share').insertAfter('.ding-news-right .field-name-field-ding-news-tags');
     }
     if ($(document).find('body').hasClass('node-type-ding-event')) {
       $('.pane-facebookshare-facebook-share').insertAfter('.right .field-name-field-ding-event-tags');
     }

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
})(jQuery);