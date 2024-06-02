#include <iostream>
#include <limits>

using namespace std;

int getValidNumberInput() {
    int num;
    while (!(cin >> num)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

void createMultiplicationTable(int startRange, int endRange, int startMultiplier, int endMultiplier) {
    cout << "Here is the multiplication table for " << startRange << " to " << endRange
         << " in the range of " << startMultiplier << " to " << endMultiplier << endl;
    cout << "X ";
    for (int i = startMultiplier; i <= endMultiplier; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = startRange; i <= endRange; ++i) {
        cout << i << " ";
        for (int j = startMultiplier; j <= endMultiplier; ++j) {
            cout << i * j << " ";
        }
        cout << endl;
    }
}

int main() {
    char choice;
    do {
        int startRange, endRange, startMultiplier, endMultiplier;
        cout << "Enter the starting range for Multiplication Table: ";
        startRange = getValidNumberInput();
        cout << "Enter the ending range for Multiplication Table: ";
        endRange = getValidNumberInput();
        cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
        startMultiplier = getValidNumberInput();
        cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
        endMultiplier = getValidNumberInput();

        createMultiplicationTable(startRange, endRange, startMultiplier, endMultiplier);

        cout << "Do you want to create another multiplication table? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the multiplication table generator!" << endl;

    return 0;
}
