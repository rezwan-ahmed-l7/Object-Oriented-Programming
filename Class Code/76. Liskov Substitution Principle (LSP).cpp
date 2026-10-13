#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

// Any valid Shape can be substituted where a Shape is expected.
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (!isfinite(w) || !isfinite(h) || w < 0.0 || h < 0.0)
            throw invalid_argument("Rectangle dimensions must be finite and non-negative.");
        if (!isfinite(w * h))
            throw invalid_argument("Rectangle area is too large to represent.");
    }
    double area() const override { return width * height; }
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {
        if (!isfinite(r) || r < 0.0)
            throw invalid_argument("Circle radius must be finite and non-negative.");
        const double result = 3.141592653589793 * r * r;
        if (!isfinite(result))
            throw invalid_argument("Circle area is too large to represent.");
    }
    double area() const override { return 3.141592653589793 * radius * radius; }
};

void printArea(const Shape& shape) {
    cout << "Area: " << shape.area() << endl;
}

int main() {
    try {
        const Rectangle rectangle(4, 5);
        const Circle circle(2);
        printArea(rectangle);
        printArea(circle);
    } catch (const invalid_argument& error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}