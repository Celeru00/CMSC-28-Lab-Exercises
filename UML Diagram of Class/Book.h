#include <iostream>
using namespace std;

class Book {
    // Private attributes
    private:
        string Title;
        string Author;
        string ISBN;
        string Publisher;

    // Public methods
    public:
        Book(){}                                         // Default Constructor

        Book(string bktitle){                             // Constructor with title
            Title = bktitle;
            Author = "Juan dela Cruz";
            ISBN = "1234567890";
            Publisher = "Juan's Publishing House";
        }

        Book(string bktitle, string bkauthor) {            // Constructor with title and author
            Title = bktitle;
            Author = bkauthor;
            ISBN = "1234567890";
            Publisher = "Juan's Publishing House";
        }

        Book(string bktitle, string bkauthor, string bkisbn) {            // Constructor with title, author and ISBN
            Title = bktitle;
            Author = bkauthor;
            ISBN = bkisbn;
            Publisher = "Juan's Publishing House";
        }

        Book(string bktitle, string bkauthor, string bkisbn, string bkpublisher) {          // Constructor with title, author, ISBN and publisher
            Title = bktitle;
            Author = bkauthor;
            ISBN = bkisbn;
            Publisher = bkpublisher;
        }

        void setTitle(string& bktitle) {          // Setter for Title
            Title = bktitle;
        }

        void setAuthor(string& bkauthor) {        // Setter for Author
            Author = bkauthor;
        }

        void setISBN(string& bkisbn) {           // Setter for ISBN
            ISBN = bkisbn;
        }

        void setPublisher(string& bkpublisher) {          // Setter for Publisher
            Publisher = bkpublisher;
        }

        string getTitle() {            // Getter for Title
            return Title;
        }

        string getAuthor() {          // Getter for Author
            return Author;
        }

        string getISBN() {           // Getter for ISBN
            return ISBN;
        }

        string getPublisher() {     // Getter for Publisher
            return Publisher;
        }

        // Method to view the book details. Depends on the constructor used.
        void viewBook() {
            cout << "\n================================================" << endl;
            cout << "Book Details: \t" << endl;
            cout << "Title: \t\t" << getTitle() << endl;
            cout << "Author: \t" << getAuthor() << endl;
            cout << "ISBN: \t\t" << getISBN() << endl;
            cout << "Publisher: \t" << getPublisher() << endl;
            cout << "================================================" << endl;
        }

        void viewBook(string title) {
            cout << "\n================================================" << endl;
            cout << "Book Details: \t" << endl;
            cout << "Title: \t\t" << title << endl;
            cout << "Author: \t" << getAuthor() << endl;
            cout << "ISBN: \t\t" << getISBN() << endl;
            cout << "Publisher: \t" << getPublisher() << endl;
            cout << "================================================" << endl;
        }

        void viewBook(string title, string author) {
            cout << "\n================================================" << endl;
            cout << "Book Details: \t" << endl;
            cout << "Title: \t\t" << title << endl;
            cout << "Author: \t" << author << endl;
            cout << "ISBN: \t\t" << getISBN() << endl;
            cout << "Publisher: \t" << getPublisher() << endl;
            cout << "================================================" << endl;
        }

        void viewBook(string title, string author, string isbn) {
            cout << "\n================================================" << endl;
            cout << "Book Details: \t" << endl;
            cout << "Title: \t\t" << title << endl;
            cout << "Author: \t" << author << endl;
            cout << "ISBN: \t\t" << isbn << endl;
            cout << "Publisher: \t" << getPublisher() << endl;
            cout << "================================================" << endl;
        }

        void viewBook(string title, string author, string isbn, string publisher) {
            cout << "\n================================================" << endl;
            cout << "Book Details: \t" << endl;
            cout << "Title: \t\t" << title << endl;
            cout << "Author: \t" << author << endl;
            cout << "ISBN: \t\t" << isbn << endl;
            cout << "Publisher: \t" << publisher << endl;
            cout << "================================================" << endl;
        }
};