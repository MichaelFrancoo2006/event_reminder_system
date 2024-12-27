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

