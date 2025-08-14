#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
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

    string filename = (role == 1) ? "../data/admin.csv" : "../data/user.csv";
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string file_uname, file_pwd;
        getline(ss, file_uname, ',');
        getline(ss, file_pwd, ',');
        if (file_uname == uname && file_pwd == pwd) {
            admin = (role == 1);
            username = uname;
            return true;
        }
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

    // Save user to CSV
    string filename = (role == 1) ? "../data/admin.csv" : "../data/user.csv";
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << uname << "," << pwd << "\n";
        file.close();
        cout << "Succesfully Registered...!" << uname << " as " << (role == 1 ? "Admin" : "User") << ".\n";
    } else {
        cout << "Error: Could not open file for writing.\n";
    }
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
