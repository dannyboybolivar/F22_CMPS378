#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int performOperation(int num1, int num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '^':
            return pow(num1, num2);
        default:
            return 0;
    }
}

int findClosingParenthesis(const string& problem, int start) {
    int count = 1;
    for (int i = start + 1; i < problem.length(); i++) {
        if (problem[i] == '(')
            count++;
        else if (problem[i] == ')')
            count--;
        if (count == 0)
            return i;
    }
    return -1; // No closing parenthesis found
}

int evaluateExpression(const string& expression) {
    int result = 0;
    char op = '+';
    int num = 0;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (isDigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '(') {
            int closingIndex = findClosingParenthesis(expression, i);
            int subResult = evaluateExpression(expression.substr(i + 1, closingIndex - i - 1));
            num = subResult;
            i = closingIndex;
        } else if (isOperator(c)) {
            result = performOperation(result, num, op);
            op = c;
            num = 0;
        }
    }
    result = performOperation(result, num, op);
    return result;
}

int main() {
    char choice;
    do {
        string problem;
        cout << "Enter a problem to solve: ";
        getline(cin, problem);
        
        int answer = evaluateExpression(problem);
        
        cout << "The answer to this problem is " << answer << "." << endl;
        cout << "Would you like to solve another problem? (Y/N) ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
    } while (toupper(choice) == 'Y');

    cout << "Thank you for using this calculator!" << endl;

    return 0;
}
