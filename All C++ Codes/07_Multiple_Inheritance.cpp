#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryTracker
{
protected:
    string inventoryID;

public:
    int stockCount;

    explicit InventoryTracker(string id) : inventoryID(id), stockCount(0) {}

    void logShipment(int quantity)
    {
        if (quantity <= 0)
        {
            cout << "Shipment quantity must be positive.\n";
            return;
        }
        stockCount += quantity;
        cout << "Shipped " << quantity << " items for Inventory ID: " << inventoryID << ".\n";
    }
};

class SalesRecord
{
protected:
    string salesID;

public:
    double unitPrice;

    explicit SalesRecord(string id) : salesID(id), unitPrice(10.0) {}

    void applyDiscount(double percentage)
    {
        if (percentage < 0.0 || percentage > 100.0)
        {
            cout << "Discount must be between 0 and 100 percent.\n";
            return;
        }
        unitPrice -= unitPrice * (percentage / 100.0);
        cout << fixed << setprecision(2) << "Discount applied. New price: " << unitPrice << '\n';
    }
};

class SpecializedWidget : public InventoryTracker, public SalesRecord
{
private:
    string productName;

public:
    SpecializedWidget(string name, string inventoryId, string salesId)
        : InventoryTracker(inventoryId), SalesRecord(salesId), productName(name) {}

    void fullSetup(int initialStock)
    {
        if (initialStock < 0)
        {
            cout << "Initial stock cannot be negative.\n";
            return;
        }
        stockCount = initialStock;
        applyDiscount(15.0);
    }

    void printDetails() const
    {
        cout << "\nSpecialized Widget Details\n";
        cout << "Product Name: " << productName << '\n';
        cout << "Inventory ID: " << inventoryID << " (Stock: " << stockCount << ")\n";
        cout << "Sales ID: " << salesID << '\n';
        cout << fixed << setprecision(2) << "Unit Price: " << unitPrice << '\n';
    }
};

int main()
{
    SpecializedWidget widget("SW-500", "INV-101", "S-555");
    widget.fullSetup(100);
    widget.logShipment(5);
    widget.printDetails();
    return 0;
}