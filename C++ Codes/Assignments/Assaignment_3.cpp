#include <iostream>
#include <string>
using namespace std;

class Configuration
{
private:
    int a;
    double b;

public:
    Configuration()
    {
        a = 0;
        b = 0.0;
    }

    void settingA(int x)
    {
        a = x;
    }

    void settingB(double y)
    {
        b = y;
    }

    void printingConfig()
    {
        cout << "Setting A: " << a << endl;
        cout << "Setting B: " << b << endl;
    }
};

class Logger
{
protected:
    int logCount;

public:
    Logger()
    {
        logCount = 0;
    }

    void recordLog(string message)
    {
        logCount++;
        cout << "[Log #" << logCount << "] " << message << endl;
    }
};

class AppManager : public Configuration, public Logger
{
public:
    void initialize()
    {

        printingConfig();
        recordLog("Starting application");
        recordLog("Loading user settings");
    }

    int getLogCount()
    {
        return logCount;
    }
};

int main()
{
    AppManager app;

    app.settingA(10);
    app.settingB(5.5);

    cout << "Initial Configuration\n"
         << endl;
    app.initialize();

    cout << "Total Logs: " << app.getLogCount() << endl
         << endl;

    app.settingA(20);

    cout << "Updated Configuration" << endl;
    app.initialize();

    return 0;
}
