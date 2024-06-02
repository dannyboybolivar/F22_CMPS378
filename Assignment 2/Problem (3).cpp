#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    string gender;
    int heightFeet;
    int heightInches;
    double weight;
};

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
    Person person;

    cout << "Please enter your name: ";
    getline(cin, person.name);

    cout << "Please enter your age: ";
    while (!(cin >> person.age)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid age: ";
    }

    cout << "Please enter your gender (male/female): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    while (true) {
        getline(cin, person.gender);
        if (person.gender == "male" || person.gender == "female") {
            break;
        } else {
            cout << "Invalid input. Please enter either 'male' or 'female': ";
        }
    }

    cout << "Please enter your height in feet: ";
    while (!(cin >> person.heightFeet)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid height in feet: ";
    }

    cout << "Please enter your height in inches: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    while (!(cin >> person.heightInches)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid height in inches: ";
    }

    cout << "Please enter your weight in pounds: ";
    while (!(cin >> person.weight)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid weight in pounds: ";
    }

    int totalHeightInches = (person.heightFeet * 12) + person.heightInches;
    double bmi = calculateBMI(person.weight, totalHeightInches);
    string bmiCategory = getBMICategory(bmi);

    cout << "\nHi " << person.name << ",\n"
         << "You are a " << person.gender << ". You are " << person.age << " years old. You are currently "
         << person.heightFeet << "\'" << person.heightInches << "\" and you currently weigh " << person.weight
         << " pounds. Your BMI is " << bmi << ", which is " << bmiCategory << ".\n"
         << "Thank you for using the BMI Calculator!" << endl;

    return 0;
}
