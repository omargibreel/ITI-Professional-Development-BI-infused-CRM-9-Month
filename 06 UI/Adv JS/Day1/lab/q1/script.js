// 1. write a script that allows you to create a rectangle object that  
// • Should have width and height properties. 
// • Implement two methods for calculating its area and perimeter return
// value. 
// • Implement displayInfo() function to display a message declaring the
// width, height, area and perimeter of the created object.  


var rectangle = {
    width: Number(prompt("Enter width:")),
    height: Number(prompt("Enter height:")),
    area: function () {
        return this.width * this.height;
    },
    perimeter: function () {
        return 2 * (this.width + this.height);
    },
    displayInfo: function () {
        document.writeln(`Rectangle with width ${this.width} and height ${this.height} has area ${this.area()} and perimeter ${this.perimeter()}.`);
    }
}

rectangle.area();
rectangle.perimeter();
rectangle.displayInfo();    