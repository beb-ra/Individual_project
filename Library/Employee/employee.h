//  Copyright 2025 Guseva Olga

#pragma once
#include "C:/Users/Lelya/cc++/Individual_project/Library/Date/date.h"
#include "C:/Users/Lelya/cc++/Individual_project/Library/Person/person.h"

#ifndef EMPLOYEE_EMPLOYEE_H_
#define EMPLOYEE_EMPLOYEE_H_

enum Position {
    Administrator,
    Director,
    Librarian,
    SupportStaff
};

class Employee : public Person {
    Date _employment_date;
    Position _position;
    float _salary;
};

#endif  // EMPLOYEE_EMPLOYEE_H_
