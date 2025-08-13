#pragma once
#include <string>
using namespace std;

class Event {
    string eventID, name, date, venue;
    int totalSeats, availableSeats;
public:
    Event();
    Event(const string& id, const string& n, const string& d, const string& v, int total, int available);
    // Getters
    string getEventID() const;
    string getName() const;
    string getDate() const;
    string getVenue() const;
    int getTotalSeats() const;
    int getAvailableSeats() const;
    // Setters
    void setAvailableSeats(int seats);
    // Seat management
    bool bookSeat();
    bool cancelSeat();
};
