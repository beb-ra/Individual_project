//  Copyright 2025 Guseva Olga

#pragma once

#include "C:/Users/Lelya/cc++/Individual_project/Library/ReaderCard/reader_card.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Person/person.h"

#ifndef READER_READER_H_
#define READER_READER_H_


class Reader : public Person {
    int _client_id;
    ReaderCard _reader_card;

public:
    Reader();
    Reader(const FIO fio, const Date birthday, const Document document, const std::string phone,
        const int client_id, const ReaderCard reader_card);
    Reader(const Reader&);
};

#endif  // READER_READER_H_
