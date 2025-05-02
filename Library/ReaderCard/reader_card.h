//  Copyright 2025 Guseva Olga

#pragma once

#include "C:/Users/Lelya/cc++/Individual_project/Library/Book/book.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/BorrowedBook/borrowed_book.h"

#ifndef READERCARD_READERCARD_H_
#define READERCARD_READERCARD_H_


class ReaderCard {
    Book* _book_archive;
    BorrowedBook** _borrowed_books;
};

#endif  // READERCARD_READERCARD_H_
