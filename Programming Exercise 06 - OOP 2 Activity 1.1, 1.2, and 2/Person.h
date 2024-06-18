#include <iostream>
using namespace std;
class Person
{
private:
    int age;
    char gender;

public:
    Person(int newage, char c)
    {
        age = newage;
        gender = c;
    }

    void setage(int newage)
    {
        if (newage >= 0)
        {

            age = newage;
        }
        else
        {
            cout << "invalid age!" << endl;
        }
    }

    int getage()
    {
        return age;
    }

    void setgender(char c)
    {
        if ((c == 'M') || (c == 'F') || c == 'm' || c == 'f')
        {
            gender = c;
        }
        else
        {

            cout << "invalid gender!" << endl;
        }
    }
    char getgender()
    {
        return gender;
    }

    void view(int age, char gender)
    {
        cout << "Person age is = " << age << endl;
        cout << "Person gender is = " << gender << endl;
    }
};