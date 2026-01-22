let counterValue = document.getElementById("counterValue");
let increaseBtn = document.getElementById("increaseBtn") ;
let decreaseBtn = document.getElementById("decreaseBtn");
let resetBtn = document.getElementById("resetBtn");

class Counter {
  private value: number;

  constructor(num: number = 0) {
    this.value = num;
  }

  increase(): void {
    this.value++;
  }

  decrease(): void {
    this.value--;
  }

  reset(): void {
    this.value = 0;
  }

  getValue(): number {
    return this.value;
  }
}

let counter = new Counter(0);

function display(): void {
  counterValue!.innerHTML = `${counter.getValue()}`;
}

increaseBtn!.addEventListener("click", () => {
  counter.increase();
  display();
});

decreaseBtn!.addEventListener("click", () => {
  counter.decrease();
  display();
});

resetBtn!.addEventListener("click", () => {
  counter.reset();
  display();
});
