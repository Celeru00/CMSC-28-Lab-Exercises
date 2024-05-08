#include <iostream>
using namespace std;

// Function Prototypes
void programDescription();
void readData(int &a);
int convertToBinary(int a, int& result);
void displayData(int a, int result);

// Program Description
void programDescription() {
    cout << "=======================================================================\n";
    cout << "\tThis program converts an integer to its binary equivalent.\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Created by:\tFrancis Reid N. Arranguez\n";
    cout << "Date created:\t04/26/2024\n";
    cout << "Subject:\tCMSC 28 (K-3L)\n";
    cout << "========================================================================\n\n";
}

// Function that retrieves data from the user
void readData (int &a) {                // Pass by reference to get the value of a
    cout << "Enter a number: ";
    cin >> a;
}

// Function that converts the integer to binary and stores it in result
int convertToBinary(int a, int& result) {                // Pass by reference to get the value of a and result
    int remainder, i = 1;                               // Initialize variables remainder and i
    result = 0;                                        // Initialize result to 0
    while (a != 0) {                                  // Loop that continuously divides a by 2 until a is 0
        remainder = a % 2;                           
        a /= 2;                                     // The remainder is multiplied by i and added to result
        result += remainder * i;                   // Variable i is used to determine the position of the remainder
        i *= 10;                                  // Each digit is stored in a decimal number so each position is 10 times the previous one.
    }
}

// Function that displays the data
void displayData(int a, int result) {
    cout << "The binary equivalent of " << a << " is " << result << "." << endl;      
}

int main() {
    int a, result;
    programDescription();                   // Function call to display the program description
    readData(a);                           // Function call to retrieve data from the user
    convertToBinary(a, result);           // Function call to convert the integer to binary
    displayData(a, result);              // Function call to display the data
    return 0;
}