var progress = document.getElementById("progress");
var song = document.getElementById("song");
var ctrlIcon = document.getElementById("ctrlIcon");
var songs = [{ name: "super Mario", src: "songs/song1/Super Mario Bros (NES) Music - Overworld Theme.mp3", img: "songs/song1/supermario.jpg" },
{ name: "Lose You To Love Me", src: "songs/song2/Selena_Gomez_-_Lose_You_To_Love_Me_(mp3.pm).mp3", img: "songs/song2/Selena_Gomez_-_Lose_You_To_Love_Me.jpg" }
    ,
{ name: "Lose You To Love Me", src: "songs/song2/Selena_Gomez_-_Lose_You_To_Love_Me_(mp3.pm).mp3", img: "songs/song2/Selena_Gomez_-_Lose_You_To_Love_Me.jpg" }]
var songIndex = 0
var nextBtn = document.getElementById("next");
var prevBtn = document.getElementById("prev");


function loadSong(index) {
    song.src = songs[index].src;
    document.querySelector("h1").innerText = songs[index].name;
    document.querySelector(".song-img").src = songs[index].img;

    song.load();
    song.play();

    var icon = ctrlIcon.querySelector("i");
    icon.classList.remove("fa-play");
    icon.classList.add("fa-pause");
}


nextBtn.addEventListener("click", function () {
    songIndex++;
    if (songIndex >= songs.length) {
        songIndex = 0;
    }
    loadSong(songIndex);
});

prevBtn.addEventListener("click", function () {
    songIndex--;

    if (songIndex < 0) {
        songIndex = songs.length - 1;
    }

    loadSong(songIndex);
});
song.onloadedmetadata = function () {
    progress.max = song.duration;
    progress.value = song.currentTime;
};

ctrlIcon.addEventListener("click", function () {
    var icon = ctrlIcon.querySelector("i");

    if (icon.classList.contains("fa-pause")) {
        song.pause();
        icon.classList.remove("fa-pause");
        icon.classList.add("fa-play");
    } else {
        song.play();
        icon.classList.remove("fa-play");
        icon.classList.add("fa-pause");
    }
});

song.ontimeupdate = function () {
    progress.value = song.currentTime;
};

progress.addEventListener("input", function () {
    var icon = ctrlIcon.querySelector("i");

    song.currentTime = progress.value;
    song.play();

    icon.classList.remove("fa-play");
    icon.classList.add("fa-pause");
});
