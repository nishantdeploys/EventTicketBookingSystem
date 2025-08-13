#pragma once
#include <string>
using namespace std;

class Ticket {
    string ticketID, eventID, userID, category;
    int seatNumber;
    double price;
public:
    Ticket();
    Ticket(const string& tid, const string& eid, const string& uid, const string& cat, int seat, double p);
    // Getters
    string getTicketID() const;
    string getEventID() const;
    string getUserID() const;
    string getCategory() const;
    int getSeatNumber() const;
    double getPrice() const;
};
