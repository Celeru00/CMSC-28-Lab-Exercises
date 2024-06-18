#include <iostream>
#include "Book.h"       // Include the Book header file

// Function that displays the description of the program
void description() {
    cout << "========================================================\n";
    cout << "\t    UML Diagram of Class (CMSC 28)\n";
    cout << "\tCreated by: Francis Reid N. Arranguez\n";
    cout << "========================================================\n";
    cout << "    This program will implements a class called Book.\n";
    cout << "  The class has the following attributes: Title, Author,\n";
    cout << "     ISBN, and Publisher. Each attributes are then\n";
    cout << "   implemented using a constructor chosen by the user.\n";
    cout << "========================================================\n\n";
}

// Function that gets the input from the user
void getInput(string &bktitle, string &bkauthor, string &bkisbn, string &bkpublisher){
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Please enter the specified book details:" << endl;
    cout << "Enter title: ";
    getline(cin, bktitle);
    cout << "Enter author: ";
    getline(cin, bkauthor);
    cout << "Enter ISBN: ";
    getline(cin, bkisbn);
    cout << "Enter publisher: ";
    getline(cin, bkpublisher);
}

// Function that displays the menu and gets the choice of the user
int menu() {
    int a;
    cout << "\nPlease select a constructor to use: " << endl;
    cout << "[1] Default Constructor" << endl;
    cout << "[2] Constructor with title" << endl;
    cout << "[3] Constructor with title and author" << endl;
    cout << "[4] Constructor with title, author and ISBN" << endl;
    cout << "[5] Constructor with title, author, ISBN and publisher" << endl;
    cout << "[0] Exit" << endl;
    cout << "Enter choice: ";
    cin >> a;
    return a;
}

// Function that performs the operations based on the choice of the user
void operations( int choice, string bktitle, string bkauthor, string bkisbn, string bkpublisher) {
    // Create a switch statement to perform the operations based on the choice of the user
    switch (choice) {
    case 1:                                                    // Default Constructor
        {
            Book book1;                                      // Create an object of the Book class
            book1.setTitle(bktitle);                        // Set the title of the book
            book1.setAuthor(bkauthor);                     // Set the author of the book
            book1.setISBN(bkisbn);                        // Set the ISBN of the book
            book1.setPublisher(bkpublisher);             // Set the publisher of the book
            book1.viewBook();                           // Display the book details
        }
            break;
    case 2:                                                 // Constructor with title
        {
            Book book2(bktitle);                         // Create an object of the Book class
            book2.viewBook(bktitle);                    // Display the book details
        }
            break;
    case 3:                                                       // Constructor with title and author
        {
            Book book3(bktitle, bkauthor);                      // Create an object of the Book class
            book3.viewBook(bktitle, bkauthor);                 // Display the book details
        }
            break;
    case 4:                                                            // Constructor with title, author and ISBN
        {
            Book book4(bktitle, bkauthor, bkisbn);                   // Create an object of the Book class
            book4.viewBook(bktitle, bkauthor, bkisbn);              // Display the book details
        }
            break;
    case 5:                                                    // Constructor with title, author, ISBN and publisher
        {
            Book book5(bktitle, bkauthor, bkisbn, bkpublisher);                     // Create an object of the Book class
            book5.viewBook(bktitle, bkauthor, bkisbn, bkpublisher);                // Display the book details
        }
            break;
    case 0:
            cout << "--[Program Terminated!]--" << endl;             // Exit the program               
            break;
    default:
            cout << "Invalid choice!" << endl;                      // Display an error message if the choice is invalid
            break;
    }
}

int main() {
    int choice;
    string bktitle, bkauthor, bkisbn, bkpublisher;                      // Declare the variables for the book details   
    description();
    getInput(bktitle, bkauthor, bkisbn, bkpublisher);
    // Create a do-while loop to display the menu and perform the operations based on the choice of the user
    do {
        choice = menu();
        operations(choice, bktitle, bkauthor, bkisbn, bkpublisher);
    } while (choice != 0);
    return 0;
}