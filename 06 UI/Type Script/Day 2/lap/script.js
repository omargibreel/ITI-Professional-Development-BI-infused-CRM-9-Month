var counterValue = document.getElementById("counterValue");
var increaseBtn = document.getElementById("increaseBtn");
var decreaseBtn = document.getElementById("decreaseBtn");
var resetBtn = document.getElementById("resetBtn");
var Counter = /** @class */ (function () {
    function Counter(num) {
        if (num === void 0) { num = 0; }
        this.value = num;
    }
    Counter.prototype.increase = function () {
        this.value++;
    };
    Counter.prototype.decrease = function () {
        this.value--;
    };
    Counter.prototype.reset = function () {
        this.value = 0;
    };
    Counter.prototype.getValue = function () {
        return this.value;
    };
    return Counter;
}());
var counter = new Counter(0);
function display() {
    counterValue.innerHTML = counter.getValue();
}
increaseBtn.addEventListener("click", function () {
    counter.increase();
    display();
});
decreaseBtn.addEventListener("click", function () {
    counter.decrease();
    display();
});
resetBtn.addEventListener("click", function () {
    counter.reset();
    display();
});
