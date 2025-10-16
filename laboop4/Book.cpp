#include "Book.h"

Book::Book() : title(""), author(""), publisher(""), year(0) {}

Book::Book(string t, string a, string p, int y) {
    setTitle(t);
    setAuthor(a);
    setPublisher(p);
    setYear(y);
}

void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }
void Book::setPublisher(string p) { publisher = p; }

void Book::setYear(int y) {
    if (y < 0) throw invalid_argument("Year cannot be negative.");
    year = y;
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher() const { return publisher; }
int Book::getYear() const { return year; }

ostream& operator<<(ostream& os, const Book& b) {
    os << "Title: " << b.title
        << ", Author: " << b.author
        << ", Publisher: " << b.publisher
        << ", Year: " << b.year;
    return os;
}