#include <iostream>
using namespace std;

int main() {
    cout << "SOLID: five principles for maintainable object-oriented design\n\n";
    cout << "S - Single Responsibility Principle (SRP)\n";
    cout << "    A class should have one clear reason to change.\n";
    cout << "    Example: Report stores report data; ReportPrinter prints it.\n\n";
    cout << "O - Open/Closed Principle (OCP)\n";
    cout << "    Extend behavior without repeatedly modifying stable code.\n";
    cout << "    Example: add a new Shape implementation to support a new shape.\n\n";
    cout << "L - Liskov Substitution Principle (LSP)\n";
    cout << "    A subtype should be usable wherever its base type is expected,\n";
    cout << "    without breaking the base type's promised behavior.\n\n";
    cout << "I - Interface Segregation Principle (ISP)\n";
    cout << "    Prefer small, focused interfaces over one interface that forces\n";
    cout << "    classes to implement methods they do not need.\n\n";
    cout << "D - Dependency Inversion Principle (DIP)\n";
    cout << "    High-level policy should depend on abstractions, not concrete details.\n";
    cout << "    Example: a notification service depends on a MessageSender interface.\n\n";
    cout << "See the separate OCP, LSP, ISP, and DIP example files for runnable code.\n";
    return 0;
}
