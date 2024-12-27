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

