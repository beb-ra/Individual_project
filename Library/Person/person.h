//  Copyright 2025 Guseva Olga

#pragma once

#include "fio.h"
#include "date.h"
#include "document.h"

#ifndef PERSON_PERSON_H_
#define PERSON_PERSON_H_

class Person {
    FIO _fio;
    Date _birthday;
    Document _document;
    char* phone;
};

#endif  // PERSON_PERSON_H_
