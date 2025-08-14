#include "User.h"
#include <iostream>
using namespace std;

User::User() : admin(false) {}

bool User::login() {
    string uname, pwd;
    int role;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pwd;
    cout << "Select role (1-Admin, 2-User): ";
    cin >> role;
    // TODO: Replace with actual user lookup and password check
    if (uname == "admin" && pwd == "admin" && role == 1) {
        admin = true;
        username = uname;
        return true;
    } else if (uname == "user" && pwd == "user" && role == 2) {
        admin = false;
        username = uname;
        return true;
    }
    return false;
}

void User::registerUser() {
    string uname, pwd;
    int role;
    cout << "Choose username: ";
    cin >> uname;
    cout << "Choose password: ";
    cin >> pwd;
    cout << "Select role (1-Admin, 2-User): ";
    cin >> role;
    // TODO: Save user to file/database
    cout << "Succesfully Registered...!" << uname << " as " << (role == 1 ? "Admin" : "User") << ".\n";
}

bool User::isAdmin() const {
    return admin;
}

void User::showUserMenu() {
    int choice;
    do {
        cout << "\n--- User Menu ---\n";
        cout << "1. View Events\n";
        cout << "2. Book Ticket\n";
        cout << "3. View My Bookings\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Showing available events...\n";
                // TODO: Implement event viewing
                break;
            case 2:
                cout << "Booking ticket...\n";
                // TODO: Implement ticket booking
                break;
            case 3:
                cout << "Showing your bookings...\n";
                // TODO: Implement booking viewing
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
}
