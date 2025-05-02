//  Copyright 2025 Guseva Olga

#pragma once

#include "C:/Users/Lelya/cc++/Individual_project/Library/FIO/fio.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Date/date.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Document/document.h"

#ifndef PERSON_PERSON_H_
#define PERSON_PERSON_H_

class Person {
    FIO _fio;
    Date _birthday;
    Document _document;
    char* phone;
};

#endif  // PERSON_PERSON_H_
