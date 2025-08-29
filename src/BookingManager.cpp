#include "BookingManager.h"
#include "Ticket.h"
#include "Event.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

void BookingManager::loadData() {
    // TODO: Load events, users, tickets from CSV using FileManager
}

bool BookingManager::cancelTicket(const string& ticketID) {
    // TODO: Implement cancellation logic
    return false;
}
Ticket* BookingManager::searchTicketByID(const string& ticketID) {
    // TODO: Search logic
    return nullptr;
}
vector<Ticket> BookingManager::searchTicketsByEventID(const string& eventID) {
    // TODO: Search logic
    return vector<Ticket>();
}
vector<Ticket> BookingManager::searchTicketsByUserName(const string& userName) {
    // TODO: Search logic
    return vector<Ticket>();
}
vector<Ticket> BookingManager::filterTicketsByCategory(const string& category) {
    // TODO: Filter logic
    return vector<Ticket>();
}
void BookingManager::sortTicketsByPrice() {
    // TODO: Sort logic
}
void BookingManager::sortTicketsBySeatNumber() {
    // TODO: Sort logic
}
void BookingManager::sortTicketsByBookingOrder() {
    // TODO: Sort logic
}
void BookingManager::sortEventsByDate() {
    // TODO: Sort logic
}
void BookingManager::sortEventsByAvailability() {
    // TODO: Sort logic
}

bool BookingManager::bookTicket(const std::string& bookedFor, int eventId, const std::string& bookedBy) {
    // Find event details
    ifstream eventFile("../data/event.csv");
    string line;
    getline(eventFile, line); // Skip header
    string eventName, eventDate, eventLocation;
    bool found = false;
    while (getline(eventFile, line)) {
        stringstream ss(line);
        string id, name, date, location;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, date, ',');
        getline(ss, location, ',');
        if (stoi(id) == eventId) {
            eventName = name;
            eventDate = date;
            eventLocation = location;
            found = true;
            break;
        }
    }
    eventFile.close();
    if (!found) return false;

    // Generate unique ticket ID
    std::stringstream ticketIdStream;
    ticketIdStream << bookedFor << "_" << eventId << "_" << std::time(nullptr);
    std::string ticketId = ticketIdStream.str();

    // Store booking in details.csv
    ofstream file("../data/details.csv", ios::app);
    if (file.is_open()) {
        file << ticketId << "," << bookedFor << "," << eventId << "," << eventName << "," << eventDate << "," << eventLocation << ",Booked," << bookedBy << "\n";
        file.close();
        cout << "Your Ticket ID: " << ticketId << endl;
        return true;
    }
    return false;
}

std::vector<Ticket> BookingManager::getUserTickets(const std::string& username) {
    vector<Ticket> tickets;
    ifstream file("../data/details.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string user, eventId, status;
        getline(ss, user, ',');
        getline(ss, eventId, ',');
        getline(ss, status, ',');
        if (user == username && status == "Booked") {
            tickets.push_back(Ticket(user, stoi(eventId)));
        }
    }
    return tickets;
}

bool BookingManager::cancelTicket(const std::string& username, int eventId) {
    ifstream file("../data/details.csv");
    vector<string> lines;
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string user, eid, status;
        getline(ss, user, ',');
        getline(ss, eid, ',');
        getline(ss, status, ',');
        if (user == username && stoi(eid) == eventId && status == "Booked") {
            lines.push_back(user + "," + eid + ",Cancelled");
            found = true;
        } else {
            lines.push_back(line);
        }
    }
    file.close();

    ofstream outFile("../data/details.csv");
    for (const auto& l : lines) {
        outFile << l << "\n";
    }
    outFile.close();
    return found;
}

bool BookingManager::cancelTicket(const std::string& ticketId) {
    ifstream file("../data/details.csv");
    vector<string> lines;
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string tid;
        getline(ss, tid, ',');
        if (tid == ticketId) {
            // Change status to Cancelled
            size_t pos = line.rfind(",Booked,");
            if (pos != string::npos) {
                line.replace(pos, 7, ",Cancelled,");
            }
            found = true;
        }
        lines.push_back(line);
    }
    file.close();

    ofstream outFile("../data/details.csv");
    for (const auto& l : lines) {
        outFile << l << "\n";
    }
    outFile.close();
    return found;
}