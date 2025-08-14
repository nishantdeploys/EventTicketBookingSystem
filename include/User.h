#pragma once
#include <string>

class User {
private:
    std::string username;
    std::string password;
    bool admin;
public:
    User();
    bool login();
    void registerUser();
    bool isAdmin() const;
    void showUserMenu();
};
