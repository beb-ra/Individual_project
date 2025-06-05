// Copyright 2025 Guseva Olga

#include <string>

#ifndef USER_USER_H_
#define USER_USER_H_

enum UserStatus {
    Director,
    Administrator,
    Librarian,
    Other
};

class User {
    std::string _login;
    std::string _password;
    UserStatus _status;

public:
    User();
    User(const std::string& login, const std::string& password, 
        const UserStatus status = UserStatus::Other, bool is_registration = false);
    User(const User&);

    ~User() = default;

    void set_login(const std::string& login);
    void set_password(const std::string& password);
    void set_status(const UserStatus status);

    const std::string get_login() const noexcept;
    const std::string get_password() const noexcept;
    const UserStatus get_status() const noexcept;

    bool operator==(const User& other) const noexcept;
private:
    bool check_correct_login(const std::string& login);
    bool check_correct_password(const std::string& password);
    bool check_correct_status(const UserStatus status);
};
#endif  // USER_USER_H_
