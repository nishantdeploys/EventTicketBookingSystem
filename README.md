# Event Ticketing Platform

## Project Structure

```
EventTicketingPlatform/
│
├── bin/
│   └── EventTicketingPlatform.exe      # Compiled executable
│
├── data/
│   ├── events.csv                      # Event data (empty by default)
│   ├── users.csv                       # User data (empty by default)
│   ├── tickets.csv                     # Ticket data (empty by default)
│
├── include/
│   ├── BookingManager.h
│   ├── Event.h
│   ├── FileManager.h
│   ├── Ticket.h
│   └── User.h
│
├── src/
│   ├── BookingManager.cpp
│   ├── Event.cpp
│   ├── FileManager.cpp
│   ├── main.cpp
│   ├── Ticket.cpp
│   └── User.cpp
│
├── README.md
└── Makefile (or CMakeLists.txt)
```

## Important Data Structures Used

- **vector**: Used for storing collections of events, users, and tickets in memory for easy iteration and management.
- **string**: Used for all textual data such as IDs, names, dates, and categories.
- **map** (future upgrade): Can be used for fast lookup of events, users, or tickets by their IDs.

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
