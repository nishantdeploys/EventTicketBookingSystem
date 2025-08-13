# Event Ticketing Platform

## Project Structure

```
EventTicketingPlatform/
│
├── src/
│   ├── main.cpp
│   ├── Event.h / Event.cpp
│   ├── User.h / User.cpp
│   ├── Ticket.h / Ticket.cpp
│   ├── BookingManager.h / BookingManager.cpp
│   ├── FileManager.h / FileManager.cpp
│
├── data/
│   ├── events.csv
│   ├── users.csv
│   ├── tickets.csv
│
├── README.md
└── Makefile (or CMakeLists.txt)
```

## Important Data Structures Used

- **std::vector**: Used for storing collections of events, users, and tickets in memory for easy iteration and management.
- **std::string**: Used for all textual data such as IDs, names, dates, and categories.
- **std::map** (future upgrade): Can be used for fast lookup of events, users, or tickets by their IDs.

## Core Classes

- **Event**: Represents an event and manages seat availability.
- **User**: Represents a user with contact info and VIP status.
- **Ticket**: Represents a booked ticket with seat and category details.
- **BookingManager**: Handles booking, cancellation, searching, and sorting operations.
- **FileManager**: Handles CSV file reading and writing for persistent storage.

## Data Persistence

- All data is stored in CSV files for simplicity and transparency.
- The FileManager class abstracts all file operations for modularity.

---
This structure is designed for modularity and future extensibility, allowing upgrades to more advanced data structures and features as needed.
