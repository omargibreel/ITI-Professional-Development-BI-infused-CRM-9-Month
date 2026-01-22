header = document.getElementById("header");
navigation = document.getElementById("navigation");
clone = header.cloneNode(true);
header.style.textAlign = "right"

document.body.appendChild(clone)
navigation.style.display = "flex";
navigation.style.justifyContent = "center";
navigation.style.textAlign = "center"

