var myDiv = document.getElementById("my-div")
myDiv.addEventListener("click", function () {
    var clone = myDiv.cloneNode(true);
    clone.style.backgroundColor = ` rgb(${Math.floor(Math.random() * 256)},${Math.floor(Math.random() * 256)},${Math.floor(Math.random() * 256)})`
    console.log(clone);

    myDiv.after(clone)

})