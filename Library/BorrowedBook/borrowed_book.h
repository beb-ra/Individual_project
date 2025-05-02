//  Copyright 2025 Guseva Olga

#pragma once
#include "C:/Users/Lelya/cc++/Individual_project/Library/Book/book.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Date/date.h"

#ifndef BORROWEDBOOK_BORROWEDBOOK_H_
#define BORROWEDBOOK_BORROWEDBOOK_H_


class BorrowedBook {
    Book _book;
    Date _issue_date;
    Date _return_date;
    int _days_overdue;
};

#endif  // BORROWEDBOOK_BORROWEDBOOK_H_
