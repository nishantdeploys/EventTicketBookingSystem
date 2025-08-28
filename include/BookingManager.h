#pragma once
#include <vector>
#include "Event.h"
#include "User.h"
#include "Ticket.h"
#include "FileManager.h"
using namespace std;

class BookingManager {
    vector<Event> events;
    vector<User> users;
    vector<Ticket> tickets;
public:
    void loadData();
    bool bookTicket(const std::string& username, int eventId);
    bool cancelTicket(const string& ticketID);
    Ticket* searchTicketByID(const string& ticketID);
    vector<Ticket> searchTicketsByEventID(const string& eventID);
    vector<Ticket> searchTicketsByUserName(const string& userName);
    vector<Ticket> filterTicketsByCategory(const string& category);
    void sortTicketsByPrice();
    void sortTicketsBySeatNumber();
    void sortTicketsByBookingOrder();
    void sortEventsByDate();
    void sortEventsByAvailability();
    std::vector<Ticket> getUserTickets(const std::string& username);
};
