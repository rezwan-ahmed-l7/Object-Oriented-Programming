#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    string itemName;
    int itemID;
    double price;
    int quantityInStock;

public:
    Item(int id, string name, double pr, int qty)
    {
        itemID = id;
        itemName = name;
        price = pr;
        quantityInStock = qty;
    }

    void setDetails(int id, string name, double pr, int qty)
    {
        itemID = id;
        itemName = name;
        price = pr;
        quantityInStock = qty;
    }

    void displayDetails()
    {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
    }

    void restock(int additionalQty)
    {
        quantityInStock += additionalQty;
    }

    bool sell(int requestedQty)
    {
        if (requestedQty <= quantityInStock)
        {
            quantityInStock -= requestedQty;
            return true;
        }
        return false;
    }
};

int main()
{
    Item i1(1001, "Phone", 10000, 10);
    Item i2(1002, "Laptop", 70000, 5);

    i1.displayDetails();
    cout << endl;
    i2.displayDetails();
    return 0;
}
