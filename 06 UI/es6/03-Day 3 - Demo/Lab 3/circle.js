import { Shape } from './shape.js';

export class Circle extends Shape {
  constructor(radius) {
    super();
    this._radius = radius;
  }

  calcCircleArea() {
    return Math.PI * (this._radius * this._radius);
  }
  calcCirclePerimeter() {
    return 2 * Math.PI * this._radius ;
  }

  toString() {
    console.log(`This is circle data `);
    
    console.log(`circle Area = ${this.calcCircleArea()} and circle preimeter = ${this.calcCirclePerimeter()}`);

  }
}
