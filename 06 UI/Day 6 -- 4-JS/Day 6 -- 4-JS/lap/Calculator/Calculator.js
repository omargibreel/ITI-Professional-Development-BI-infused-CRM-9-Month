var screen = document.querySelector('.screen');
var buttons = document.querySelectorAll('button');
var currentInput = '';

for (var i = 0; i < buttons.length; i++) {
    buttons[i].addEventListener('click', function () {
        value = this.value;
        if (value === 'c') {
            currentInput = '';
            screen.textContent = '';
        } else if (value === '=') {
            try {
                currentInput = eval(currentInput);
                screen.textContent = currentInput;
            } catch (e) {
                screen.textContent = 'Error';
                currentInput = '';
            }
        } else {
            currentInput += value;
            screen.textContent = currentInput;
        }
    });
}
