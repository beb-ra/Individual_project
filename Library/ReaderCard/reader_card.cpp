//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/ReaderCard/reader_card.h"

ReaderCard::ReaderCard() : _book_archive(), _borrowed_books() {}

ReaderCard::ReaderCard(const TVector<Book> book_archive, const TVector<BorrowedBook*> borrowed_books) :
	_book_archive(book_archive), _borrowed_books(borrowed_books) {}

ReaderCard::ReaderCard(const ReaderCard& other) {
	_book_archive = other._book_archive;
	_borrowed_books = other._borrowed_books;
}

const TVector<Book>& ReaderCard::get_book_archive() const {
	return _book_archive;
}
const TVector<BorrowedBook*>& ReaderCard::get_borrowed_books() const {
	return _borrowed_books;
}

void ReaderCard::set_book_archive(const TVector<Book>& new_book_archive) {
	_book_archive = new_book_archive;
}
void ReaderCard::set_borrowed_books(const TVector<BorrowedBook*>& new_borrowed_books) {
	_borrowed_books = new_borrowed_books;
}