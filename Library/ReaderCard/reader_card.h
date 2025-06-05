//  Copyright 2025 Guseva Olga

#pragma once

#include "/Users/Lelya/cc++/Individual_project/Library/Book/book.h"
#include "/Users/Lelya/cc++/Individual_project/Library/BorrowedBook/borrowed_book.h"
#include "/Users/Lelya/cc++/Individual_project/Library/Tvector/tvector.h"

#ifndef READERCARD_READERCARD_H_
#define READERCARD_READERCARD_H_


class ReaderCard {
    TVector<Book> _book_archive;
    TVector<BorrowedBook*> _borrowed_books;

public:
    ReaderCard();
    ReaderCard(const TVector<Book> book_archive, const TVector<BorrowedBook*> borrowed_books);
    ReaderCard(const ReaderCard&);

    const TVector<Book>& get_book_archive() const;
    const TVector<BorrowedBook*>& get_borrowed_books() const;

    void set_book_archive(const TVector<Book>& new_book_archive);
    void set_borrowed_books(const TVector<BorrowedBook*>& new_borrowed_books);
};

#endif  // READERCARD_READERCARD_H_
