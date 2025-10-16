#include "Library.h"
#include <iostream>

int main() {
    try {
        Library lib;

        Book b1("The Hobbit", "Tolkien", "Allen & Unwin", 1937);
        Book b2("1984", "Orwell", "Secker & Warburg", 1949);
        Book b3("Brave New World", "Huxley", "Chatto & Windus", 1932);

        lib + b1;
        lib + b2;
        lib + b3;

        cout << "Library contents:\n";
        lib.display();

        cout << "\nSearching by author 'Orwell':\n";
        lib.searchByAuthor("Orwell");

        cout << "\nRemoving '1984'...\n";
        lib - string("1984");

        cout << "\nLibrary after removal:\n";
        lib.display();

        cout << "\nSearching by year 1937:\n";
        lib.searchByYear(1937);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}