#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class Shape {
protected:
    double width;
    double height;

public:
    Shape(double w, double h) : width(w), height(h) {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual void display() const {
        cout << "Shape: ";
    }

    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void display() const override {
        cout << "Shape: Rectangle" << endl;
    }
};

class Triangle : public Shape {
public:
    Triangle(double base, double height) : Shape(base, height) {}

    double area() const override {
        return 0.5 * width * height;
    }

    double perimeter() const override {
        // Assuming an equilateral triangle for simplicity
        return 3 * width;
    }

    void display() const override {
        cout << "Shape: Triangle" << endl;
    }
};

class Circle : public Shape {
public:
    Circle(double radius) : Shape(radius, 0) {}

    double area() const override {
        return M_PI * width * width;
    }

    double perimeter() const override {
        return 2 * M_PI * width;
    }

    void display() const override {
        cout << "Shape: Circle" << endl;
    }
};

class Square : public Shape {
public:
    Square(double side) : Shape(side, side) {}

    double area() const override {
        return width * width;
    }

    double perimeter() const override {
        return 4 * width;
    }

    void display() const override {
        cout << "Shape: Square" << endl;
    }
};

void displayMenu() {
    cout << "\nShape Calculation Program\n";
    cout << "1. Rectangle\n";
    cout << "2. Triangle\n";
    cout << "3. Circle\n";
    cout << "4. Square\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double width, height, radius, side;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "Enter width of the rectangle: ";
                cin >> width;
                cout << "Enter height of the rectangle: ";
                cin >> height;
                Rectangle rect(width, height);
                rect.display();
                cout << "Area: " << rect.area() << endl;
                cout << "Perimeter: " << rect.perimeter() << endl;
                break;
            }
            case 2: {
                cout << "Enter base of the triangle: ";
                cin >> width;
                cout << "Enter height of the triangle: ";
                cin >> height;
                Triangle tri(width, height);
                tri.display();
                cout << "Area: " << tri.area() << endl;
                cout << "Perimeter: " << tri.perimeter() << endl;
                break;
            }
            case 3: {
                cout << "Enter radius of the circle: ";
                cin >> radius;
                Circle circ(radius);
                circ.display();
                cout << "Area: " << circ.area() << endl;
                cout << "Perimeter: " << circ.perimeter() << endl;
                break;
            }
            case 4: {
                cout << "Enter side length of the square: ";
                cin >> side;
                Square sq(side);
                sq.display();
                cout << "Area: " << sq.area() << endl;
                cout << "Perimeter: " << sq.perimeter() << endl;
                break;
            }
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
