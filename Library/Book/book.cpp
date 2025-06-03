//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/Book/book.h"


Book::Book(int id, const std::string& title, const std::string& author,
    const std::string& genre, int year, const BookStatus status,
    int readerId)
    : _book_id(id), _title(title), _author(author), _genre(genre),
    _year_publication(year), _status(status), _reader_id(readerId) {}

int _book_id;
std::string _title;
std::string _author;
std::string _genre;
int _year_publication;
BookStatus _status;
int _reader_id;

int Book::get_book_id() const {
    return _book_id;
}
std::string Book::get_title() const {
    return _title;
}
std::string Book::get_author() const {
    return _author;
}
std::string Book::get_genre() const {
    return _genre;
}
int Book::get_year_publication() const {
    return _year_publication;
}
BookStatus Book::get_book_status() const {
    return _status;
}
int Book::get_reader_id() const {
    return _reader_id;
}

void Book::set_status(const BookStatus new_status) {
    _status = new_status;
}
void Book::set_reader_id(int new_id) {
    _reader_id = new_id;
}
