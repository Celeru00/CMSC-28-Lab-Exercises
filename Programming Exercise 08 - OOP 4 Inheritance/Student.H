#include <iostream>
#include "Person.h"     // Include the Person header file
using namespace std;

class Student : public Person {     // Declare the Student class and inherit
    private:        // Declare private members
        string studentNum;
    
    public:        // Declare public members
        Person StudentPerson;
        string Course;
        string Department;
        string College;

    public:
        Student() {};       // Default constructor

        Student(string studentNumber, Person studentPerson, string course, string department, string college) {      // Constructor
            studentNum = studentNumber;
            StudentPerson = studentPerson;
            Course = course;
            Department = department;
            College = college;
        }

        void setStudentNumber(string a) {
            studentNum = a;
        }

        void setStudentPerson(Person b) {
            StudentPerson = b;
        }

        void setCourse(string c) {
            Course = c;
        }

        void setDepartment(string d) {
            Department = d;
        }

        void setCollege(string e) {
            College = e;
        }

        string getStudentNumber() {
            return studentNum;
        }

        string getCourse() {
            return Course;
        }

        string getDepartment() {
            return Department;
        }

        string getCollege() {
            return College;
        }

        void getStudentInfo() {
            cout << "=================================================================" << endl;
            cout << "Madayaw, " << StudentPerson.getFullName() << "!" << endl;
            cout << "Welcome to UP Mindanao!"<< endl;
            cout << "\nCongratulations! You are now officially an Iskolar ng Bayan!" << endl;
            cout << "\nWe are pleased to inform you that you are admitted in the\n" << Course << " program\nunder the ";
            cout << Department << ", " << College << "." << "\nYour student number is " << studentNum << "." << endl;
            cout << "=================================================================";
        }
};