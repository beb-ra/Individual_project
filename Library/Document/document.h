//  Copyright 2025 Guseva Olga

#pragma once

#ifndef DOCUMENT_DOCUMENT_H_
#define DOCUMENT_DOCUMENT_H_

enum DocumentType {
    Passport,
    Diplom,
    StudentCard,
    PrivilegeCertificate
};

class Document {
    DocumentType _type;
    int _series;
    int _number;
};

#endif  // DOCUMENT_DOCUMENT_H_
