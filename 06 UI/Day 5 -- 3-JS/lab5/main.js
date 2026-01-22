// 5. Date Object 
// 1- Make a function that takes date string as a parameter, and returns the Day 
// name (Saturday, Sunday,…) of the given date. 

// function getDayName(_date) {
//     var weekDays = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
//     var day = new Date(_date)
//     return weekDays[day.getDay()];
// }


// var userDate;
// userDate = prompt("Please enter Date in this format MM-DD-YYYY");
// var dayName = getDayName(userDate)

// document.writeln(dayName)

// 4. Function
// 4.1. Create a function that accepts only 2 parameters and throw exception if number of
// parameters either less than or exceeds 2 parameters

// function test(x, y) {
//     if (arguments.length !== 2) {
//         throw new Error("function accepts only 2 parameters");
//     }
//     return x + y;
// }


// document.writeln(test(5, 5))

// 4.2. Write your own function that can add n values ensure that all passing parameters are
// numerical values only
// function sumInt() {
//     var sum = 0
//     for (let i = 0; i < arguments.length; i++) {
//         if (typeof arguments[i] !== "number")
//             throw new Error("function accepts numerical Values");
//         sum += arguments[i]
//     }

//     return sum
// }

// var getsum = sumInt(5, 5, 5, 5, 5)
// document.writeln(getsum)
// 4.3. Write a function that takes any number of parameters and returns them reversed using
// array’s reverse function.
function reverseArr() {
    var sum = 0
    for (let i = arguments.length - 1; i >= 0; i--) {
        if (typeof arguments[i] !== "number")
            throw new Error("function accepts numerical Values");
        document.writeln(arguments[i])
    }

}

reverseArr(1, 2, 3, 4, 5, 6)