#include <iostream>
using namespace std;

class Chair {
public:
    virtual void sitOn() = 0;
    virtual ~Chair() {}
};

class Table {
public:
    virtual void putThings() = 0;
    virtual ~Table() {}
};

class ModernChair : public Chair {
public:
    void sitOn() override {
        cout << "Sitting on Modern Chair" << endl;
    }
};

class ModernTable : public Table {
public:
    void putThings() override {
        cout << "Putting things on Modern Table" << endl;
    }
};

class ClassicChair : public Chair {
public:
    void sitOn() override {
        cout << "Sitting on Classic Chair" << endl;
    }
};

class ClassicTable : public Table {
public:
    void putThings() override {
        cout << "Putting things on Classic Table" << endl;
    }
};

class FurnitureFactory {
public:
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;
    virtual ~FurnitureFactory() {}
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ModernChair();
    }

    Table* createTable() override {
        return new ModernTable();
    }
};

class ClassicFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ClassicChair();
    }

    Table* createTable() override {
        return new ClassicTable();
    }
};

int main() {
    FurnitureFactory* factory = new ModernFurnitureFactory();
    Chair* chair = factory->createChair();
    Table* table = factory->createTable();

    chair->sitOn();
    table->putThings();

    delete chair;
    delete table;
    delete factory;

    return 0;
}