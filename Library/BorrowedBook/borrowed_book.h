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
    int _days_overdue;
    //int reader_id; ?

    BorrowedBook(Book* book, Date issue_date, Date return_date, int days_overdue = 0);

    Book& get_book() const; 
    int get_days_overdue() const;
    Date get_issue_date() const;
    Date get_return_date() const;
};

#endif  // BORROWEDBOOK_BORROWEDBOOK_H_
