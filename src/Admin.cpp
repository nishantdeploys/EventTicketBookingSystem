#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() : User() {}

void Admin::showAdminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. View All Users\n";
    cout << "2. Manage Events\n";
    cout << "3. View Bookings\n";
    cout << "0. Logout\n";
    // TODO: Implement admin menu logic
}