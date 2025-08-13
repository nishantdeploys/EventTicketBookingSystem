#include "Ticket.h"
using namespace std;

Ticket::Ticket() {}
Ticket::Ticket(const string& tid, const string& eid, const string& uid, const string& cat, int seat, double p)
    : ticketID(tid), eventID(eid), userID(uid), category(cat), seatNumber(seat), price(p) {}
string Ticket::getTicketID() const { return ticketID; }
string Ticket::getEventID() const { return eventID; }
string Ticket::getUserID() const { return userID; }
string Ticket::getCategory() const { return category; }
int Ticket::getSeatNumber() const { return seatNumber; }
double Ticket::getPrice() const { return price; }
