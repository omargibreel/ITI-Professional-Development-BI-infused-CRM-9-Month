/**
 * Okay first we need to apply the next and previous fucntionality
 * ( we will have an array of URLs and apply a click event for each button that chage the url in the html tag to the next or previous url (indexOf(currentUrl) + 1) )
 *
 */

var urlArr = [
  'SlideShow/1.jpg',
  'SlideShow/2.jpg',
  'SlideShow/3.jpg',
  'SlideShow/4.jpg',
  'SlideShow/5.jpg',
  'SlideShow/6.jpg',
];

var nextButton = document.querySelector('.Next');
var previousButton = document.querySelector('.Previous');
var SlideShowButton = document.querySelector('.SlideShow');
var StopButton = document.querySelector('.Stop');
var img = document.getElementById('img');

var myInterval;
var sliderFlag = false;

///Next Img Functionality
function nextBtn() {
  var imgURL = document.getElementById('img').getAttribute('src');
  var currentIdx = urlArr.indexOf(imgURL);
  var nextIdx = currentIdx + 1;

  //   if (sliderFlag) {  
  //     clearInterval(myInterval);
  //     sliderFlag = false
  //   }

  if (currentIdx == 5) {
    nextIdx = 0;
  }

  img.setAttribute('src', urlArr.at(nextIdx));
}

function prevBtn() {
  //Previous Btn

  var imgURL = document.getElementById('img').getAttribute('src');
  var currentIdx = urlArr.indexOf(imgURL);
  var previousIdx = currentIdx - 1;

  //   if (sliderFlag) {
  //     clearInterval(myInterval);
  //     sliderFlag = false
  //   }

  if (currentIdx == 0) {
    previousIdx = 5;
  }
  img.setAttribute('src', urlArr.at(previousIdx));
}

// now i want when i press next to change the url of the image to the indexOf current url + 1

//////////////

//Slide Show Functionlaity

SlideShowButton.addEventListener('click', function () {
  sliderFlag = true;
  myInterval = setInterval(function () {
    nextBtn();
  }, 1000);
});

// Stop Functionality

StopButton.addEventListener('click', function () {
  sliderFlag = false;
  clearInterval(myInterval);
});
