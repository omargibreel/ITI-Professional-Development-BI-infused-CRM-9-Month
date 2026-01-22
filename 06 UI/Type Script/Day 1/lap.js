// 01-Create an interface for a Student with:
// - id (number)
// - name (string)
// - email (string, optional)
// - isActive (boolean)
// - grades (array of numbers)
// 02-Create functions that:
// 1. Add a new student (returns void)
var students = [];
function addStudent(student) {
    students.push(student);
}
// 2. Calculate average grade for a student (returns number)
function calculateAverage(student) {
    var sum = 0;
    student.grades.forEach(function (grade) {
        sum += grade;
    });
    return sum / student.grades.length;
}
// 3. Get student status based on average grade (returns string)
//    - >= 90: "Excellent"
//    - >= 70: "Good"
//    - >= 50: "Average"
//    - < 50: "Needs improvement"
function getStudentStatus(avg) {
    if (avg >= 90)
        return "Excellent";
    else if (avg >= 70)
        return "Good";
    else if (avg >= 50)
        return "Average";
    else
        return "Needs improvement";
}
// EX:
//  Adding student: Alice Johnson
//  Average grade: 85.75
//  Performance: Good
var student1 = {
    id: 1,
    name: "Alice Johnson",
    isActive: true,
    grades: [10, 20, 30],
};
addStudent(student1);
var avg1 = calculateAverage(student1);
console.log("Average grade: ".concat(avg1));
console.log("Performance: ".concat(getStudentStatus(avg1)));
//  Adding student: Bob Smith
// 1 Average grade: 48.33
//  Performance: Needs improvement
var student2 = {
    id: 1,
    name: "Alice Johnson",
    isActive: true,
    grades: [40, 50, 60],
};
addStudent(student2);
var avg2 = calculateAverage(student2);
console.log("Average grade: ".concat(avg2));
console.log("Performance: ".concat(getStudentStatus(avg2)));
