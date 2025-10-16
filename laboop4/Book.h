#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    int year;

public:
    Book();
    Book(string t, string a, string p, int y);

    void setTitle(string t);
    void setAuthor(string a);
    void setPublisher(string p);
    void setYear(int y);

    string getTitle() const;
    string getAuthor() const;
    string getPublisher() const;
    int getYear() const;

    friend ostream& operator<<(ostream& os, const Book& b);
};

#endif
