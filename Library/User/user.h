// Copyright 2025 Guseva Olga

#include <string>

#ifndef USER_USER_H_
#define USER_USER_H_

class User {
    std::string _login;
    std::string _password;

public:
    User();
    User(const std::string& login, const std::string& password, bool is_registration = false);
    User(const User&);

    ~User() = default;

    void set_login(const std::string& login);
    void set_password(const std::string& password);

    const std::string get_login() const noexcept;
    const std::string get_password() const noexcept;

    bool operator==(const User& other) const noexcept;

private:
    bool check_correct_login(const std::string& login);
    bool check_correct_password(const std::string& password);
};
#endif  // USER_USER_H_
