//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/Book/book.h"

Book::Book() : _book_id(0), _title(""), _author(""), _genre(""), _year_publication(0), 
   _status(BookStatus::InLibrary), _reader_id(-1) {}

Book::Book(int id, const std::string& title, const std::string& author,
    const std::string& genre, int year, const BookStatus status,
    int reader_id)
    : _book_id(id), _title(title), _author(author), _genre(genre),
    _year_publication(year), _status(status), _reader_id(reader_id) {}

Book::Book(const Book& other) {
    _book_id = other._book_id;
    _title = other._title;
    _author = other._author;
    _genre = other._genre;
    _year_publication = other._year_publication;
    _status = other._status;
    _reader_id = other._reader_id;
}

int Book::get_book_id() const noexcept {
    return _book_id;
}
std::string Book::get_title() const noexcept {
    return _title;
}
std::string Book::get_author() const noexcept {
    return _author;
}
std::string Book::get_genre() const noexcept {
    return _genre;
}
int Book::get_year_publication() const noexcept {
    return _year_publication;
}
BookStatus Book::get_book_status() const noexcept {
    return _status;
}
int Book::get_reader_id() const noexcept {
    return _reader_id;
}

void Book::set_status(const BookStatus new_status) {
    _status = new_status;
}
void Book::set_reader_id(const int new_id) {
    _reader_id = new_id;
}
