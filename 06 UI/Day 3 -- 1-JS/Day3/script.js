// JavaScript Day1
// 1- Try the following piece and write the answer
// a)
// var y;
// console.log(y);  // undefined


// b)
// console.log(y);  // not defined


// c)
// var x = 10;
// var y = 20;
// console.log(y * x - 2); // 198
// d)
// var y;
// console.log(typeof y); // undefine
// e)
// var x = "1";
// var y = 2;
// console.log(x + y); // 12
// f)
// var x = 1;
// var y = true;
// console.log(x + y); //will be 1+1


//// 2- Ask the user to enter a message then display it using the different html
//// heading tags (from <h1> to <h6>) using Loops. DO NOT write the header
//// element explicitly in your script!
var userMes
console.log(userMes)
do {
    userMes = prompt("hello please enter message")
} while (userMes == "" || userMes == undefined);
for (let i = 1; i <= 6; i++) {
    document.write(`<h${i}> ${userMes} <h${i}>`)
}


// 3- Write a script that takes from the user n values and returns their sum, stop
// receiving values from user whe
// n he enters 0 or sum exceeds 100,sd check tha0t
// the entered data is numeric and inform the user with the total sum of the
// entered values.

// var sum = 0
// var input
// do {
//     input = prompt("enter valid number")
//     if (input == '' || input == null)
//         continue
//     if (+input) {
//         sum += Number(input)
//     }
//     if (Number(input) == 0) break

//     console.log(input);

//     console.log(sum);

// } while (sum <= 100);


// 4- On contact page prompt user to enter his name, make sure that name is string,
// and let the user enter his birth year and make sure that it is a number, and it is
// less than 2010, and then calculate his age. For each prompt if user input valid
// show him next prompt, if not valid show him the same prompt again until user
// enters it correctly (use loops). And after validating user input, write all user
// input on the page in that format:
// Name: ahmed
// Birth year: 1981
// Age: 30

// var uName
// var year
// var age

// do {
//     uName = prompt("please enter valid name")

// } while (!isNaN(uName));


// do {
//     year = prompt("please enter year is less than 2010")


// } while (year >= 2010 || year < 1950);


// age = 2026 - year

// document.write(`<h1>name: ${uName}<h1>
//   <h1>  year of birth : ${year}<h1>
//    <h1> age = ${age}<h1>`)

