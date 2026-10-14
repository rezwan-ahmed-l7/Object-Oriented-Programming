#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string itemName;
    int itemID;
    double price;
    int quantityInStock;

public:
    Item(int id, string name, double pr, int qty)
        : itemName(name), itemID(id), price(pr >= 0 ? pr : 0),
          quantityInStock(qty >= 0 ? qty : 0) {}

    void setDetails(int id, string name, double pr, int qty) {
        if (pr < 0 || qty < 0) {
            cout << "Price and stock quantity cannot be negative." << endl;
            return;
        }
        itemID = id;
        itemName = name;
        price = pr;
        quantityInStock = qty;
    }

    void displayDetails() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
    }

    void restock(int additionalQty) {
        if (additionalQty <= 0) {
            cout << "Restock quantity must be positive." << endl;
            return;
        }
        quantityInStock += additionalQty;
    }

    bool sell(int requestedQty) {
        if (requestedQty <= 0) {
            cout << "Sale quantity must be positive." << endl;
            return false;
        }
        if (requestedQty > quantityInStock) {
            cout << "Insufficient stock." << endl;
            return false;
        }
        quantityInStock -= requestedQty;
        return true;
    }
};

int main() {
    Item i1(1001, "Phone", 10000, 10);
    Item i2(1002, "Laptop", 70000, 5);
    i1.displayDetails();
    cout << endl;
    i2.displayDetails();
    return 0;
}