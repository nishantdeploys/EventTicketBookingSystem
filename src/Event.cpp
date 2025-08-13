#include "Event.h"
using namespace std;

Event::Event() {}
Event::Event(const string& id, const string& n, const string& d, const string& v, int total, int available)
    : eventID(id), name(n), date(d), venue(v), totalSeats(total), availableSeats(available) {}
string Event::getEventID() const { return eventID; }
string Event::getName() const { return name; }
string Event::getDate() const { return date; }
string Event::getVenue() const { return venue; }
int Event::getTotalSeats() const { return totalSeats; }
int Event::getAvailableSeats() const { return availableSeats; }
void Event::setAvailableSeats(int seats) { availableSeats = seats; }
bool Event::bookSeat() { if (availableSeats > 0) { --availableSeats; return true; } return false; }
bool Event::cancelSeat() { if (availableSeats < totalSeats) { ++availableSeats; return true; } return false; }
