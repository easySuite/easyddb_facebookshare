/**
 * @file
 */

Drupal.behaviors.artesis_facebookshare = {
  attach: function (settings) {
    var pageToShare = window.location.pathname;
  	var baseUrl = Drupal.settings.artesis_facebookshare.base_url;
	  var url = baseUrl + '/artesis_facebookshare/json/?url=' + baseUrl + pageToShare;
    jQuery.ajax({
      type: 'get',
      url: url,
      dataType: 'json',
      success: function(response) {
          jQuery('div.artesis-facebookshare-box-wrapper').append(response);
      }
    });
  }
};
