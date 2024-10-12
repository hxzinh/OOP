#include<bits/stdc++.h>

using namespace std;

/**
 * @brief Struct representing a flight.
 *
 * Contains flight ID, date, time, departure, and destination information.
 */
struct Flight {
    string flightId;
    string flightDate;
    string flightTime;
    string flightDeparture;
    string flightDestination;
};

/**
 * @brief Validates that the string contains only alphanumeric characters.
 *
 * Ensures the string contains only letters and numbers.
 *
 * @param str The string to validate.
 * @return True if the string is valid, false otherwise.
 */
bool checkString(const string& str) {
    bool check = false;
    for(char c : str) {
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            check = true;
        }
        else {
            return false;
        }
    }
    return check;
}

/**
 * @brief Validates the flight ID.
 *
 * Ensures the flight ID has a maximum length of 5 and contains only alphanumeric characters.
 *
 * @param id The flight ID to validate.
 * @return True if the flight ID is valid, false otherwise.
 */
bool isValidFlightId(const string& id) {
    if (id.length() > 5) return false;
    if(!checkString(id)) return false;
    return true;
}

/**
 * @brief Determines if a year is a leap year.
 *
 * A leap year is divisible by 4, but not by 100, unless it is also divisible by 400.
 *
 * @param year The year to check.
 * @return True if the year is a leap year, false otherwise.
 */
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Validates the flight date.
 *
 * Ensures the flight date is in the format DD/MM/YYYY and that the date fields are within valid ranges.
 *
 * @param date The date to validate.
 * @return True if the date is valid, false otherwise.
 */
bool isValidDate(const string& date) {
    // Simple date validation (DD/MM/YYYY)
    if (date.length() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if(year < 0) return false;
    return true;
}

/**
 * @brief Validates the flight time.
 *
 * Ensures the time is in the format HH:MM and that hours and minutes are within valid ranges.
 *
 * @param time The time to validate.
 * @return True if the time is valid, false otherwise.
 */
bool isValidTime(const string& time) {
    if (time.length() != 5 || time[2] != ':') return false;
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;
    return true;
}

/**
 * @brief Validates the location string.
 *
 * Ensures the location string is no more than 20 characters long and contains only alphanumeric characters.
 *
 * @param location The location string to validate.
 * @return True if the location is valid, false otherwise.
 */
bool isValidLocation(const string& location) {
    if (location.length() > 20) return false;
    if(!checkString(location)) return false;
    return true;
}

/**
 * @brief Inputs flight information from the user.
 *
 * Prompts the user to input flight ID, date, time, departure, and destination.
 * Validates each field before accepting it.
 *
 * @param flight The flight struct to fill with information.
 */
void Input(Flight& flight) {
    do {
        cout << "Enter flight ID: ";
        cin >> flight.flightId;
        if (!isValidFlightId(flight.flightId)) {
            cout << "Invalid flight ID. Please try again." << endl;
        }
    } while (!isValidFlightId(flight.flightId));

    do {
        cout << "Enter flight date (DD/MM/YYYY): ";
        cin >> flight.flightDate;
        if (!isValidDate(flight.flightDate)) {
            cout << "Invalid date. Please try again." << endl;
        }
    } while (!isValidDate(flight.flightDate));

    do {
        cout << "Enter flight time (HH:MM): ";
        cin >> flight.flightTime;
        if (!isValidTime(flight.flightTime)) {
            cout << "Invalid time. Please try again." << endl;
        }
    } while (!isValidTime(flight.flightTime));

    cin.ignore(); // Clear the newline character from the buffer

    do {
        cout << "Enter flight departure: ";
        getline(cin, flight.flightDeparture);
        if (!isValidLocation(flight.flightDeparture)) {
            cout << "Invalid departure. Please try again." << endl;
        }
    } while (!isValidLocation(flight.flightDeparture));

    do {
        cout << "Enter flight destination: ";
        getline(cin, flight.flightDestination);
        if (!isValidLocation(flight.flightDestination)) {
            cout << "Invalid destination. Please try again." << endl;
        }
    } while (!isValidLocation(flight.flightDestination));
}

/**
 * @brief Outputs flight information.
 *
 * Prints the flight ID, date, time, departure, and destination.
 *
 * @param flight The flight whose information is to be printed.
 */
void Output(const Flight& flight) {
    cout << "[+] Flight ID: " << flight.flightId << endl;
    cout << "[+] Flight Date: " << flight.flightDate << endl;
    cout << "[+] Flight Time: " << flight.flightTime << endl;
    cout << "[+] Flight Departure: " << flight.flightDeparture << endl;
    cout << "[+] Flight Destination: " << flight.flightDestination << endl;
}

/**
 * @brief Compares two flights by their ID.
 *
 * Used for sorting flights by flight ID in ascending order.
 *
 * @param a The first flight to compare.
 * @param b The second flight to compare.
 * @return True if flight a should come before flight b, false otherwise.
 */
bool cmp(const Flight& a, const Flight& b) {
    return a.flightId < b.flightId;
}

/**
 * @brief Displays the menu options.
 *
 * Lists the available options for managing flights.
 */
void menu() {
    cout << "1. Sort flight's information\n";
    cout << "2. Sort with start time\n";
    cout << "3. Search flight with ID\n";
    cout << "4. Search flight with departure\n";
    cout << "5. Search flight with destination\n";
    cout << "6. Exit\n";

    return;
}

/**
 * @brief Main function to manage flight information.
 *
 * Prompts the user to input flight information, displays options for sorting and searching, and allows the user to interact with the flight records.
 */
int main() {
    Flight flight[100];
    int n;
    cout << "Enter number of flight: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter the flight " << i << "th:\n";
        Input(flight[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << "The flight " << i << "th:\n";
        Output(flight[i]);
    }

    while(true) {
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1) {
            sort(flight + 1, flight + n + 1, cmp);
            for(int i = 1; i <= n; i++) {
                cout << "The flight " << i << "th:\n";
                Output(flight[i]);
            }
        }
        else if(choice == 2) {
            sort(flight + 1, flight + n + 1, [](const Flight& a, const Flight& b) {
                return a.flightTime < b.flightTime;
            });
            for(int i = 1; i <= n; i++) {
                cout << "The flight " << i << "th:\n";
                Output(flight[i]);
            }
        }
        else if(choice == 3) {
            string id;
            cout << "Enter the ID you want to search: ";
            cin.ignore();
            getline(cin, id);
            for(int i = 1; i <= n; i++) {
                if(flight[i].flightId == id) {
                    cout << "The flight " << i << "th:\n";
                    Output(flight[i]);
                }
            }
        }
        else if(choice == 4) {
            string departure;
            cout << "Enter the departure you want to search: ";
            cin.ignore();
            getline(cin, departure);
            for(int i = 1; i <= n; i++) {
                if(flight[i].flightDeparture == departure) {
                    cout << "The flight " << i << "th:\n";
                    Output(flight[i]);
                }
            }
        }
        else if(choice == 5) {
            string destination;
            cout << "Enter the destination you want to search: ";
            cin.ignore();
            getline(cin, destination);
            for(int i = 1; i <= n; i++) {
                if(flight[i].flightDestination == destination) {
                    cout << "The flight " << i << "th:\n";
                    Output(flight[i]);
                }
            }
        }
        else {
            break;
        }
    }

    return 0;
}
