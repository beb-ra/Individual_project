#pragma once
#include "../Book/book.h"
#include "../Date/date.h"

#ifndef BORROWEDBOOK_BORROWEDBOOK_H_
#define BORROWEDBOOK_BORROWEDBOOK_H_


class BorrowedBook {
    Book _book;
    Date _issue_date;
    Date _return_date;
    int _days_overdue;
};

#endif  // BORROWEDBOOK_BORROWEDBOOK_H_
