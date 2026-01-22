// 1- Complete First day`s task 
// var user = { name:”Ali”,age:10}  
// When applying getSetGen() on user object (you can use call or  
// bind or apply), it will result in creating the following:   
// getName(), getAge(), setName(), setAge() 


var user = {
    name: 'Omar',
    age: 22,

};

function getSetGen() {
    var arrEntries = Object.entries(this)
    for (var i = 0; i < arrEntries.length; i++) {
        if (typeof arrEntries[i][1] !== "function") {
            (function () {
                var data = arrEntries[i][1];
                Object.defineProperty(user, "Get" + `${arrEntries[i][0]}`, {
                    value: function () {
                        return data;
                    },
                    configurable: false,
                    enumerable: true
                });
                Object.defineProperty(user, "Set" + `${arrEntries[i][0]}`, {
                    value: function (value) {
                        data = value;
                    }, configurable: false,
                    enumerable: true
                });
            })();
        }
    }
}

getSetGen.call(user);
console.log(user.Getname());
console.log(user.Setname("Ali"))
console.log(user.Getage());
console.log(user.Getname());
console.log(user);

