#include "FileManager.h"
#include "Event.h"
#include <fstream>
#include <sstream>
using namespace std;

vector<Event> FileManager::loadEvents(const string& filename) {
    vector<Event> events;
    ifstream file(filename);
    string line;
    getline(file, line); // Skip header
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, date, location;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, date, ',');
        getline(ss, location, ',');
        events.push_back(Event(stoi(id), name, date, location));
    }
    return events;
}
void FileManager::saveEvents(const string& filename, const vector<Event>& events) {
    // TODO: Write to CSV
}
vector<User> FileManager::loadUsers(const string& filename) {
    vector<User> users;
    // TODO: Read from CSV
    return users;
}
void FileManager::saveUsers(const string& filename, const vector<User>& users) {
    // TODO: Write to CSV
}
vector<Ticket> FileManager::loadTickets(const string& filename) {
    vector<Ticket> tickets;
    // TODO: Read from CSV
    return tickets;
}
void FileManager::saveTickets(const string& filename, const vector<Ticket>& tickets) {
    // TODO: Write to CSV
}
