//
// Created by arman on 2023. 11. 12.
//

#ifndef INFORMATIKA2021PARCIALIS_LIBRARY_H
#define INFORMATIKA2021PARCIALIS_LIBRARY_H

using namespace std;

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "book.h"

class Library {
private:
    vector<Book> books;

public:

    Library() {}

    Library(const Library &other) {
        for (const Book &book : other.books) {
            books.push_back(Book(book));
        }
    }

    Library(Library &&other) noexcept {
        books = std::move(other.books);
        other.books.clear();
    }

    void addBook(const Book& book) {
        books.push_back(book);
    }

//    void printBooks() {
//        for (Book book: books) {
//            cout << book;
//        }
//        cout<< "------------------------------------" << endl;
//    }

    friend ostream &operator<<(ostream &os, const Library &library) {
        for (const Book &book: library.books) {
            book.print(os);
        }
        cout << "------------------------------------" << endl;
        return os;
    }


    const Book findBook(const string &searchTerm) const {
        for (const Book &book: books) {
            if (book.getTitle().find(searchTerm) != string::npos || book.getAuthor().find(searchTerm) != string::npos) {
                return book; // Az első egyezést visszaadjuk
            }
        }
        // Ha nincs egyezés, kivételt váltunk ki
        throw out_of_range("Book not found!");
    }

    int countBooksByAuthor(const string& author) {
        int count = 0;
        for (const Book &book: books) {
            if (book.getAuthor() == author) {
                count++;
            }
        }
        return count;
    }

    void sortBooks() {
        sort(books.begin(), books.end(), [](const Book &book1, const Book &book2) {
            if (book1.getAuthor() != book2.getAuthor()) {
                return book1.getAuthor() < book2.getAuthor();
            }
            return book1.getYear() > book2.getYear();
        });
    }

    void deleteBook(const string& title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                books.erase(books.begin() + i);
            }
        }
    }

};


#endif //INFORMATIKA2021PARCIALIS_LIBRARY_H
