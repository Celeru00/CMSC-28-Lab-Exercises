#include <iostream>
using namespace std;

class CPU {
    private:
        float speed;
        string manufacturer;
        string codename;
    
    public:
        CPU(float s, string m, string c) {
            speed = s;
            manufacturer = m;
            codename = c;
        }

        void view() {
            cout << "========================================" << endl;
            cout << "CPU Information" << endl;
            cout << "Speed:\t\t" << speed << " GHz" << endl;
            cout << "Manufacturer: \t" << manufacturer << endl;
            cout << "Codename: \t" << codename << endl;
            cout << "========================================" << endl;
        }
};