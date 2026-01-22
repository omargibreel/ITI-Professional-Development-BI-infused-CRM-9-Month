// 2. Create your own custom object that has getSetGen as function value, this
// function should generate setters and getters for the properties of the caller
// object This object may have description property of string value if needed
// Let any other created object can use this function property to generate
// getters and setters for his own properties Avoid generating getters or
// setters for property of function value
// Hint:
// if getSetGen() applied on any other object it should generate getters and setters
// for all of the applied object properties.
// i.e. if you have the following object
// obj = {id:”SD-10”,location:”SV”, addr:”123 st.”, getSetGen:
// function(){/*should be implemented*/}}
// using of getSetGen() will generate the following getId(), setId(), getLocation(),
// setLocation(), getAddr(), setAddr().
// If you created the following object
// var user = { name:”Ali”,age:10} 



// var person = {
//     fName: 'omar',
//     lName: 'osama',
//     age: 22,
//     city: 'cairo',
//     getSetGen: function () {
//         var arrEntries = Object.entries(this)
//         for (var i = 0; i < arrEntries.length; i++) {
//             if (typeof arrEntries[i][1] !== "function") {
//                 (function () {
//                     var data = arrEntries[i][1];
//                     Object.defineProperty(person, `${arrEntries[i][0]}`, {
//                         get: function () {
//                             return data;
//                         },
//                         set: function (value) {
//                             data = value;
//                         },
//                         configurable: false,
//                         enumerable: true
//                     });
//                 })();
//             }
//             console.log(Object.getOwnPropertyDescriptor(this, `${arrEntries[i][0]}`));
//         }
//     }
// }
// person.getSetGen()
// console.log(person.fName);



var person = {
    fName: 'omar',
    lName: 'osama',
    age: 22,
    city: 'cairo',
    getSetGen: function () {
        var arrEntries = Object.entries(this)
        for (var i = 0; i < arrEntries.length; i++) {
            if (typeof arrEntries[i][1] !== "function") {
                (function () {
                    var data = arrEntries[i][1];
                    Object.defineProperty(person, "Get" + `${arrEntries[i][0]}`, {
                        value: function () {
                            return data;
                        },
                        configurable: false,
                        enumerable: true
                    });
                    Object.defineProperty(person, "Set" + `${arrEntries[i][0]}`, {

                        value: function (value) {
                            data = value;
                        },
                        configurable: false,
                        enumerable: true
                    });
                })();
            }
            console.log(Object.getOwnPropertyDescriptor(this, `${arrEntries[i][0]}`));
        }
    }
}


person.getSetGen()

console.log(person.GetfName());

// var person = {
//     fName: 'omar',
//     lName: 'osama',
//     age: 22,
//     city: 'cairo',
//     getSetGen: function () {
//         var arrEntries = Object.entries(this)
//         for (var i = 0; i < arrEntries.length; i++) {
//             if (typeof arrEntries[i][1] !== "function") {
//                 (function () {
//                     var data = arrEntries[i][1];
//                     Object.defineProperty(this, "Get" + `${arrEntries[i][0]}`, {
//                         get: function () {
//                             return data;
//                         },
//                         configurable: false,
//                         enumerable: true
//                     });
//                     Object.defineProperty(this, "Set" + `${arrEntries[i][0]}`, {
//                         set: function (value) {
//                             data = value;
//                         },
//                         configurable: false,
//                         enumerable: true
//                     });
//                 }).call(this);
//             }
//         }
//     }
// }

// person.getSetGen();

// console.log(person.GetfName);
// console.log(person.GetlName);
// console.log(person.Getage);


