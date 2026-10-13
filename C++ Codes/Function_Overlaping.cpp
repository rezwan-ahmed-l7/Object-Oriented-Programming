#include <bits/stdc++.h>
using namespace std;
class Number
{

	int num1;
	int num2;
	int num3;
	int num4;

public:
	Number(int a, int b)
	{
		num1 = a;
		num2 = b;
		num3 = 0;
		num4 = 0;
	}

	Number(int a, int b, int c)
	{
		num1 = a;
		num2 = b;
		num3 = c;
		num4 = 0;
	}

	Number(int a, int b, int c, int d)
	{
		num1 = a;
		num2 = b;
		num3 = c;
		num4 = d;
	}

	void display()
	{
		cout << "Numbers: " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << endl;
	}
};

int main()
{
	Number obj1(10, 20);
	Number obj2(10, 20, 30);
	Number obj3(10, 20, 30, 40);

	cout << "Object 1 (2 parameters): ";
	obj1.display();

	cout << "Object 2 (3 parameters): ";
	obj2.display();

	cout << "Object 3 (4 parameters): ";
	obj3.display();

	return 0;
}