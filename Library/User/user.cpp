// Copyright 2025 Guseva Olgs

#include <iostream>

#include "/Users/Lelya/cc++/Individual_project/Library/User/user.h"
//#include "/Users/Lelya/cc++/Individual_project/Library/TVector/tvector.h"

User::User() : _login("Username"), _password("82549QWE") {}

User::User(const std::string& login, const std::string& password, bool is_registration) {
    if (is_registration) {
        set_login(login);
        set_password(password);
    }
    else {
        _login = login;
        _password = password;
    }
}
User::User(const User& other) {
    if (&other == NULL)
        throw std::invalid_argument("Object was not found\n");
    _login = other._login;
    _password = other._password;
}

void User::set_login(const std::string& login) {
    if (!check_correct_login(login))
        throw std::invalid_argument("Incorrect login\n");
    _login = login;
}
void User::set_password(const std::string& password) {
    if (!check_correct_password(password))
        throw std::invalid_argument("Incorrect password\n");
    _password = password;
}

const std::string User::get_login() const noexcept {
    return _login;
}
const std::string User::get_password() const noexcept {
    return _password;
}

bool User::operator==(const User& other) const noexcept {
    if (_login != other._login)
        return false;
    if (_password != other._password)
        return false;
    return true;
}

bool User::check_correct_login(const std::string& login) {
    if (login.length() < 4 || login.length() > 20) {
        throw std::invalid_argument
        ("The login must contain from 4 to 20 symbols!\n");
        return false;
    }

    if (login.find(' ') != std::string::npos) {
        throw std::invalid_argument("The login must not contain spaces!\n");
        return false;
    }
    return true;
}

bool User::check_correct_password(const std::string& password) {
    if (password.length() < 8 || password.length() > 20) {
        throw std::invalid_argument
        ("The password must contain from 8 to 20 symbols!\n");
        return false;
    }

    if (password.find(' ') != std::string::npos) {
        throw std::invalid_argument("The password must not contain spaces!\n");
        return false;
    }
    return true;
}