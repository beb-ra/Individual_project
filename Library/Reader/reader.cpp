//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/Reader/reader.h"

Reader::Reader() : Person(), _client_id(0), _reader_card() {}

Reader::Reader(const FIO fio, const Date birthday, const Document document, const std::string phone,
    const int client_id, const ReaderCard reader_card) : Person(fio, birthday, document, phone) {
    _client_id = client_id;
    _reader_card = reader_card;
}

Reader::Reader(const Reader& other) : Person(other) {
    _client_id = other._client_id;
    _reader_card = other._reader_card;
}
