//  Copyright 2025 Guseva Olga

#pragma once

#include "C:/Users/Lelya/cc++/Individual_project/Library/FIO/fio.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Date/date.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Document/document.h"
#include <string>

#ifndef PERSON_PERSON_H_
#define PERSON_PERSON_H_

class Person {
    FIO _fio;
    Date _birthday;
    Document _document;
    std::string _phone;

public:
    Person();
    Person(const FIO fio, const Date birthday, const Document document, const std::string phone);
    Person(const Person&);

    FIO get_fio() const;
    Date get_birthday() const;
    Document get_document() const;
    std::string get_phone() const;

    void set_fio(const FIO new_fio);
    void set_birthday(const Date new_birthday);
    void set_document(const Document new_document);
    void set_phone(const std::string new_phone);
};

#endif  // PERSON_PERSON_H_
