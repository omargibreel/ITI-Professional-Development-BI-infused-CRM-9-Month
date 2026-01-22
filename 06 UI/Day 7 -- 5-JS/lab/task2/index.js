var nameInput = document.getElementById('nameInput');
var emailInput = document.getElementById('emailInput');
var ageInput = document.getElementById('ageInput');

var nameInputSpan = document.getElementById('nameInputSpan');
var ageInputSapn = document.getElementById('ageInputSapn');
var emailInputSapn = document.getElementById('emailInputSapn');

var form = document.querySelector('form');
var spans = document.querySelectorAll('span');
var inputs = document.querySelectorAll('input');

var emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

var nameFlag = false;
var ageFlag = false;
var emailFlag = false;

//Handle Name Input Validation
function handleNameInput() {
  if (nameInput.value == '') {
    nameInputSpan.textContent = 'This Field Is Required!';
  } else if (nameInput.value.length < 2 || nameInput.value > 10) {
    nameInputSpan.textContent = 'Name Must Be between 2 and 10 charachters';
  } else {
    nameFlag = true;
    nameInputSpan.textContent = '';
  }
}

//Handle Age Input Validation
function handleAgeInput() {
  if (ageInput.value == '') {
    ageInputSapn.textContent = 'This Field Is Required!';
  } else if (!isFinite(ageInput.value)) {
    ageInputSapn.textContent = 'Only Numeric Values Are Allowed';
  } else if (ageInput.value < 18 || ageInput.value.length > 60) {
    ageInputSapn.textContent = 'Age Must Be between 18 and 60 years';
  } else {
    ageFlag = true;
    ageInputSapn.textContent = '';
  }
}

//Handle Email Validation
function handleEmailInput() {
  if (emailInput.value == '') {
    emailInputSapn.textContent = 'This Field Is Required!';
  } else if (!emailRegex.test(emailInput.value)) {
    emailInputSapn.textContent = 'Invalid Email Format';
  } else {
    emailFlag = true;
    emailInputSapn.textContent = '';
  }
}

///Handle form Submit////

var tableBody = document.querySelector('tbody');

// //we WIll make a for each loop and for each input we will run
form.addEventListener('submit', function (e) {
  if (nameFlag && emailFlag && ageFlag) {
    e.preventDefault();
    var tableRow = document.createElement('tr');
    var nameTd = document.createElement('td');
    var ageTd = document.createElement('td');
    var emailTd = document.createElement('td');
    nameTd.textContent = nameInput.value;
    tableRow.appendChild(nameTd);
    ageTd.textContent = ageInput.value;
    tableRow.appendChild(ageTd);
    emailTd.textContent = emailInput.value;
    tableRow.appendChild(emailTd);

    tableBody.appendChild(tableRow);

    form.reset();
    nameFlag = false;
    ageFlag = false;
    emailFlag = false;
  } else {
    inputs.forEach((element, index) => {
      if (element.value == '') {
        e.preventDefault();
        spans[index].textContent = 'This Field Is Required!';
      }
    });
  }
});
