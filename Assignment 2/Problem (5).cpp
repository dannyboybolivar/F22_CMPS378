#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

struct MathProblem {
    char operand;
    double num1;
    double num2;
};

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
    char choice;

    cout << "Welcome to Math Calculator!" << endl;

    do {
        MathProblem problem;

        cout << "Enter a math problem (e.g., 5 + 3, sin 0.5, log10 100): ";
        cin >> problem.num1 >> problem.operand >> problem.num2;

        if (cin.fail()) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        double result;

        switch (problem.operand) {
            case '+':
                result = add(problem.num1, problem.num2);
                break;
            case '-':
                result = subtract(problem.num1, problem.num2);
                break;
            case '*':
                result = multiply(problem.num1, problem.num2);
                break;
            case '/':
                result = divide(problem.num1, problem.num2);
                break;
            case '%':
                result = my_modulus(problem.num1, problem.num2);
                break;
            case '^':
                result = exponent(problem.num1, problem.num2);
                break;
            case 's':
                result = sine(problem.num1);
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
