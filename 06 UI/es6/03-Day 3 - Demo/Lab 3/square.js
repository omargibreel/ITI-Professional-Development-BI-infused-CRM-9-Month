import { Shape } from './shape.js';

export class Square extends Shape {
  constructor(width) {
    super();
    this._width = width;
  }

  calcSquareArea() {
    return this._width * this._width;
  }
  calcSquarePerimeter() {
    return 4 * this._width;
  }

  toString() {
    console.log(`This is square data `);

    console.log(`Squre Area = ${this.calcSquareArea()} and Square preimeter = ${this.calcSquarePerimeter()}`);
  }
}
