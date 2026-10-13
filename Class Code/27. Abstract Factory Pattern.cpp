#include <iostream>
#include <memory>
using namespace std;

class Chair {
public:
    virtual void sitOn() const = 0;
    virtual ~Chair() = default;
};

class Table {
public:
    virtual void putThings() const = 0;
    virtual ~Table() = default;
};

class ModernChair : public Chair {
public:
    void sitOn() const override {
        cout << "Sitting on Modern Chair" << endl;
    }
};

class ModernTable : public Table {
public:
    void putThings() const override {
        cout << "Putting things on Modern Table" << endl;
    }
};

class ClassicChair : public Chair {
public:
    void sitOn() const override {
        cout << "Sitting on Classic Chair" << endl;
    }
};

class ClassicTable : public Table {
public:
    void putThings() const override {
        cout << "Putting things on Classic Table" << endl;
    }
};

class FurnitureFactory {
public:
    virtual unique_ptr<Chair> createChair() const = 0;
    virtual unique_ptr<Table> createTable() const = 0;
    virtual ~FurnitureFactory() = default;
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    unique_ptr<Chair> createChair() const override {
        return make_unique<ModernChair>();
    }

    unique_ptr<Table> createTable() const override {
        return make_unique<ModernTable>();
    }
};

class ClassicFurnitureFactory : public FurnitureFactory {
public:
    unique_ptr<Chair> createChair() const override {
        return make_unique<ClassicChair>();
    }

    unique_ptr<Table> createTable() const override {
        return make_unique<ClassicTable>();
    }
};

int main() {
    unique_ptr<FurnitureFactory> factory = make_unique<ModernFurnitureFactory>();
    unique_ptr<Chair> chair = factory->createChair();
    unique_ptr<Table> table = factory->createTable();

    chair->sitOn();
    table->putThings();

    return 0;
}