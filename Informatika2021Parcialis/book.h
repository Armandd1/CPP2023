//
// Created by arman on 2023. 11. 12.
//

#ifndef INFORMATIKA2021PARCIALIS_BOOK_H
#define INFORMATIKA2021PARCIALIS_BOOK_H

using namespace std;

#include <string>
#include <ostream>

class Book {
private:
    string author;
    string title;
    int year;
    int pages;

public:
    Book(string author, string title, int year, int pages) {
        this->author = author;
        this->title = title;
        this->year = year;
        this->pages = pages;
    }

    const string &getAuthor() const {
        return author;
    }

    const string &getTitle() const {
        return title;
    }

    int getYear() const {
        return year;
    }

    int getPages() const {
        return pages;
    }

    void print(ostream &os) const {
        os << "Author: " << author << "\nTitle: " << title << "\nYear: " << year << "\nPages: " << pages << endl
           << endl;
    }

    friend ostream &operator<<(std::ostream &os, const Book &book) {
        book.print(os);
        return os;
    }

};


#endif //INFORMATIKA2021PARCIALIS_BOOK_H
