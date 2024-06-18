#include <iostream>
#include "Person.h"     // Include the Person header file
#include "Student.h"    // Include the Student header file
using namespace std;

void programDescription() {
    cout << "=================================================================" << endl;
    cout << "\tThis program displays the information of a student." << endl;
    cout << "=================================================================" << endl;
    cout << "  Created by: Francis Reid N. Arranguez | 1-BSCS | CMSC28 - K-3L" << endl;
    cout << "=================================================================" << endl;

}

int main() {
    Student s1;         // Declare a Student object
    string fname, lname, course, department, college, studentnumber;        // Declare variables
    char minitial;                                                    // Declare a variable for the middle initial

    programDescription();

    // Get the first name
    cout << "\nStudent First Name: ";
    getline(cin, fname);
    s1.setFname(fname);

    // Get the middle initial
    cout << "Student Middle Initial: ";
    cin >> minitial;
    s1.setMinitial(minitial);

    // Get the last name
    cout << "Student Last Name: ";
    cin.ignore();
    getline(cin, lname);
    s1.setLname(lname);
    s1.setStudentPerson(Person(fname, minitial, lname));            // Set values for the Person object and pass it to the Student object

    // Get the student number
    cout << "Student Number: ";
    getline(cin, studentnumber);
    s1.setStudentNumber(studentnumber);

    // Get the course
    cout << "Course: ";
    getline(cin, course);
    s1.setCourse(course);

    // Get the department
    cout << "Department: ";
    getline(cin, department);
    s1.setDepartment(department);

    // Get the college
    cout << "College: ";
    getline(cin, college);
    s1.setCollege(college);

    // Display the student information
    cout << "\nStudent Information\n";
    s1.getStudentInfo();
}