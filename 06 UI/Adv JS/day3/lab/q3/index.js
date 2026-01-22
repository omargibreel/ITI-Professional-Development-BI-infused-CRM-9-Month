function register() {
    var name = document.getElementById("nameInp").value;
    var age = document.getElementById("ageInp").value;
    var color = document.getElementById("colorInp").value;

    var genderElements = document.getElementsByName("gen");
    var gender = "male"; // Default
    for (var i = 0; i < genderElements.length; i++) {
        if (genderElements[i].checked) {
            gender = genderElements[i].value;
        }
    }

    if (name === "") {
        alert("Please enter your name");
        return;
    }

    cookieLib.setCookie("uName", name);
    cookieLib.setCookie("uColor", color);
    cookieLib.setCookie("uGender", gender);
    cookieLib.setCookie("uVisits", "0");

    window.location.href = "profile.html";
}