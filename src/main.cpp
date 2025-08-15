#include <iostream>
#include "BookingManager.h"
#include "User.h"
#include "Admin.h"
using namespace std;

int main() {
    BookingManager manager;
    manager.loadData();
    cout << "Welcome to the Event Ticketing Platform!" << endl;

    User currentUser;
    int choice;
    do {
        cout << "\n1. Login\n2. Register\n0. Exit\nChoose an option: ";
        cin >> choice;
        if (choice == 1) {
            if (currentUser.login()) {
                cout << "Login successful as " << (currentUser.isAdmin() ? "Admin" : "User") << "!\n";
                if (currentUser.isAdmin()) {
                    Admin adminUser;
                    adminUser.showAdminMenu();
                } else {
                    currentUser.showUserMenu();
                }
                break;
            } else {
                cout << "Login failed. Try again.\n";
            }
        } else if (choice == 2) {
            currentUser.registerUser();
        }
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
