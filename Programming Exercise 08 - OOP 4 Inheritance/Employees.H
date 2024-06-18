#include <iostream>
#include "Person.h"     // Include the Person header file
using namespace std;

class Employees : public Person {       // Declare the Employees class and inherit
    private:             // Declare private members
        string EmployeeNumber;
    
    protected:          // Declare protected members
        Person EmployeePerson;
        string Position;
        string Office;
        double Salary;

    public:
        Employees() {};         // Default constructor
        
        Employees(string employeeNumber, Person employeePerson, string position, string office, double salary) {     // Constructor
            EmployeeNumber = employeeNumber;
            EmployeePerson = employeePerson;
            Position = position;
            Office = office;
            Salary = salary;
        }

        void setEmployeeNumber(string a) {
            EmployeeNumber = a;
        }

        void setEmployeePerson(Person b) {
            EmployeePerson = b;
        }

        void setPosition(string c) {
            Position = c;
        }

        void setOffice(string d) {
            Office = d;
        }

        void setSalary(float e) {
            Salary = e;
        }

        string getEmployeeNumber() {
            return EmployeeNumber;
        }

        string getPosition() {
            return Position;
        }

        string getOffice() {
            return Office;
        }

        double getSalary() {
            return Salary;
        }

        string getEmployeePerson() {
            return EmployeePerson.getFullName();        // Call the getFullName function from the Person class
        }

        void displayEmployeeInformation() {
            cout << "=================================================================" << endl;
            cout << "Employee Information" << endl;
            cout << "=================================================================" << endl;
            cout << "Dear " << EmployeePerson.getFullName() << "," << endl;
            cout << "\nWe are pleased to inform you that you have been hired as a" << endl;
            cout << Position << " in the " << Office << " office." << endl;
            cout << "Your employee number is " << EmployeeNumber << "." << endl;
            cout << "Your monthly salary is Php " << Salary << "." << endl;
            cout << "=================================================================" << endl;
        }
};