#pragma once
#include <string>

class Ticket {
    std::string username;
    int eventId;
public:
    Ticket(std::string username, int eventId);
    int getEventId() const { return eventId; }
    std::string getUsername() const { return username; }
};
