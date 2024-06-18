#include <iostream>
#include <list>                  // Include the list library
#include "Person.h"             // Include the Person header file
#include "Movie.h"             // Include the Movie header file
using namespace std;

// Program description
void description() {
    cout << "=================================================================" << endl;
    cout << "\tThis program displays the information of a movie." << endl;
    cout << "=================================================================" << endl;
    cout << "  Created by: Francis Reid N. Arranguez | 1-BSCS | CMSC28 - K-3L" << endl;
    cout << "=================================================================" << endl;
}

// Display the menu
int menu() {
    int choice;
    cout << "\nMenu:" << endl;
    cout << "[1] Add Movie Title" << endl;
    cout << "[2] Add Sypnosis" << endl;
    cout << "[3] Add MPAA Rating" << endl;
    cout << "[4] Add Genre" << endl;
    cout << "[5] Add Directors" << endl;
    cout << "[6] Add Actors/Actresses" << endl;
    cout << "[7] Display Movie Information" << endl;
    cout << "[0] Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

// Perform operations based on the user's choice
void operations(int choice, Movie& movie) {
    string title, synopsis, mpaa_rating, fname, lname, new_genre;           // Declare variables
    char minitial;
    list<string> genres;                                                   // Declare genres as a list of strings
    list<Person> directors, actors;                                       // Declare directors and actors as a list of Persons
    Person* person = nullptr;                                            // Declare a pointer to a Person

    switch (choice) {
        case 1:                                                     // Add Movie Title 
            cout << "Enter Movie Title: ";
            cin.ignore();
            getline(cin, title);
            movie.setTitle(title);
            break;
        case 2:                                                     // Add Synopsis
            cout << "Enter Synopsis: ";
            cin.ignore();
            getline(cin, synopsis);
            movie.setSynopsis(synopsis);
            break;
        case 3:                                                     // Add MPAA Rating
            cout << "Enter MPAA Rating: ";
            cin.ignore();
            getline(cin, mpaa_rating);
            movie.setMPAA_Rating(mpaa_rating);
            break;
        case 4:                                                               // Add Genre
            cout << "Enter genre: ";
            cin.ignore();                                                   // Ignore the newline character in the input stream
            getline(cin, new_genre);                                       // Get the user input
            genres = movie.getGenre();                                    // Get the current list of genres
            genres.push_back(new_genre);                                 // Add the new genre to the list
            movie.setGenre(genres);                                     // Set the updated list as the movie's list of genres
            break;
        case 5:                                                                 // Add Directors
            cout << "Enter director's first name: ";
            cin >> fname;
            cout << "Enter director's middle initial: ";
            cin >> minitial;
            cout << "Enter director's last name: ";
            cin >> lname;
            person = new Person(fname, minitial, lname);                    // Assign a new Person to the pointer
            directors = movie.getDirectors();                              // Get the current list of directors
            directors.push_back(*person);                                 // Dereference the pointer to get the Person
            movie.setDirectors(directors);                               // Set the updated list as the movie's list of directors
            break;
        case 6:                                                         // Add Actors/Actresses
            cout << "Enter actor's first name: ";
            cin >> fname;
            cout << "Enter actor's middle initial: ";
            cin >> minitial;
            cout << "Enter actor's last name: ";
            cin >> lname;
            person = new Person(fname, minitial, lname);                    // Assign a new Person to the pointer
            actors = movie.getActors();                                    // Get the current list of actors
            actors.push_back(*person);                                    // Dereference the pointer to get the Person
            movie.setActors(actors);                                     // Set the updated list as the movie's list of actors
            break;
        case 7:                                                                         // Display Movie Information
            cout << "\n============================================" << endl;
            cout << "Movie Information" << endl;
            movie.display();                                                          // Display the movie information
            cout << "============================================" << endl;
            break;
        case 0:                                             // Exit the program
            cout << "Exiting program..." << endl;
            break;
        default:                                         // Invalid choice                       
            cout << "Invalid choice!" << endl; 
            break;
    }
}

int main() {
    int choice;
    Movie movie;
    description();
    // Do-while loop to display the menu and perform operations based on the user's choice
    do {
        choice = menu();
        operations(choice, movie);
    } while (choice != 0);
    return 0;
}