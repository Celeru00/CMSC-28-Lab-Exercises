#include <iostream>
using namespace std;

class Grades {
    private:
        string Subject;
        int Grade;
    
    public:
    Grades (string subject, int grade) {
        Subject = subject;
        Grade = grade;
    }

    void setGrade(int grade) {
        if (grade >= 0 && grade <= 100) {
            Grade = grade;
        } else {
            cout << "Invalid grade!" << endl;
        }
    }

    string getSubject() {
        return Subject;
    }

    int getGrade() {
        return Grade;
    }
};