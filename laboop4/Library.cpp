#include "Library.h"
#include <iostream>

Library::Library() : books(nullptr), size(0) {}

Library::~Library() {
    delete[] books;
}

// Add book (+)
Library& Library::operator+(const Book& newBook) {
    Book* temp = new Book[size + 1];
    for (int i = 0; i < size; ++i)
        temp[i] = books[i];
    temp[size] = newBook;

    delete[] books;
    books = temp;
    size++;
    return *this;
}

Library& Library::operator-(const string& titleToRemove) {
    if (size == 0) throw runtime_error("Library is empty.");

    int newSize = 0;
    for (int i = 0; i < size; ++i)
        if (books[i].getTitle() != titleToRemove)
            newSize++;

    if (newSize == size)
        throw invalid_argument("Book not found.");

    Book* temp = new Book[newSize];
    int j = 0;
    for (int i = 0; i < size; ++i)
        if (books[i].getTitle() != titleToRemove)
            temp[j++] = books[i];

    delete[] books;
    books = temp;
    size = newSize;
    return *this;
}

void Library::searchByAuthor(const string& a) const {
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (books[i].getAuthor() == a) {
            cout << books[i] << endl;
            found = true;
        }
    if (!found) cout << "No books found for author: " << a << endl;
}

void Library::searchByTitle(const string& t) const {
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (books[i].getTitle() == t) {
            cout << books[i] << endl;
            found = true;
        }
    if (!found) cout << "No books found with title: " << t << endl;
}

void Library::searchByPublisher(const string& p) const {
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (books[i].getPublisher() == p) {
            cout << books[i] << endl;
            found = true;
        }
    if (!found) cout << "No books found from publisher: " << p << endl;
}

void Library::searchByYear(int y) const {
    bool found = false;
    for (int i = 0; i < size; ++i)
        if (books[i].getYear() == y) {
            cout << books[i] << endl;
            found = true;
        }
    if (!found) cout << "No books found from year: " << y << endl;
}

void Library::display() const {
    if (size == 0) {
        cout << "Library is empty." << endl;
        return;
    }
    for (int i = 0; i < size; ++i)
        cout << i + 1 << ". " << books[i] << endl;
}