#include <iostream>
using namespace std;

// Function Prototypes
void progdescription();
void readdata(float &x, float &y, float &z);
float getsmall(float x, float y, float z);
float getbig(float x, float y, float z);
void showdata(float x, float y, float z, float smallval, float bigval, float diff);

// Program Description
void progdescription() {
    cout << "=====================================================================================\n";
    cout << "This program finds the highest and lowest value between 3 numbers. After sorting,\n";
    cout << "the lowest number will  be subtracted from the highest number.\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "Created by:\tFrancis Reid N. Arranguez\n";
    cout << "Date created:\t04/26/2024\n";
    cout << "Subject:\tCMSC 28 (K-3L)\n";
    cout << "=====================================================================================\n\n";
}

// Function that retrieves data from the user
void readdata(float &x, float &y, float &z) {        // Pass by reference to get the value of x, y, and z
    cout << "Enter a number(x): ";                  // Asks the user to input 3 numbers
    cin >> x;
    cout << "Enter a number(y): ";
    cin >> y;
    cout << "Enter a number(z): ";
    cin >> z;
}

// Function that gets the smallest number
float getsmall(float x, float y, float z) {          // Pass by value to get the value of x, y, and z
    if (x < y && x < z) {                           // If x is less than y and z, return x
        return x;
    } else if (y < x && y < z) {                  // If y is less than x and z, return y
        return y;
    } else {                                    // If z is less than x and y, return z
        return z;
    }
}

// Function that gets the biggest number
float getbig(float x, float y, float z) {               // Pass by value to get the value of x, y, and z
    if (x > y && x > z) {                              // If x is greater than y and z, return x
        return x;
    } else if (y > x && y > z) {                     // If y is greater than x and z, return y
        return y;
    } else {                                       // If z is greater than x and y,
        return z;
    }
}

// Function that shows the data
void showdata(float x, float y, float z, float smallval, float bigval, float diff) {            // Pass by value to get the value of x, y, z, 
    cout << "The numbers are " << x << ", " << y << ", and " << z << "." << endl;              // smallval, bigval, and diff
    cout << "The smallest number is " << smallval << "." << endl;
    cout << "The biggest number is " << bigval << "." << endl;
    cout << "The difference between the biggest and smallest number is " << diff << "." << endl;
}

int main() {
    float x, y, z, smallval, bigval, diff;                    // Declares variables x, y, z, smallval, bigval, and diff
    progdescription();                                       // Calls the function progdescription
    readdata(x, y, z);                                      // Calls the function readdata and passes the value of x, y, and z
    smallval = getsmall(x, y, z);                          // Calls the function getsmall and saves the value to smallval
    bigval = getbig(x, y, z);                             // Calls the function getbig and saves the value to bigval
    diff = bigval - smallval;                            // Subtracts the value of smallval from bigval and saves it to diff
    showdata(x, y, z, smallval, bigval, diff);          // Calls the function showdata and passes the value of x, y, z, smallval, bigval, and diff
    return 0;
}
