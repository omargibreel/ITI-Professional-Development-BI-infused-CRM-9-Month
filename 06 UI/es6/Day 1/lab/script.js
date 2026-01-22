// ES6 lab Day 1 
// 1) Swap the values of two variables using destructuring 
let a = 5;
let b = 10;
console.log(a, b);
[a, b] = [b, a];
console.log(a, b);
// 2) Using rest parameter and spread operator return max value from any array
// note: array length is not fixed return min and max value and display each of
// them separately after function call
function findMinMax(...numbers) {
    let min = Math.min(...numbers);
    let max = Math.max(...numbers);
    return { min, max };
}


let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let { min, max } = findMinMax(...arr);
console.log('min number = ', min);
console.log('max number = ', max);

let { min1, max1 } = findMinMax(1, 5, 9, 8, 7, 26, 2, 4, 5, 8);
console.log('min number = ', min1);
console.log('max number = ', max1);

// 3) Study new array api methods then create the following methods and apply
// it on this array var fruits = ["apple", "strawberry", "banana", "orange",
// "mango"]



// Create an Array
const ages = [32, 33, 16, 40];

// Create a Test Function
function checkAge(age) {
    return age > 18;
}

// Are all ages over 18?

console.log(ages.every(checkAge));

let fruits = ["apple", "strawberry", "banana", "orange", "mango"];
// a. test that every element in the given array is a string
console.log(fruits.every((fruit) => {
    return typeof fruit === 'string';
}));

// b. test that some of array elements starts with "a"
console.log(fruits.some((fruit) => {
    return fruit.startsWith('a');
}));
// c. generate new array filtered from the given array with only elements that
// starts with "b" or "s"
let newFruitsArr = fruits.filter((fruit) => {
    return fruit.startsWith('b') || fruit.startsWith('s');
});
console.log(newFruitsArr);
// d. generate new array each element of the new array contains a string
// declaring that you like the give fruit element
let newArr = fruits.map((fruit) => {
    return `I like ${fruit}`;
});
console.log(newArr);
// e. use forEach to display all elements of the new array from previous point 
newArr.forEach((fruit) => {
    console.log(fruit);
});