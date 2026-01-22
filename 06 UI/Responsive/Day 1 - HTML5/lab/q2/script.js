var canvas = document.querySelector("#myCanvas");
var ctx = canvas.getContext("2d");
var btn = document.querySelector("#btn");
var color = document.querySelector("#color");
canvas.width = 800;
canvas.height = 400;

function Draw() {


    ctx.clearRect(0, 0, canvas.width,
        canvas.height
    )
    for (let i = 0; i < 50; i++) {
        var x = Math.random() * canvas.width
        var y = Math.random() * canvas.height
        var radius = Math.random() * 50

        ctx.beginPath();

        ctx.strokeStyle = color.value
        ctx.arc(x, y, radius, 0, 2 * Math.PI);
        ctx.stroke();
    }

}
btn.addEventListener("click", Draw);
