#include <iostream>
#include <limits>

using namespace std;

struct MultiplicationTableParameters {
    int startRange;
    int endRange;
    int startMultiplier;
    int endMultiplier;
};

int getValidNumberInput() {
    int num;
    while (!(cin >> num)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

void createMultiplicationTable(const MultiplicationTableParameters& params) {
    cout << "Here is the multiplication table for " << params.startRange << " to " << params.endRange
         << " in the range of " << params.startMultiplier << " to " << params.endMultiplier << endl;
    cout << "X ";
    for (int i = params.startMultiplier; i <= params.endMultiplier; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = params.startRange; i <= params.endRange; ++i) {
        cout << i << " ";
        for (int j = params.startMultiplier; j <= params.endMultiplier; ++j) {
            cout << i * j << " ";
        }
        cout << endl;
    }
}

int main() {
    char choice;
    do {
        MultiplicationTableParameters params;
        cout << "Enter the starting range for Multiplication Table: ";
        params.startRange = getValidNumberInput();
        cout << "Enter the ending range for Multiplication Table: ";
        params.endRange = getValidNumberInput();
        cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
        params.startMultiplier = getValidNumberInput();
        cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
        params.endMultiplier = getValidNumberInput();

        createMultiplicationTable(params);

        cout << "Do you want to create another multiplication table? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the multiplication table generator!" << endl;

    return 0;
}
