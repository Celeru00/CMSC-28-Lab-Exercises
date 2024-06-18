#include <iostream>
using namespace std;

// Function Prototypes
void description();
float getData(float *numPtr);
float getLargest(float length, float *numPtr);
float getSmallest(float length, float *numPtr);
float getMean(float length, float *numPtr);
float getVariance(float Mean, float *numPtr, float length);
float getSD(float Var);
void output(float length, float largest, float smallest, float Mean, float Var, float SD);

// Function that displays the description of the program
void description() {
    cout << "========================================================\n";
    cout << "\t\tProgramming Exercise 05\n";
    cout << "\tCreated by: Francis Reid N. Arranguez\n";
    cout << "========================================================\n";
    cout << "    This program will ask the user to input various\n";
    cout << "     numbers (positive or negative but not zero)\n";
    cout << "    and perform basic statistics on these numbers.\n";
    cout << "========================================================\n\n";
}

// Function that gets the data from the user and records the number of data entered 
float getData(float *numPtr) {
    float length;
    for (int i = 0; i < 10; i++) {                         // Loop that gets the data from the user
        cout << "Enter number " << i + 1 << ": ";
        cin >> *(numPtr + i);
        if (*(numPtr + i) == 0) {                       // If the user enters 0, the loop will break
            length = i;                                // If 0 is entered, the length will be i
            break;
        } else {
            length = i+1;                           // If 0 is not entered, the length will be i+1
        }
    }
    return length;                               // Returns the length of the data entered
}

// Function that gets the largest number from the data entered
float getLargest(float length, float *numPtr) {                 // Pass by reference
    float largest = *numPtr;                                   // Initialize the largest number to the first number entered
    for (int i = 0; i < length; i++) {                        // Loop that gets the largest number
        if (*(numPtr + i) > largest) {                       // If the number is greater than the largest number,
            largest = numPtr[i];                            // the value of the largest number is swapped
        }
    }
    return largest;                                      // Returns the largest number
}

// Function that gets the smallest number from the data entered
float getSmallest(float length, float *numPtr) {
    float smallest = *numPtr;                                 // Initialize the smallest number to the first number entered
    for (int i = 0; i < length; i++) {                       // Loop that gets the smallest number
        if (*(numPtr + i) < smallest) {                     // If the number is less than the smallest number,
            smallest = numPtr[i];                          // the value of the smallest number is swapped
        }
    }
    return smallest;                                    // Returns the smallest number
}

// Function that gets the mean of the data entered
float getMean(float length, float *numPtr) {
    float result = 0, sum;                                  // Initialize the result to 0
    for (int i = 0; i < length; i++) {                     // Loop that adds all of the members of the array
        sum = result + numPtr[i];                         // Adds the current number to the result
        result = sum;                                    // Assigns the sum to the result
    }
    return result/length;                              // Divides the sum by the length of the data entered to get the mean
}

// Function that gets the sample variance of the data entered
float getVariance(float Mean, float *numPtr, float length) {                
    float sum, result = 0;                                                  // Initialize the result to 0                                      
    for (int i=0; i < length; i++) {                                       // Loop that gets the sample variance                
        sum =  result + ((numPtr[i] - Mean)*(numPtr[i] - Mean));          // Summation of the square of the difference of the number and the mean
        result = sum;
    }
    return result/(length-1);                                           // Divides the sum by the length of the data entered minus 1
}

// Function that gets the sample standard deviation of the data entered
float getSD(float Var) {
    float result = 1;                                       // Initialize the result to 1
    for (int i = 0; i < 20; i++){                          // Loop that gets the square root of the variance by using the Newton-Raphson method
        result = (result + (Var / result)) / 2;
    }
    return result;
}

// Function that outputs the data entered and the statistics of the data
void output(float length, float largest, float smallest, float Mean, float Var, float SD) {
    cout << "\n========================================================\n";
    cout << "The number of data entered is: \t\t" << length << endl;
    cout << "The largest number is: \t\t\t" << largest << endl;
    cout << "The smallest number is: \t\t" << smallest << endl;
    cout << "The mean of the data is: \t\t" << Mean << endl;
    cout << "The variance of the data is: \t\t" << Var << endl;
    cout << "The standard deviation of the data is: \t" << SD << endl;
    cout << "========================================================\n";
}

int main() {
    float length, largest, smallest, Mean, Var, SD;
    float num[10], *numPtr = num;                           // Pointer that points to the array
    description();
    length = getData(numPtr);
    largest = getLargest(length, numPtr);
    smallest = getSmallest(length, numPtr);
    Mean = getMean(length, numPtr);
    Var = getVariance(Mean, numPtr, length);
    SD = getSD(Var);
    output(length, largest, smallest, Mean, Var, SD);
    return 0;
}