// 01-Create an interface for a Student with:
// - id (number)
// - name (string)
// - email (string, optional)
// - isActive (boolean)
// - grades (array of numbers)

interface Student {
  id: number;
  name: string;
  email?: string;
  isActive: boolean;
  grades: number[];
}

// 02-Create functions that:
// 1. Add a new student (returns void)
let students: Student[] = [];
function addStudent(student: Student): void {
  students.push(student);
}
// 2. Calculate average grade for a student (returns number)

function calculateAverage(student: Student): number {
  let sum = 0;
  student.grades.forEach((grade) => {
    sum += grade;
  });
  return sum / student.grades.length;
}
// 3. Get student status based on average grade (returns string)
//    - >= 90: "Excellent"
//    - >= 70: "Good"
//    - >= 50: "Average"
//    - < 50: "Needs improvement"

function getStudentStatus(avg: number): string {
  if (avg >= 90) return "Excellent";
  else if (avg >= 70) return "Good";
  else if (avg >= 50) return "Average";
  else return "Needs improvement";
}

// EX:
//  Adding student: Alice Johnson
//  Average grade: 85.75
//  Performance: Good

let student1: Student = {
  id: 1,
  name: "Alice Johnson",
  isActive: true,
  grades: [10, 20, 30],
};

addStudent(student1);

let avg1 = calculateAverage(student1);
console.log(`Average grade: ${avg1}`);
console.log(`Performance: ${getStudentStatus(avg1)}`);

//  Adding student: Bob Smith
// 1 Average grade: 48.33
//  Performance: Needs improvement

let student2: Student = {
  id: 1,
  name: "Alice Johnson",
  isActive: true,
  grades: [40, 50, 60],
};

addStudent(student2);

let avg2 = calculateAverage(student2);
console.log(`Average grade: ${avg2}`);
console.log(`Performance: ${getStudentStatus(avg2)}`);
