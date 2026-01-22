// 2- Create your box object that contains books objects, ensure that you
// can
// a. count # of books inside box.
// b. delete any of these books in box according to book name or type.
// c. create book object and add it to box object content property
// d. use toString() to tell its dimensions and how books are stores in it.
// e. implement valueof() so that if there is more than one box object we can 
/////// a. get total books in these boxes by adding the i.e. box1 has 5 books while box2 has 2 books, box1+box2 should return 7
// Note:
// • there is no inheritance
// • box object has the following properties: height, width,
// length, numOfBooks, volume, material, content (Array of
// books).
// • The content property contains an array of books.
// • book object has the following properties: title, numofChapters,
// author, numofPages, publisher, numofCopies
// • you can define any function needed for both box and book objects. 

function book(title, numofChapters, author, numofPages, publisher, numofCopies) {
    this.title = title;
    this.numofChapters = numofChapters;
    this.author = author;
    this.numofPages = numofPages;
    this.publisher = publisher;
    this.numofCopies = numofCopies;
}
function box(height, width, length, material) {
    this.height = height;
    this.width = width;
    this.length = length;
    this.material = material;
    this.content = [];
}
box.prototype.numOfBooks = function () {
    return this.content.length;
}
box.prototype.addBook = function (book) {
    this.content.push(book);
}
box.prototype.deleteBook = function (book) {
    for (var i = 0; i < this.content.length; i++) {
        if (this.content[i].title === book || this.content[i].type === book) {
            this.content.splice(i, 1);
            break;
        }
    }

}


var myBox = new box(20, 20, 20, "wood");

var book1 = new book("JS Basics", 12, "Omar", 200, "TechPress", 5);
var book2 = new book("CSS Mastery", 8, "Alice", 150, "DesignBooks", 3);
var book3 = new book("HTML Guide", 10, "Bob", 180, "WebBooks", 4);

myBox.addBook(book1);
myBox.addBook(book2);
myBox.addBook(book3);

console.log(myBox.content);


console.log(myBox.numOfBooks());

myBox.deleteBook("CSS Mastery");

console.log(myBox.numOfBooks());

console.log(myBox.content);








/////////////////////////////////////  d 
box.prototype.toString = function () {
    return `Box dimensions: Height=${this.height}, Width=${this.width}, Length=${this.length}, Material=${this.material}, Number of Books=${this.numOfBooks()}`;
}
console.log(myBox.toString());


/////////////////////////////////////  e
box.prototype.valueOf = function () {
    return this.numOfBooks();
}
var box1 = new box(20, 20, 20, "wood");
var box2 = new box(15, 15, 15, "plastic");
box1.addBook(book1);
box1.addBook(book2);
box2.addBook(book3);
var totalBooks = box1 + box2;
console.log(`Total books in both boxes: ${totalBooks}`);

console.log(box1.valueOf()); // 2 books
console.log(box2.valueOf()); /// 1 books
