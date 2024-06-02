#include <iostream>
#include <limits>

using namespace std;

void recursiveBubbleSort(int arr[], int n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    recursiveBubbleSort(arr, n - 1);
}

double calculateAverage(int arr[], int n, int pointsPossible) {
    int totalScore = 0;
    for (int i = 0; i < n; i++) {
        totalScore += arr[i];
    }
    return (static_cast<double>(totalScore) / (n * pointsPossible)) * 100;
}

int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    string courseDept, courseNum, courseName;
    int pointsPossible, numStudents;

    cout << "Welcome to Grade Calculator!\n";
    cout << "Enter the course dept: ";
    cin >> courseDept;
    cout << "Enter the course number: ";
    cin >> courseNum;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    cout << "Enter the course name: ";
    getline(cin, courseName);

    while (true) {
        cout << "Enter the number of students that will be scored: ";
        cin >> numStudents;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid number of students.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Enter points possible: ";
        cin >> pointsPossible;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number for points possible.\n";
        } else {
            break;
        }
    }

    int *scores = new int[numStudents];
    for (int i = 0; i < numStudents; i++) {
        while (true) {
            cout << "Enter the score for student " << (i + 1) << ": ";
            cin >> scores[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid score.\n";
            } else {
                break;
            }
        }
    }

    recursiveBubbleSort(scores, numStudents);

    double averageScore = calculateAverage(scores, numStudents, pointsPossible);
    int minScore = findMinimum(scores, numStudents);
    int maxScore = findMaximum(scores, numStudents);

    cout << "Course: " << courseDept << " " << courseNum << ": " << courseName << endl;
    cout << "Scores: ";
    for (int i = 0; i < numStudents; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    cout << "Average: " << averageScore << "%" << endl;
    cout << "Lowest Score: " << minScore << endl;
    cout << "Highest Score: " << maxScore << endl;

    delete[] scores;

    cout << "Thank you for using the grade calculator!" << endl;

    return 0;
}
