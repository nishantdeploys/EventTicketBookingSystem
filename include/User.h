#pragma once
#include <string>
using namespace std;

class User {
    string userID, name, email;
    bool isVIP;
public:
    User();
    User(const string& id, const string& n, const string& e, bool vip);
    // Getters
    string getUserID() const;
    string getName() const;
    string getEmail() const;
    bool getVIPStatus() const;
    // Setters
    void setVIPStatus(bool vip);
};
