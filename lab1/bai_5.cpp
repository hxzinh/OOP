#include <iostream>

using namespace std;

/**
 * @brief Struct representing a date.
 * 
 * Contains day, month, and year as integer fields.
 */
struct Date {
    int day;
    int month;
    int year;
};

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
 * @brief Returns the number of days in a given month of a particular year.
 * 
 * Handles leap years for February.
 * 
 * @param month The month (1-12).
 * @param year The year to check.
 * @return The number of days in the given month.
 */
int daysInMonth(int month, int year) {
    if(month == 2) return isLeapYear(year) ? 29 : 28;
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    else return 30;
}

/**
 * @brief Computes the next day of a given date.
 * 
 * Increments the day, adjusting the month and year as necessary.
 * 
 * @param date The current date.
 * @return The date of the next day.
 */
Date nextDay(Date date) {
    date.day++;
    if (date.day > daysInMonth(date.month, date.year)) {
        date.day = 1;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

/**
 * @brief Computes the previous day of a given date.
 * 
 * Decrements the day, adjusting the month and year as necessary.
 * 
 * @param date The current date.
 * @return The date of the previous day.
 */
Date previousDay(Date date) {
    date.day--;
    if (date.day < 1) {
        date.month--;
        if (date.month < 1) {
            date.month = 12;
            date.year--;
        }
        date.day = daysInMonth(date.month, date.year);
    }
    return date;
}

/**
 * @brief Computes the day of the year for a given date.
 * 
 * Calculates the cumulative day number in the year, considering leap years.
 * 
 * @param date The date to evaluate.
 * @return The day of the year (1-366).
 */
int dayOfYear(Date date) {
    int days = date.day;
    for (int i = 1; i < date.month; i++) {
        days += daysInMonth(i, date.year);
    }
    return days;
}

/**
 * @brief Validates whether a given date is valid.
 * 
 * Checks if the year, month, and day are within valid ranges.
 * 
 * @param date The date to validate.
 * @return True if the date is valid, false otherwise.
 */
bool isValidDate(Date date) {
    if (date.year <= 0) return false;
    if (date.month < 1 || date.month > 12) return false;
    if (date.day < 1 || date.day > daysInMonth(date.month, date.year)) return false;
    return true;
}

/**
 * @brief Main function to interact with the user for date operations.
 * 
 * Prompts the user to input a valid date, then computes and prints the next day, previous day, and day of the year.
 */
int main() {
    Date date;

    do {
        cout << "Enter day: ";
        cin >> date.day;
        cout << "Enter month: ";
        cin >> date.month;
        cout << "Enter year: ";
        cin >> date.year;
    } while (!isValidDate(date));

    Date next = nextDay(date);
    Date prev = previousDay(date);
    int dayOfYearResult = dayOfYear(date);

    cout << "Next day: " << next.day << "/" << next.month << "/" << next.year << endl;
    cout << "Previous day: " << prev.day << "/" << prev.month << "/" << prev.year << endl;
    cout << "Day " << dayOfYearResult << " of the year" << endl;

    return 0;
}
