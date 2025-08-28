#include "Admin.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Admin::Admin() : User() {}

void Admin::showAdminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. View All Users\n";
        cout << "2. Manage Events\n";
        cout << "3. View Bookings\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // View all users
                ifstream file("../data/user.csv");
                string line;
                cout << "\nRegistered Users:\n";
                getline(file, line); // Skip header
                while (getline(file, line)) {
                    stringstream ss(line);
                    string username, password;
                    getline(ss, username, ',');
                    getline(ss, password, ',');
                    cout << "Username: " << username << endl;
                }
                file.close();
                break;
            }
            case 2: {
                // Manage events (view events)
                ifstream file("../data/event.csv");
                string line;
                cout << "\nEvents:\n";
                getline(file, line); // Skip header
                while (getline(file, line)) {
                    stringstream ss(line);
                    string id, name, date, location;
                    getline(ss, id, ',');
                    getline(ss, name, ',');
                    getline(ss, date, ',');
                    getline(ss, location, ',');
                    cout << "ID: " << id << ", Name: " << name << ", Date: " << date << ", Location: " << location << endl;
                }
                file.close();
                break;
            }
            case 3: {
                // View bookings
                ifstream file("../data/bookings.csv");
                string line;
                cout << "\nBookings:\n";
                while (getline(file, line)) {
                    stringstream ss(line);
                    string username, eventId;
                    getline(ss, username, ',');
                    getline(ss, eventId, ',');
                    cout << "User: " << username << ", Event ID: " << eventId << endl;
                }
                file.close();
                break;
            }
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
}