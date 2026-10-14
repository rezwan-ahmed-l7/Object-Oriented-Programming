#include <iostream>
using namespace std;

// LSP: every Shape subtype can be used wherever Shape is expected,
// while preserving the area() contract.
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
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
    Rectangle rectangle(4, 3);
    Circle circle(2);
    printArea(rectangle);
    printArea(circle);
    return 0;
}
