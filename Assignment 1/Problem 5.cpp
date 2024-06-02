#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero" << endl;
        return 0;
    }
    return a / b;
}

double my_modulus(double a, double b) {
    if (b == 0) {
        cout << "Error: Modulus by zero" << endl;
        return 0;
    }
    return fmod(a, b);
}

double exponent(double base, double exp) {
    return pow(base, exp);
}

double sine(double x) {
    return sin(x);
}

// Add other mathematical functions as needed

int main() {
    char operand;
    double num1, num2;
    char choice;

    cout << "Welcome to Math Calculator!" << endl;

    do {
        cout << "Enter a math problem (e.g., 5 + 3, sin 0.5, log10 100): ";
        cin >> num1 >> operand >> num2;

        if (cin.fail()) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        double result;

        switch (operand) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            case '%':
                result = my_modulus(num1, num2);
                break;
            case '^':
                result = exponent(num1, num2);
                break;
            case 's':
                result = sine(num1);
                break;
            // Add cases for other operands
            default:
                cout << "Invalid operand. Please try again." << endl;
                continue;
        }

        cout << "Result: " << result << endl;

        cout << "Do you want to input a new problem? (y/n): ";
        cin >> choice;

        while (choice != 'y' && choice != 'n') {
            cout << "Invalid choice. Please enter 'y' or 'n': ";
            cin >> choice;
        }

    } while (choice == 'y');

    cout << "Thank you for using the Math Calculator!" << endl;

    return 0;
}

