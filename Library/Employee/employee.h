#pragma once
#include "../Date/date.h"

#ifndef EMPLOYEE_EMPLOYEE_H_
#define EMPLOYEE_EMPLOYEE_H_

enum Position {
    Administrator,
    Director,
    Librarian,
    SupportStaff
};

class Employee {
    Date _employment_date;
    Position _position;
    float _salary; 
};

#endif  // EMPLOYEE_EMPLOYEE_H_
