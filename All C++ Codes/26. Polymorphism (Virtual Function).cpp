#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Area of Shape" << endl;
    }
};

class Rectangle : public Shape {
    int length, width;

public:
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

class Circle : public Shape {
    int radius;

public:
    Circle(int r) {
        radius = r;
    }

    void area() override {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

int main() {
    Shape *s;
    Rectangle r(10, 5);
    Circle c(7);

    s = &r;
    s->area();

    s = &c;
    s->area();

    return 0;
}