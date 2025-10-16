#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
private:
    Book* books;
    int size;

public:
    Library();
    ~Library();

    Library& operator+(const Book& newBook);
    Library& operator-(const std::string& titleToRemove);

    void search(const std::string& author) const;
    void search(const std::string& title, bool byTitle) const;
    void searchByPublisher(const std::string& publisher) const; 
    void search(int year) const;

    void display() const;
};

#endif
