#include <iostream>
using namespace std;

class ParkGroup
{
private:
    int visitors;
    int tickets;

public:
    ParkGroup(int visitorCount, int ticketCount)
        : visitors(visitorCount), tickets(ticketCount) {}

    int getVisitors() const { return visitors; }
    int getTickets() const { return tickets; }

    friend int minimumRides(const ParkGroup groups[], int groupCount, int capacity);
};

int minimumRides(const ParkGroup groups[], int groupCount, int capacity)
{
    if (groupCount < 0 || capacity <= 0)
        return -1;

    int totalTickets = 0;
    for (int i = 0; i < groupCount; ++i)
    {
        if (groups[i].tickets < 0)
            return -1;
        totalTickets += groups[i].tickets;
    }
    return (totalTickets + capacity - 1) / capacity;
}

int main()
{
    const ParkGroup groups[] = {
        ParkGroup(4, 4), ParkGroup(3, 4), ParkGroup(1, 1), ParkGroup(2, 1)};
    const int groupCount = sizeof(groups) / sizeof(groups[0]);
    const int rideCapacity = 4;

    int rides = minimumRides(groups, groupCount, rideCapacity);
    if (rides < 0)
    {
        cerr << "Invalid group, ticket, or ride-capacity data.\n";
        return 1;
    }

    int totalVisitors = 0;
    int totalTickets = 0;
    for (int i = 0; i < groupCount; ++i)
    {
        totalVisitors += groups[i].getVisitors();
        totalTickets += groups[i].getTickets();
    }

    cout << "Total visitors: " << totalVisitors << '\n';
    cout << "Total ride tickets: " << totalTickets << '\n';
    cout << "Ride capacity: " << rideCapacity << '\n';
    cout << "Minimum rides needed: " << rides << '\n';
    return 0;
}
