// Js OOP
// 1. Display the area and perimeter of an object created from using Rectangle
// Constructor that has width and height properties and 2 methods (using
// prototype property) for calculating area, perimeter.
// a. Override toString() function to display a message declaring the width,
// height, area and perimeter of the created object.
// b. Create Class Property that counts numbers of created objects and
// Class method to retrieve it.
// 2. Make proper updates in your previous code of generating Rectangle object that
// should inherit from Shape Constructor, and create your Square constructor
// that inherits from Rectangle. Prevent creating any object from shape, allow
// creation of only rectangles and square
// Bonus: allow creation of only one square and one rectangle.

function Shape() {
    if (this.constructor === Shape) {
        throw new Error("Cannot create instance of abstract class Shape");
    }
}
function Rectangle(width, height) {
    Shape.call(this);
    this.width = width;
    this.height = height;
    Rectangle.objectCount = (Rectangle.objectCount || 0) + 1;
}

Rectangle.prototype = Object.create(Shape.prototype);
Rectangle.prototype.constructor = Rectangle;
Rectangle.prototype.area = function () {
    return this.width * this.height;
};
Rectangle.prototype.perimeter = function () {
    return 2 * (this.width + this.height);
};
Rectangle.prototype.toString = function () {
    return `Rectangle: width=${this.width}, height=${this.height}, area=${this.area()}, perimeter=${this.perimeter()}`;
};
Rectangle.getObjectCount = function () {
    return Rectangle.objectCount || 0;
};
function Square(width) {
    Rectangle.call(this, width, width);
    Square.objectCount = (Square.objectCount || 0) + 1;
}
Square.prototype = Object.create(Rectangle.prototype);
Square.prototype.constructor = Square;
Square.getObjectCount = function () {
    return Square.objectCount || 0;
};
Square.prototype.toString = function () {
    return `Square: width=${this.width}, area=${this.area()}, perimeter=${this.perimeter()}`;
}

console.log(new Rectangle(4, 5).toString());

console.log(new Square(4).toString());

console.log(Square.getObjectCount());
console.log(Rectangle.getObjectCount());

