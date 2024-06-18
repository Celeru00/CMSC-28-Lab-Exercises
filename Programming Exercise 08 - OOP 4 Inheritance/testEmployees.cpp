#include <iostream>
#include "Person.h"         // Include the Person header file
#include "Employees.h"      // Include the Employees header file

void programDescription() {
    cout << "=================================================================" << endl;
    cout << "\tThis program displays the information of an employee." << endl;
    cout << "=================================================================" << endl;
    cout << "  Created by: Francis Reid N. Arranguez | 1-BSCS | CMSC28 - K-3L" << endl;
    cout << "=================================================================" << endl;

}

int main() {
    Employees e1;         // Declare an Employees object
    double salary;
    string fname, lname, position, office, employeeNumber;
    char minitial;

    programDescription();

    // Get the first name
    cout << "\nEmployee First Name: ";
    getline(cin, fname);
    e1.setFname(fname);

    // Get the middle initial
    cout << "Employee Middle Initial: ";
    cin >> minitial;
    e1.setMinitial(minitial);

    // Get the last name
    cout << "Employee Last Name: ";
    cin.ignore();
    getline(cin, lname);
    e1.setLname(lname);
    e1.setEmployeePerson(Person(fname, minitial, lname));            // Set values for the Person object and pass it to the Employees object

    // Get the employee number
    cout << "Employee Number: ";
    getline(cin, employeeNumber);
    e1.setEmployeeNumber(employeeNumber);

    // Get the position
    cout << "Position: ";
    getline(cin, position);
    e1.setPosition(position);

    // Get the office
    cout << "Office: ";
    getline(cin, office);
    e1.setOffice(office);

    // Get the salary
    cout << "Salary: ";
    cin >> salary;
    e1.setSalary(salary);

    // Display the employee information
    e1.displayEmployeeInformation();
}