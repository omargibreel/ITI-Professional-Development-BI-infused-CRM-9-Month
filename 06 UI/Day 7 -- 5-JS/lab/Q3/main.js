var imgArr = document.querySelectorAll("img")
console.log(imgArr);

var index = 0

imgArr[0].src = "marbels/marble2.jpg"

var intervalId = setInterval(function () {
    imgArr[index].src = "marbels/marble1.jpg";
    index++;
    if (index == imgArr.length) {

        index = 0
    }
    imgArr[index].src = "marbels/marble2.jpg";


}, 500)

imgArr.forEach((marble) => {
    marble.addEventListener("mouseenter", () => {
        clearInterval(intervalId);
    })

    marble.addEventListener("mouseleave", () => {
        intervalId = setInterval(function () {

            imgArr[index].src = "marbels/marble1.jpg";
            index++;
            if (index % imgArr.length == 0)
                index = 0

            imgArr[index].src = "marbels/marble2.jpg"
        }, 500)
    })
}


);