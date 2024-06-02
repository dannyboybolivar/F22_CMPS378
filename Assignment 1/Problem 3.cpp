#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

double calculateBMI(double weight, int heightInInches) {
    return (703 * weight) / pow(heightInInches, 2);
}

string getBMICategory(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi < 24.9) {
        return "Normal weight";
    } else if (bmi < 29.9) {
        return "Overweight";
    } else {
        return "Obesity";
    }
}

int main() {
    string name, gender;
    int age, heightFeet, heightInches, totalHeightInches;
    double weight, bmi;

    cout << "Please enter your name: ";
    getline(cin, name);

    cout << "Please enter your age: ";
    while (!(cin >> age)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid age: ";
    }

    cout << "Please enter your gender (male/female): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    while (true) {
        getline(cin, gender);
        if (gender == "male" || gender == "female") {
            break;
        } else {
            cout << "Invalid input. Please enter either 'male' or 'female': ";
        }
    }

    cout << "Please enter your height in feet: ";
    while (!(cin >> heightFeet)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid height in feet: ";
    }

    cout << "Please enter your height in inches: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    while (!(cin >> heightInches)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid height in inches: ";
    }

    cout << "Please enter your weight in pounds: ";
    while (!(cin >> weight)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid weight in pounds: ";
    }

    totalHeightInches = (heightFeet * 12) + heightInches;
    bmi = calculateBMI(weight, totalHeightInches);
    string bmiCategory = getBMICategory(bmi);

    cout << "\nHi " << name << ",\n"
         << "You are a " << gender << ". You are " << age << " years old. You are currently "
         << heightFeet << "\'" << heightInches << "\" and you currently weigh " << weight
         << " pounds. Your BMI is " << bmi << ", which is " << bmiCategory << ".\n"
         << "Thank you for using the BMI Calculator!" << endl;

    return 0;
}
