//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/Library/library.h"

Library::Library() : _employees(), _readers(), _books(), _borrowed_books() {}

Library::Library(const TVector<Employee> employees, const TVector<Reader> readers,
    const TVector<Book> books, const TVector<BorrowedBook> borrowed_books) :
    _employees(employees), _readers(readers), _books(books), _borrowed_books(borrowed_books) {}

Library::Library(const Library& other) {
    _employees = other._employees;
    _readers = other._readers;
    _books = other._books;
    _borrowed_books = other._borrowed_books;
}

const TVector<Employee>& Library::get_employees() const noexcept {
    return _employees;
}
const TVector<Reader>& Library::get_readers() const noexcept {
    return _readers;
}
const TVector<Book>& Library::get_books() const noexcept {
    return _books;
}
const TVector<BorrowedBook>& Library::get_borrowed_books() const noexcept {
    return _borrowed_books;
}
