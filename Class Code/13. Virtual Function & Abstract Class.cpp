#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    int length{};
    int width{};

public:
    void setValues(int l, int w) {
        length = l;
        width = w;
    }

    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

class Circle : public Shape {
    int radius{};

public:
    void setValue(int r) {
        radius = r;
    }

    void area() override {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

int main() {
    Rectangle r;
    Circle c;

    r.setValues(10, 5);
    c.setValue(7);

    Shape* s = &r;
    s->area();

    s = &c;
    s->area();

    return 0;
}
