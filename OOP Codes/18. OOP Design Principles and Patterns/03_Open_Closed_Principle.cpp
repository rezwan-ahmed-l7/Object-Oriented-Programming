#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// OCP: ShapeAreaCalculator works with the Shape abstraction.
// New shapes can be added without changing the calculator.
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

double totalArea(const vector<unique_ptr<Shape>>& shapes) {
    double total = 0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(4, 3));
    shapes.push_back(make_unique<Circle>(2));

    cout << "Total area: " << totalArea(shapes) << endl;
    return 0;
}
