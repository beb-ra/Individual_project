#pragma once

#include "../Employee/employee.h"
#include "../Reader/reader.h"
#include "../Book/book.h"

#ifndef PERSON_PERSON_H_
#define PERSON_PERSON_H_

class Person {
    Employee _employees;
    Reader _readers;
    Book _books;
};

#endif  // PERSON_PERSON_H_
