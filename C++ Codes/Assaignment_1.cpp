#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;
public:
    Rectangle() : length(1), width(1) {}
    Rectangle(int l, int w) : length(l >= 0 ? l : 0), width(w >= 0 ? w : 0) {
        if (l < 0 || w < 0)
            cout << "Negative dimensions are invalid; negative values were set to 0." << endl;
    }
    ~Rectangle() { cout << "Rectangle object destroyed." << endl; }
    int area() const { return length * width; }
    int perimeter() const { return 2 * (length + width); }
    void show() const {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl << endl;
    }
};

int main() {
    cout << "Rectangle Area & Perimeter\n" << endl;
    Rectangle r1;
    cout << "1st Rectangle:" << endl;
    r1.show();
    Rectangle r2(5, 3);
    cout << "2nd Rectangle:" << endl;
    r2.show();
    return 0;
}