#pragma once
#include <string>
#include "User.h"

class Admin : public User {
public:
    Admin();
    void showAdminMenu();
    // Add more admin-specific methods here
};