#include <iostream>
using namespace std;

// Any Shape can be substituted where a Shape is expected.
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.141592653589793 * radius * radius; }
};

void printArea(const Shape& shape) {
    cout << "Area: " << shape.area() << endl;
}

int main() {
    Rectangle rectangle(4, 5);
    Circle circle(2);
    printArea(rectangle);
    printArea(circle);
    return 0;
}