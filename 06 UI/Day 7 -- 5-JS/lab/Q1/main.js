var images = [
    "SlideShow/1.jpg",
    "SlideShow/2.jpg",
    "SlideShow/3.jpg",
    "SlideShow/4.jpg",
    "SlideShow/5.jpg",
    "SlideShow/6.jpg",
];

var img = document.querySelector("img");

var nextBtn = document.getElementById("Next");
var prevBtn = document.getElementById("previous");
var slideBtn = document.getElementById("Slide");
var stopBtn = document.getElementById("Stop");

var index = 0;
var intervalId = null;

nextBtn.addEventListener("click", function () {
    index++;
    if (index == images.length)
        index = 0;
    img.src = images[index];
});

prevBtn.addEventListener("click", function () {
    if (index == 0) {
        index = images.length;
    }
    index--;
    img.src = images[index];
});

slideBtn.addEventListener("click", function () {
    if (intervalId !== null) return;
    // عشان اتاكد ان مفيش set time
    // شغاله عشان كان بيزود السرعه ف لو شايل قيمه اطلع 
    intervalId = setInterval(function () {
        index++;
        if (index === images.length) {
            index = 0;
        }
        img.src = images[index];
    }, 2000);
    // nextBtn.addEventListener("click", function () {
    // فكرت اعمل call لل next بدل ما اكتب نفس الكود تاني بس مش نافع 
});

stopBtn.addEventListener("click", function () {
    clearInterval(intervalId);
    intervalId = null;
});
