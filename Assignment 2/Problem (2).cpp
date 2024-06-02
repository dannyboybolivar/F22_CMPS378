#include <iostream>
#include <string>
#include <cctype> // for isdigit

using namespace std;

struct Date {
    int month;
    int day;
    int year;
};

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
        Date birthday;
        cout << "Welcome to Birthday Date Meaning Generator!" << endl;
        
        // Input month
        bool validMonth = false;
        while (!validMonth) {
            cout << "Please enter the month of your birthday: ";
            string monthStr;
            cin >> monthStr;
            if (monthStr.size() > 2) {
                cout << "Invalid input for month. Please enter a number between 1 and 12." << endl;
                continue;
            }
            for (char c : monthStr) {
                if (!isdigit(c)) {
                    if (monthStr == "January") {
                        birthday.month = 1;
                        validMonth = true;
                        break;
                    } else if (monthStr == "February") {
                        birthday.month = 2;
                        validMonth = true;
                        break;
                    }
                    // Add cases for other month names
                    cout << "Invalid input for month. Please enter a number between 1 and 12." << endl;
                    break;
                }
            }
            if (!validMonth) {
                int month = stoi(monthStr);
                if (month < 1 || month > 12) {
                    cout << "Invalid input for month. Please enter a number between 1 and 12." << endl;
                    continue;
                }
                birthday.month = month;
                validMonth = true;
            }
        }
        
        // Input day
        bool validDay = false;
        while (!validDay) {
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
                    break;
                }
            }
            int day = stoi(dayStr);
            if (day < 1 || day > 31) {
                cout << "Invalid input for day. Please enter a number between 1 and 31." << endl;
                continue;
            }
            birthday.day = day;
            validDay = true;
        }
        
        // Input year
        bool validYear = false;
        while (!validYear) {
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
                    break;
                }
            }
            int year = stoi(yearStr);
            if (year < 2000 || year > 2023) {
                cout << "Invalid input for year. Please enter a 4-digit number between 2000 and 2023." << endl;
                continue;
            }
            birthday.year = year;
            validYear = true;
        }
        
        displayMonthMeaning(birthday.month);
        displayDayMeaning(birthday.day);
        displayYearMeaning(birthday.year);
        
        cout << "Would you like to try another one? (Y/N): ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
    } while (toupper(choice) == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}

