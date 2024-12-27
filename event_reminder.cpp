// Include necessary libraries
#include <iostream> // Input-output stream library
#include <vector> // Vector library
#include <string> // String library
#include <ctime> // C time library
// Use standard namespace
using namespace std;

// Structure to store event details
struct Event {
    string name; // Event name
    string date; // Format: "YYYY-MM-DD"
};

// Global vector to store all events
vector<Event> events;

// Function prototypes
void addEvent(); // Function to add a new event
void displayEvents(); // Function to display all events
void removeEvent(); // Function to remove an event
void remindEvent(); // Function to remind today's events
bool isDateToday(const string& date); // Function to check if a date is today's date
void menu(); // Menu function to handle user input

// Main function to start the program
int main() {
    menu(); // Start the system with the menu
    return 0;
}

// Function to add a new event
void addEvent() {
    Event newEvent;
    cout << "Enter event name: ";
    cin.ignore(); // Clears input buffer

    getline(cin, newEvent.name); // Read event name
    cout << "Enter event date (YYYY-MM-DD): ";
    cin >> newEvent.date; // Read event date

    events.push_back(newEvent); // Add event to the list
    cout << "Event added successfully!\n";
}

// Function to display all events
void displayEvents() {
    if (events.empty()) {
        cout << "No events scheduled.\n";
        return;
    }

    cout << "Scheduled Events:\n";
    for (size_t i = 0; i < events.size(); ++i) {
        cout << i + 1 << ". " << events[i].name << " on " << events[i].date << "\n";
    }
}

// Function to remove an event
void removeEvent() {
    if (events.empty()) {
        cout << "No events to remove.\n";
        return;
    }

    int index;
    displayEvents(); // Show all events
    cout << "Enter the number of the event to remove: ";
    cin >> index; // Read the index of the event to remove

    if (index > 0 && index <= events.size()) {
        events.erase(events.begin() + index - 1); // Remove event
        cout << "Event removed successfully!\n";
    } else {
        cout << "Invalid selection.\n";
    }
}

// Function to remind today's events
void remindEvent() {
    if (events.empty()) {
        cout << "No events to remind.\n";
        return;
    }

    cout << "Today's Events:\n";
    bool found = false;
    for (const auto& event : events) {
        if (isDateToday(event.date)) {
            cout << "- " << event.name << " on " << event.date << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No events scheduled for today.\n";
    }
}

// Function to check if a date is today's date
bool isDateToday(const string& date) {
    time_t now = time(0); // Get current time
    tm* ltm = localtime(&now); // Convert to local time structure

    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm); // Format as YYYY-MM-DD
    return date == string(buffer); // Compare dates
}

