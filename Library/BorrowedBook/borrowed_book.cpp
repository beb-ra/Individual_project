//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/BorrowedBook/borrowed_book.h"

BorrowedBook::BorrowedBook() : _book(), _issue_date(), _return_date(), _reader_id(-1), _days_overdue(0) {}

BorrowedBook::BorrowedBook(Book* book, Date issue_date, Date return_date, int reader_id, size_t days_overdue) :
	_book(book), _issue_date(issue_date), _return_date(return_date),
    _reader_id(reader_id), _days_overdue(days_overdue) {}

BorrowedBook::BorrowedBook(const BorrowedBook& other) {
    _book = other._book;
    _issue_date = other._issue_date;
    _return_date = other._return_date;
    _reader_id = other._reader_id;
    _days_overdue = other._days_overdue;
}

Book* BorrowedBook::get_book() const noexcept {
    return _book;
}

size_t BorrowedBook::get_days_overdue() const noexcept {
    return _days_overdue;
}
Date BorrowedBook::get_issue_date() const noexcept {
    return _issue_date;
}
Date BorrowedBook::get_return_date() const noexcept {
    return _return_date;
}

int BorrowedBook::get_reader_id() const noexcept {
    return _reader_id;
}

void BorrowedBook::set_book(Book* new_book) {
    _book = new_book;
}

void BorrowedBook::set_days_overdue(const size_t new_days_overdue) {
    _days_overdue = new_days_overdue;
}
void BorrowedBook::set_return_date(const Date new_return_date) {
    _return_date = new_return_date;
}
void BorrowedBook::set_reader_id(const int new_reader_id) {
    _reader_id = new_reader_id;
}