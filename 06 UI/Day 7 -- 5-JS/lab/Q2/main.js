var nameInput = document.getElementById('nameInput');
var emailInput = document.getElementById('emailInput');
var ageInput = document.getElementById('ageInput');
var form = document.querySelector("form");

var nameInputSpan = document.getElementById('nameInputSpan');
var ageInputSpan = document.getElementById('ageInputSpan');
var emailInputSpan = document.getElementById('emailInputSpan');
var emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
var nameFlag = false;
var ageFlag = false;
var emailFlag = false;
nameInput.addEventListener("blur", function () {
    if (nameInput.value == "")
        nameInputSpan.textContent = 'This Field Is Required!';
    else if (nameInput.value.length < 3 || nameInput.value.length > 15)
        nameInputSpan.textContent = 'Name Must Be between 3 and 15 charachters';
    else {
        nameInputSpan.textContent = '';
        nameFlag = true
    }
})

ageInput.addEventListener("blur", function () {
    if (ageInput.value == "")
        ageInputSpan.textContent = 'This Field Is Required!';
    else if (!isFinite(+ageInput.value))
        ageInputSpan.textContent = 'Only Numeric Values Are Allowed';
    else if (+ageInput.value < 18 || +ageInput.value > 60)
        ageInputSpan.textContent = 'Age Must Be between 18 and 60 years';
    else {
        ageInputSpan.textContent = '';
        ageFlag = true
    }
})

emailInput.addEventListener("blur", function () {
    if (emailInput.value == '')
        emailInputSpan.textContent = 'This Field Is Required!';
    else if (!emailRegex.test(emailInput.value))
        emailInputSpan.textContent = 'Invalid Email Format';
    else {
        emailInputSpan.textContent = '';
        emailFlag = true
    }

})

var tableBody = document.querySelector("tbody");

form.addEventListener("submit", function (e) {
    e.preventDefault();
    if (!nameFlag) {
        nameInputSpan.textContent = 'This Field Is Required!';
    }
    if (!ageFlag) {
        ageInputSpan.textContent = 'This Field Is Required!';
    }
    if (!emailFlag) {
        emailInputSpan.textContent = 'This Field Is Required!';
    }
    if (nameFlag && ageFlag && emailFlag) {
        var newRow = document.createElement("tr");
        var nameCell = document.createElement("td");
        nameCell.textContent = nameInput.value;
        var ageCell = document.createElement("td");
        ageCell.textContent = ageInput.value;
        var emailCell = document.createElement("td");
        emailCell.textContent = emailInput.value;
        newRow.appendChild(nameCell);
        newRow.appendChild(ageCell);
        newRow.appendChild(emailCell);
        tableBody.appendChild(newRow);
        form.reset();
        nameFlag = ageFlag = emailFlag = false;
    }
});





