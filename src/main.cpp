#include <iostream>
#include "BookingManager.h"
#include "User.h"
#include "Admin.h"
using namespace std;

int main() {
    cout << "========================================\n";
    cout << " Welcome to the Event Ticketing Platform\n";
    cout << "========================================\n";

    User currentUser;
    int choice;
    do {
        cout << "\nPlease choose an option:\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (currentUser.login()) {
                cout << "\nLogin successful as " << (currentUser.isAdmin() ? "Admin" : "User") << "!\n";
                if (currentUser.isAdmin()) {
                    Admin adminUser;
                    adminUser.showAdminMenu();
                } else {
                    currentUser.showUserMenu();
                }
            } else {
                cout << "\nLogin failed. Try again.\n";
            }
        } else if (choice == 2) {
            currentUser.registerUser();
        }
    } while (choice != 0);

    cout << "\nThank you for using the Event Ticketing Platform. Goodbye!\n";
    return 0;
}
