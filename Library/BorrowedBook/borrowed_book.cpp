//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/BorrowedBook/borrowed_book.h"

BorrowedBook::BorrowedBook(Book* book, Date issue_date, Date return_date, int days_overdue) :
	_book(book), _issue_date(issue_date), _return_date(return_date), 
	_days_overdue(days_overdue) {}


Book& BorrowedBook::get_book() const {
    if (_book == nullptr) {
        throw std::logic_error("Book pointer is null");
    }
    return *_book;
}

int BorrowedBook::get_days_overdue() const {
    return _days_overdue;
}
Date BorrowedBook::get_issue_date() const {
    return _issue_date;
}
Date BorrowedBook::get_return_date() const {
    return _return_date;
}