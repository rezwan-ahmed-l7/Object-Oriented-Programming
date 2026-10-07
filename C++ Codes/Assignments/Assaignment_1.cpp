#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle()
    {
        length = 1;
        width = 1;
    }

    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    ~Rectangle()
    {
        cout << "Rectangle object destroyed." << endl;
    }

    int area()
    {
        return length * width;
    }

    int perimeter()
    {
        return 2 * (length + width);
    }

    void show()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl
             << endl;
    }
};

int main()
{
    cout << "Rectangle Area & Parameter\n"
         << endl;

    Rectangle r1;
    cout << "1st Rectangle:" << endl;
    r1.show();

    Rectangle r2(5, 3);
    cout << "2nd Rectangle:" << endl;
    r2.show();

    return 0;
}