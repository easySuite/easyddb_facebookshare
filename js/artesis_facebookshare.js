/**
 * @file
 */


function artesis_facebookshare_popup() {
  var head_meta_url = jQuery('meta[property="og:url"]').attr("content");
  var head_meta_title = jQuery('meta[property="og:title"]').attr("content");
  var head_meta_description = jQuery('meta[property="og:description"]').attr("content");
  var head_meta_image = jQuery('meta[property="og:image"]').attr("content");
  if(typeof head_meta_url !== 'undefined') {
    head_meta_url = '&p[url]=' + encodeURIComponent(head_meta_url);
  }
  else {
   head_meta_url = '';
  }
  if(typeof head_meta_title !== 'undefined') {
    head_meta_title = '&p[title]=' + encodeURIComponent(head_meta_title);
  }
  else {
   head_meta_title = '';
  }
  if(typeof head_meta_description !== 'undefined') {
    head_meta_description = '&p[summary]=' + encodeURIComponent(head_meta_description);
  }
  else {
   head_meta_description = '';
  }
  if(typeof head_meta_image !== 'undefined') {
    head_meta_image = '&p[images][0]=' + encodeURIComponent(head_meta_image);
  }
  else {
   head_meta_image = '';
  }
  window.open(
    "https://www.facebook.com/sharer/sharer.php?s=100" + head_meta_url + head_meta_title + head_meta_description + head_meta_image,
    "facebook", 
    "width=626,height=436");
    return false;
}
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
