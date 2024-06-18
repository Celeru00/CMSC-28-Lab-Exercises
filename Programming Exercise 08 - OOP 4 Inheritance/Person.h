#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <list>
#include <sstream>
using namespace std;

class Person {
    // Declare protected members
    protected:
        string Fname;
        char Minitial;
        string Lname;

    public:
        Person() {};                                                    // Default constructor

        Person(string fname, char minitial, string lname) {             // Constructor
            this->Fname = fname;
            this->Minitial = minitial;
            this->Lname = lname;
        }

        // Setters
        void setFname(string a) {
            Fname = a;
        }

        void setLname(string b) {
            Lname = b;
        }

        void setMinitial(char c) {
            Minitial = c;
        }

        // Getters
        string getFname() {
            return Fname;
        }

        string getLname() {
            return Lname;
        }

        char getMinitial() {
            return Minitial;
        }

        // Function to get the full name
        string getFullName() const {
            stringstream ss;
            ss << Fname << " " << Minitial << ". " << Lname;            // Concatenate the first name, middle initial, and last name
            return ss.str();
        }
};

#endif
