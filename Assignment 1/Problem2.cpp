#include <iostream>
#include <string>
#include <cctype> // for isdigit

using namespace std;

void displayMonthMeaning(int month) {
    switch(month) {
        case 1:
            cout << "The month of January means Janus" << endl;
            break;
        case 2:
            cout << "The month of February means purification" << endl;
            break;
        // Add cases for other months
        default:
            cout << "Invalid month" << endl;
    }
}

void displayDayMeaning(int day) {
    cout << "The " << day << "st of January means Self-Started" << endl;
    // Add meanings for other days
}

void displayYearMeaning(int year) {
    cout << "The year of " << year << " means that you are a millennial" << endl;
    // Add meanings for other years
}

int main() {
    char choice;
    do {
        int month, day, year;
        cout << "Welcome to Birthday Date Meaning Generator!" << endl;
        
        // Input month
        cout << "Please enter the month of your birthday: ";
        string monthStr;
        cin >> monthStr;
        if (monthStr.size() > 2) {
            cout << "Invalid input for month. Please enter a number between 1 and 12." << endl;
            continue;
        }
        for (char c : monthStr) {
            if (!isdigit(c)) {
                cout << "Invalid input for month. Please enter a number between 1 and 12." << endl;
                continue;
            }
        }
        month = stoi(monthStr);
        cin.ignore(); // Clear the newline character from the input buffer
        
        // Input day
        cout << "Please enter the day of your birthday: ";
        string dayStr;
        cin >> dayStr;
        if (dayStr.size() > 2) {
            cout << "Invalid input for day. Please enter a number between 1 and 31." << endl;
            continue;
        }
        for (char c : dayStr) {
            if (!isdigit(c)) {
                cout << "Invalid input for day. Please enter a number between 1 and 31." << endl;
                continue;
            }
        }
        day = stoi(dayStr);
        cin.ignore(); // Clear the newline character from the input buffer
        
        // Input year
        cout << "Please enter the year of your birthday: ";
        string yearStr;
        cin >> yearStr;
        if (yearStr.size() != 4) {
            cout << "Invalid input for year. Please enter a 4-digit number between 2000 and 2023." << endl;
            continue;
        }
        for (char c : yearStr) {
            if (!isdigit(c)) {
                cout << "Invalid input for year. Please enter a 4-digit number between 2000 and 2023." << endl;
                continue;
            }
        }
        year = stoi(yearStr);
        cin.ignore(); // Clear the newline character from the input buffer
        
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2000 || year > 2023) {
            cout << "Invalid input. Please enter valid values." << endl;
            continue; // Restart the loop
        }
        
        displayMonthMeaning(month);
        displayDayMeaning(day);
        displayYearMeaning(year);
        
        cout << "Would you like to try another one? (Y/N): ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
    } while (toupper(choice) == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}


