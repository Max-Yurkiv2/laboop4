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
    Library& operator-(const string& titleToRemove);

    void searchByAuthor(const string& a) const;
    void searchByTitle(const string& t) const;
    void searchByPublisher(const string& p) const;
    void searchByYear(int y) const;

    void display() const;
};

#endif#pragma once
