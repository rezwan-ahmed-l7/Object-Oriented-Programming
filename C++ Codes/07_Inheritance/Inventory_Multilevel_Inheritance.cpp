#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <string>
using namespace std;

class InventoryTracker
{
protected:
    string inventoryId;
    int stockCount;

public:
    explicit InventoryTracker(const string &id, int initialStock = 0)
        : inventoryId(id), stockCount(initialStock)
    {
        if (initialStock < 0)
            throw invalid_argument("Initial stock cannot be negative.");
    }

    void logShipment(int quantity)
    {
        if (quantity <= 0)
        {
            cout << "Shipment quantity must be positive.\n";
            return;
        }
        if (quantity > numeric_limits<int>::max() - stockCount)
        {
            cout << "Shipment rejected: stock count would overflow.\n";
            return;
        }
        stockCount += quantity;
        cout << "Received " << quantity << " item(s) for inventory ID: " << inventoryId << '\n';
    }
};

class SalesRecord : public InventoryTracker
{
protected:
    string salesId;
    double unitPrice;

public:
    SalesRecord(const string &id, const string &saleId, double price, int initialStock)
        : InventoryTracker(id, initialStock), salesId(saleId), unitPrice(price)
    {
        if (!isfinite(price) || price < 0.0)
            throw invalid_argument("Unit price must be finite and non-negative.");
    }

    void applyDiscount(double percentage)
    {
        if (!isfinite(percentage) || percentage < 0.0 || percentage > 100.0)
        {
            cout << "Discount must be a finite value between 0 and 100 percent.\n";
            return;
        }
        unitPrice *= (1.0 - percentage / 100.0);
        cout << "Discount applied. New price: " << fixed << setprecision(2) << unitPrice << '\n';
    }
};

class SpecializedWidget : public SalesRecord
{
private:
    string productName;

public:
    SpecializedWidget(const string &name, const string &inventoryId, const string &saleId,
                      double price, int initialStock)
        : SalesRecord(inventoryId, saleId, price, initialStock), productName(name) {}

    void displayDetails() const
    {
        cout << "Product name: " << productName << '\n'
             << "Inventory ID: " << inventoryId << '\n'
             << "Stock count: " << stockCount << '\n'
             << "Sales ID: " << salesId << '\n'
             << "Unit price: " << fixed << setprecision(2) << unitPrice << '\n';
    }
};

int main()
{
    try
    {
        SpecializedWidget item("SW-500", "INV-101", "S-555", 10.00, 100);
        item.applyDiscount(15.0);
        item.logShipment(5);
        cout << '\n';
        item.displayDetails();
    }
    catch (const invalid_argument &error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}