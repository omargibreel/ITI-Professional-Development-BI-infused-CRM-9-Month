
import { Shape } from "./shape.js";


export class Rect extends Shape{

    constructor(width, length){
        super()

        this._width = width
        this._length = length
    }

    calcRectArea(){
        return this._length * this._width
    }

    clacRectPreimeter(){
        return (this._length *  this._width) * 2
    }

    toString(){
            console.log(`This is Rect data `);
    console.log(`Rect Area = ${this.calcRectArea()} and Rect preimeter = ${this.clacRectPreimeter()}`);

        
    }
}