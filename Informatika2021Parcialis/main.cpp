#include <iostream>
#include "book.h"
#include "Library.h"

int main() {
//    Book myBook("John Doe", "Sample Book", 2022, 200);
//    Book myBook2("John", "Sample Book2", 2023, 203);
//    Library library;
//    library.addBook(myBook);
//    library.addBook(myBook2);
//    library.printBooks();
//
//    try {
//        const Book &foundBook = library.findBook("Book2");
//        cout << "Book: " << foundBook.getTitle() << " - " << foundBook.getAuthor() << endl;
//    } catch (const out_of_range &e) {
//        cerr << "Error: " << e.what() << endl;
//    }

    Library library;
    Book myBook1("Jokai Mor", "Egri csillagok", 1980, 300);
    Book myBook2("Jokai Mor", "A koszivu ember fiai", 1967, 400);
    Book myBook3("Murakami Haruki", "Sotetedes utan", 2004, 250);
    Book myBook4("Murakami Haruki", "A norveg erdo", 1987, 420);
    Book myBook5("Murakami Haruki", "1Q84", 1987, 800);
    Book myBook6("Knausgard Karl Ove", "Harcom", 2009, 1000);
    library.addBook(myBook1);
    library.addBook(myBook2);
    library.addBook(myBook3);
    library.addBook(myBook4);
    library.addBook(myBook5);
    library.addBook(myBook6);
//    library.printBooks();
    cout << library;

    cout << "Konyvek szama: " << library.countBooksByAuthor("Murakami Haruki") << endl << endl;

    try {
        const Book &foundBook = library.findBook("Harc");
        cout << "Book: " << foundBook.getTitle() << " - " << foundBook.getAuthor() << endl;
    } catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << endl;
    }

    library.sortBooks();
//    library.printBooks();
    cout << library;


    library.deleteBook("A koszivu ember fiai");
//    library.printBooks();
    cout << library;

    return 0;
}
