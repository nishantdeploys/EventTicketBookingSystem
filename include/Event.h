#pragma once
#include <string>

class Event {
    int id;
    std::string name, date, location;
public:
    Event(int id, std::string name, std::string date, std::string location);
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getDate() const { return date; }
    std::string getLocation() const { return location; }
};
