#pragma once

#ifndef BOOK_BOOK_H_
#define BOOK_BOOK_H_

enum Genre {
    Prose,
    Fantasy,
    Poetry,
    Comedy,
    Novel,
    FairyTale
};

enum BookStatus {
    InLibrary,
    Taken,
    Lost,
    WrittenDown
};

class Book {
    int _book_id;
    char* _book_name;
    char* _author;
    Genre _genre;
    int _year_publication;
    BookStatus _book_status;
    int _reader_id;
};

#endif  // BOOK_BOOK_H_
