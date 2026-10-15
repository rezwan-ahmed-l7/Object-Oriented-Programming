#include <iostream>
using namespace std;

class Animal
{
public:
    virtual ~Animal() = default;

    virtual void sound() const
    {
        cout << "Animal makes a sound\n";
    }
};

class Dog : public Animal
{
public:
    void sound() const override { cout << "Dog barks\n"; }
};

class Cat : public Animal
{
public:
    void sound() const override { cout << "Cat meows\n"; }
};

int main()
{
    Dog dog;
    Cat cat;
    Animal *animal = &dog;
    animal->sound();
    animal = &cat;
    animal->sound();
    return 0;
}