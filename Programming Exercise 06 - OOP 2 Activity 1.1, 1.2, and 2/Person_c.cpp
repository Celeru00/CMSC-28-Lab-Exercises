#include <iostream>
#include "Person.h"
#include "Grade.h"
using namespace std;

int main()
{
    int grade, age;
    char gender;
    string subject;

    system("cls");
    do {
        cout << "Enter age: ";
        cin >> age;
        if (age < 0) {
            cout << "Invalid age!" << endl;
        }
    } while (age < 0);

    cout << "Enter gender (M or F): ";
    cin >> gender;

    Person c(age, gender);
    c.setage(age);
    c.setgender(gender);

    cout << "Enter subject: ";
    cin.ignore( );
    getline(cin, subject);

    do {
        cout << "Enter grade: ";
        cin >> grade;
        if (grade < 0 || grade > 100) {
            cout << "Invalid grade!" << endl;
        }
    } while (grade < 0 || grade > 100);
    
    Grades g(subject, grade);
    g.setGrade(grade);

    cout << "\n======================================================" << endl;
    cout << "Person's age is " << c.getage() << " and gender is " << c.getgender() << "." << endl;
    cout << "The grade for " << g.getSubject() << " is " << g.getGrade() << "." << endl;
    if (g.getGrade() >= 60) {
        cout << "Congratulations! You passed the subject." << endl;
    } else {
        cout << "Sorry, you failed the subject." << endl;
    }
    cout << "======================================================" << endl;
    return 0;
}