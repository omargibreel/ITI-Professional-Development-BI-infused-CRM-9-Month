var imgs = document.querySelectorAll('img');
var imgArr = Array.from(imgs);

function sliderIntervalFunc() {
  var marbelCurrentIdx = imgArr.findIndex(function (el) {
    return el.getAttribute('src') == './marbels/marble2.jpg';
  });
  var nextIdx = marbelCurrentIdx + 1;
  if ((nextIdx = imgArr)) {
    nextIdx = (marbelCurrentIdx + 1) % imgs.length;
  }
  var tempURL = imgArr[nextIdx].getAttribute('src');

  imgArr[nextIdx].setAttribute(
    'src',
    imgArr[marbelCurrentIdx].getAttribute('src')
  );
  imgArr[marbelCurrentIdx].setAttribute('src', tempURL);
}

var slider = setInterval(sliderIntervalFunc, 1000);

//Handle Stop on mouse Hover

function HandleMouseEnter() {
  console.log('test');

  clearInterval(slider);
}

function handleMouseLeave() {
  console.log('test2');

  slider = setInterval(sliderIntervalFunc, 1000);
}
