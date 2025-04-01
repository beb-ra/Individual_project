#pragma once
#include "../Book/book.h"
#include "../BorrowedBook/borrowed_book.h"

#ifndef READERCARD_READERCARD_H_
#define READERCARD_READERCARD_H_


class ReaderCard {
    Book* _book_archive;
    BorrowedBook** _borrowed_books;
};

#endif  // READERCARD_READERCARD_H_
