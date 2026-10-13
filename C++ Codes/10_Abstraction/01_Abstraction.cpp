#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Shape
{
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w)
    {
        if (!isfinite(l) || !isfinite(w) || l < 0.0 || w < 0.0)
            throw invalid_argument("Rectangle dimensions must be finite and non-negative.");
        if (!isfinite(l * w))
            throw invalid_argument("Rectangle area is too large to represent.");
    }

    double area() const override { return length * width; }
};

int main()
{
    try
    {
        const Rectangle rectangle(10, 5);
        cout << "Area of Rectangle: " << rectangle.area() << '\n';
    }
    catch (const invalid_argument &error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}