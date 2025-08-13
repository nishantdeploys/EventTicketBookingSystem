#pragma once
#include <string>
#include <vector>
#include "Event.h"
#include "User.h"
#include "Ticket.h"
using namespace std;

class FileManager {
public:
    static vector<Event> loadEvents(const string& filename);
    static void saveEvents(const string& filename, const vector<Event>& events);
    static vector<User> loadUsers(const string& filename);
    static void saveUsers(const string& filename, const vector<User>& users);
    static vector<Ticket> loadTickets(const string& filename);
    static void saveTickets(const string& filename, const vector<Ticket>& tickets);
};
