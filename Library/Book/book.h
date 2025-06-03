//  Copyright 2025 Guseva Olga

#pragma once
#include <string>

#ifndef BOOK_BOOK_H_
#define BOOK_BOOK_H_

enum BookStatus {
    InLibrary,
    Taken,
    Lost,
    WrittenDown
};

class Book {
    int _book_id;
    std::string _title;
    std::string _author;
    std::string _genre;
    int _year_publication;
    BookStatus _status;
    int _reader_id;

    Book(int book_id, const std::string& title, const std::string& author,
        const std::string& genre, int year, const BookStatus book_status = BookStatus::InLibrary,
        int reader_id = -1);

    int get_book_id() const;
    std::string get_title() const;
    std::string get_author() const;
    std::string get_genre() const;
    int get_year_publication() const;
    BookStatus get_book_status() const;
    int get_reader_id() const;

    void set_status(const BookStatus new_status);
    void set_reader_id(int new_id);
};

#endif  // BOOK_BOOK_H_
