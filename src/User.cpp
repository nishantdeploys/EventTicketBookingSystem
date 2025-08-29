#include "User.h"
#include "BookingManager.h"
#include "Event.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
    getline(file, line); // Skip header
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

    string filename = (role == 1) ? "../data/admin.csv" : "../data/user.csv";
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << uname << "," << pwd << "\n";
        file.close();
        cout << "Successfully Registered...!" << uname << " as " << (role == 1 ? "Admin" : "User") << ".\n";
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
        cout << "4. Cancel Ticket\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                // Show events
                ifstream file("../data/event.csv");
                string line;
                cout << "\nAvailable Events:\n";
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
            case 2: {
                int eventId;
                string bookedFor;
                cout << "\nEnter Event ID to book (or 0 to go back): ";
                cin >> eventId;
                if (eventId == 0) break;
                cout << "Enter name for ticket (can be your name or someone else's): ";
                cin >> bookedFor;
                BookingManager bookingManager;
                if (bookingManager.bookTicket(bookedFor, eventId, username)) {
                    cout << "Ticket booked successfully!\n";
                } else {
                    cout << "Booking failed. Event may be full or not found.\n";
                }
                break;
            }
            case 3: {
                // Show bookings where booked_by == username
                ifstream file("../data/details.csv");
                string line;
                bool found = false;
                cout << "\nYour Bookings:\n";
                while (getline(file, line)) {
                    stringstream ss(line);
                    string bookedFor, eventId, eventName, eventDate, eventLocation, status, bookedBy;
                    getline(ss, bookedFor, ',');
                    getline(ss, eventId, ',');
                    getline(ss, eventName, ',');
                    getline(ss, eventDate, ',');
                    getline(ss, eventLocation, ',');
                    getline(ss, status, ',');
                    getline(ss, bookedBy, ',');
                    if (bookedBy == username) {
                        found = true;
                        cout << "Ticket for: " << bookedFor
                             << ", Event ID: " << eventId
                             << ", Name: " << eventName
                             << ", Date: " << eventDate
                             << ", Location: " << eventLocation
                             << ", Status: " << status << endl;
                    }
                }
                file.close();
                if (!found) {
                    cout << "No bookings found.\n";
                }
                break;
            }
            case 4: {
                // Cancel ticket
                int eventId;
                cout << "\nEnter Event ID to cancel (or 0 to go back): ";
                cin >> eventId;
                if (eventId == 0) break;
                BookingManager bookingManager;
                if (bookingManager.cancelTicket(username, eventId)) {
                    cout << "Ticket cancelled successfully!\n";
                } else {
                    cout << "Cancellation failed. Ticket not found.\n";
                }
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
