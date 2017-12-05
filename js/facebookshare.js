/**
 * @file
 */
(function($) {
  Drupal.behaviors.facebookshare = {
  attach: function (context, settings) {
    if ($(context).find('body').hasClass('node-type-ding-news')) {
      $('#node-ding-news-full-group-right', context).append($('.pane-facebookshare-facebook-share'));
     }
     if ($(context).find('body').hasClass('node-type-ding-event')) {
       $('#node-ding-event-full-group-right', context).append($('.pane-facebookshare-facebook-share'));
     }

    $('.facebookshare').once('fb').each(function() {
      $(this).facebook("likebutton", {
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
