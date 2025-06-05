//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/Person/person.h"

Person::Person() : _fio(), _birthday(), _document(), _phone("") {}

Person::Person(FIO fio, Date birthday, Document document, std::string phone) :
	_fio(fio), _birthday(birthday), _document(document), _phone(phone) {}

Person::Person(const Person& other) {
	_fio = other._fio;
	_birthday = other._birthday;
	_document = other._document;
	_phone = other._phone;
}

FIO Person::get_fio() const {
	return _fio;
}
Date Person::get_birthday() const {
	return _birthday;
}
Document Person::get_document() const {
	return _document;
}
std::string Person::get_phone() const {
	return _phone;
}

void Person::set_fio(const FIO new_fio) {
	_fio = new_fio;
}
void Person::set_birthday(const Date new_birthday) {
	_birthday = new_birthday;
}
void Person::set_document(const Document new_document) {
	_document = new_document;
}
void Person::set_phone(const std::string new_phone) {
	_phone = new_phone;
}
