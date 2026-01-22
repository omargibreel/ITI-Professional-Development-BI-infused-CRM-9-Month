// 1.String object
// 1.1 Write a script to determine whether the entered string is palindrome or not. Ask the
// user whether to consider case of the entered string or not, handle both cases in your
// script i.e. RADAR NOON MOOM are palindrome.
// Note: raDaR is not a palindrome if user requested considering case of entered string.
// var str
// var caseSensitive
// do {
//     caseSensitive = Number(prompt("please select if you need case sensitive press 0 if you need insensitive press 1"))
//     str = prompt("please enter the str")
// } while (!str || (caseSensitive !== 0 && caseSensitive !== 1));
// if (caseSensitive == 1) {
//     str = str.toLocaleLowerCase();
// }
// str = str.trim()
// var arr = str.split(" ")
// for (let i = 0; i < arr.length; i++) {
//     var word = arr[i]
//     var revers = word.split("").reverse().join("")

//     document.writeln(word + " Is Palindrome ?" + ` ${(word == revers)}` + "<br>")

// }
// 1.2 write a script that accepts a string from user through prompt and count the number of
// ‘e’ characters in it.
// var str
// do {
//     str = prompt("please enter the str")
// } while (!str);
// var ctr = 0
// for (let i = 0; i < str.length; i++) {
//     if (str[i] == "e" || str[i] == "E")
//         ctr++

// }
// document.writeln("count of e in the word = " + ctr)
// 1.3  Write a script that reads from the user his info; validates and displays it with a
// welcoming message.

// var name, phone, mobile, email
// do {
//     name = prompt("Enter your name (letters only):");

// } while (!name || !/^[a-zA-Z\s]+$/.test(name));
// do {
//     phone = prompt("Enter your phone number (8 digits):");

// } while (!/^\d{8}$/.test(phone));
// do {
//     mobile = prompt("Enter your mobile number (11 digits starting with 010, 011, or 012):");
// } while (!/^(010|011|012|015)\d{8}$/.test(mobile));
// do {
//     email = prompt("Enter your email:");
// } while (!/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-z]{2,4}$/.test(email));
// document.writeln(`<h2>Welcome ${name}!</h2>`);
// document.writeln(`<p>Phone Number: ${phone}</p>`);
// document.writeln(`<p>Mobile Number: ${mobile}</p>`);
// document.writeln(`<p>Email: ${email}</p>`);

// 2. Math Object
// 2.1 Write a script that ask the user to Enter the value of a circle’s radius in order to calculate
// its area as shown in fig.


// var r
// do {
//     r = parseFloat(prompt("please enter valid number"))
// } while (isNaN(r));


// document.writeln("hello user the area of your radius = " + Math.PI * r ** 2)
// 2.2 Enter another value to calculate its square root and alert the result as shown in fig.

// var num
// do {
//     num = parseFloat(prompt("please enter valid number"))
// } while (isNaN(num) || num <= 0);
// document.writeln(`the square root of ${num} = ` + Math.sqrt(num))

// 3. Array Object
// 3.1 Fill an array of 3 elements from the user, and apply each of the following mathematical
// operations on it (+, *, /). Format the output as shown in Fig.



var arr = []
flag = 0
for (let i = 0; i < 3; i++) {
    do {
        input = prompt("please enter your number")
        if (input === "") {
            continue;
        }
        if (input === null) {
            arr = []
            flag = 1
            i = 3
            break;

        }
        arr[i] = +Number(input);
        if (i > 0 && arr[i] === 0) {
            alert("zero is not allowed because infinity");
        }
    } while (isNaN(arr[i]));
}
var sum = arr[0], mul = arr[0], div = arr[0]
for (let i = 1; i < arr.length; i++) {
    sum += arr[i]
    mul *= arr[i]
    div /= arr[i]
}
if (flag)
    document.writeln("canceld")
if (arr.length) {
    document.writeln("sum of arr = " + sum + "<br>")
    document.writeln("sum of mul = " + mul + "<br>")
    document.writeln("sum of div = " + div + "<br>")
}


// 3.2 Fill an array of 5 elements from the user, sort it in descending and ascending
// orders then display the output as shown in Fig.



// var arr = []
// var flag = 0
// for (let i = 0; i < 5; i++) {
//     do {
//         input = prompt("please enter your number")
//         if (input === "") {
//             continue;
//         }
//         if (input === null) {
//             arr = []
//             flag = 1
//             i = 5
//             break;

//         }
//         arr[i] = Number(input);
//     } while (isNaN(arr[i]));
// }
// if (flag)
//     document.writeln("canceld")
// if (arr.length) {
//     document.writeln("<p>u've entered the values of : </p> " + arr + "<br>");
//     document.writeln("<p>u've after being sorting descending : </p> " + arr.sort(function (a, b) { return b - a }) + "<br>");
//     document.writeln("<p>u've after being sorting  ascending: </p> " + arr.sort(function (a, b) { return a - b }) + "<br>");

// }
