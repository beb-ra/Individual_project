//  Copyright 2025 Guseva Olga

#pragma once
#include "/Users/Lelya/cc++/Individual_project/Library/Book/book.h"
#include "/Users/Lelya/cc++/Individual_project/Library/Date/date.h"
#include <stdexcept>

#ifndef BORROWEDBOOK_BORROWEDBOOK_H_
#define BORROWEDBOOK_BORROWEDBOOK_H_

class BorrowedBook {
    Book* _book;
    Date _issue_date;
    Date _return_date;
    int _reader_id;
    size_t _days_overdue;

public:
    BorrowedBook();
    BorrowedBook(Book* book, const Date issue_date, const Date return_date, 
        const int reader_id, const size_t days_overdue = 0);
    BorrowedBook(const BorrowedBook&);

    Book* get_book() const noexcept;
    size_t get_days_overdue() const noexcept;
    Date get_issue_date() const noexcept;
    Date get_return_date() const noexcept;
    int get_reader_id() const noexcept;

    void set_book(Book* new_book);
    void set_days_overdue(const size_t new_days_overdue);
    void set_return_date(const Date new_return_date);
    void set_reader_id(const int new_reader_id);
};

#endif  // BORROWEDBOOK_BORROWEDBOOK_H_
