#include "User.h"
using namespace std;

User::User() {}
User::User(const string& id, const string& n, const string& e, bool vip)
    : userID(id), name(n), email(e), isVIP(vip) {}
string User::getUserID() const { return userID; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }
bool User::getVIPStatus() const { return isVIP; }
void User::setVIPStatus(bool vip) { isVIP = vip; }
