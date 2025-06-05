//  Copyright 2025 Guseva Olga

#pragma once

#include "C:/Users/Lelya/cc++/Individual_project/Library/Employee/employee.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Reader/reader.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Book/book.h"

#ifndef LIBRARY_LIBRARY_H_
#define LIBRARY_LIBRARY_H_

class Library {
    TVector<Employee> _employees;
    TVector<Reader> _readers;
    TVector<Book> _books;
    TVector<BorrowedBook> _borrowed_books;

public:
    Library();
    Library(const TVector<Employee> employees, const TVector<Reader> readers,
        const TVector<Book> books, const TVector<BorrowedBook> borrowed_books);
    Library(const Library&);

    const TVector<Employee>& get_employees() const noexcept;
    const TVector<Reader>& get_readers() const noexcept;
    const TVector<Book>& get_books() const noexcept;
    const TVector<BorrowedBook>& get_borrowed_books() const noexcept;
};

#endif  // LIBRARY_LIBRARY_H_
