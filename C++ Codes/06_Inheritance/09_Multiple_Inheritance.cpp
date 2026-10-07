#include <iostream>
#include <string>
using namespace std;

class InventoryTracker
{
protected:
    string inventoryID;

public:
    int stockCount;

    InventoryTracker(string id)
    {
        inventoryID = id;
        stockCount = 0;
    }

    void logShipment(int quantity)
    {
        stockCount += quantity;
        cout << "Shipped " << quantity << " items for Inventory ID: " << inventoryID << "." << endl;
    }
};

class SalesRecord
{
protected:
    string salesID;

public:
    double unitPrice;

    SalesRecord(string id)
    {
        salesID = id;
        unitPrice = 10.0;
    }

    void applyDiscount(double percentage)
    {
        unitPrice -= unitPrice * (percentage / 100);
        cout << "Discount applied. New price: " << unitPrice << endl;
    }
};

class SpecializedWidget : public InventoryTracker, public SalesRecord
{
private:
    string productName;

public:
    SpecializedWidget(string name, string inventoryID, string salesID)
        : InventoryTracker(inventoryID), SalesRecord(salesID)
    {
        productName = name;
    }

    void fullSetup(int initialStock)
    {
        stockCount = initialStock;
        applyDiscount(15.0);
    }

    void printDetails()
    {
        cout << "\nSpecialized Widget Details" << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Inventory ID: " << inventoryID << " (Stock: " << stockCount << ")" << endl;
        cout << "Sales ID: " << salesID << endl;
        cout << "Unit Price: " << unitPrice << endl;
    }
};

int main()
{
    SpecializedWidget sw("SW-500", "INV-101", "S-555");

    sw.fullSetup(100);
    sw.logShipment(5);
    sw.printDetails();

    return 0;
}
