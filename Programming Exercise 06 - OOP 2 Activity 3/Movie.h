#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <list>
#include "Person.h"             // Include the Person header file
using namespace std;

class Movie {
    // Declare private members
    private:
        string Title;
        string Synopsis;
        string MPAA_Rating;
        list<string> Genre;            // Declare Genre as a list of strings
        list<Person> Director;        // Declare Director as a list of Persons
        list<Person> Actor;          // Declare Actor as a list of Persons

    public: 
        Movie() {};                 // Default constructor

        // Setters
        void setTitle(string a) {
            Title = a;
        }

        void setSynopsis(string b) {
            Synopsis = b;
        }
        void setMPAA_Rating(string c) {
            MPAA_Rating = c;
        }

        void setGenre(list<string> d) {
            this->Genre = d;
        }

        void setDirectors(list<Person> directors) {
            this->Director = directors;
        }
        void setActors(list<Person> actors) {
            this->Actor = actors;
        }

        // Getters
        string getTitle() {
            return Title;
        }

        string getSynopsis() {
            return Synopsis;
        }
        string getMPAA_Rating() {
            return MPAA_Rating;
        }

        list<string> getGenre() {
            return Genre;
        }

        list<Person> getDirectors() {
            return Director;
        }

        list<Person> getActors() {
            return Actor;
        }

        // Display movie details
        void display() {
            cout << "Title: " << Title << endl;
            cout << "Synopsis: \n" << Synopsis << endl;
            cout << "MPAA Rating: " << MPAA_Rating << endl;
            cout << "Genre: " << endl;
            for (string genre : Genre) {                                // Loop that iterates through the list of genres and prints each genre
                cout << "\t" << genre << endl;
            }
            cout << "Directors: " << endl;
            for (Person director : Director) {                         // Loop that iterates through the list of directors and prints each director
                cout << "\t" << director.getFullName() << endl;
            }
            cout << "Actors: " << endl;
            for (Person actor : Actor) {                              // Loop that iterates through the list of actors and prints each actor
                cout << "\t" << actor.getFullName() << endl;
            }
        }
};

#endif