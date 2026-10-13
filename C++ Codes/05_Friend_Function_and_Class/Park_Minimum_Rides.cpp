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

    friend long long minimumRides(const ParkGroup groups[], int groupCount, int capacity);
};

long long minimumRides(const ParkGroup groups[], int groupCount, int capacity)
{
    if (groupCount < 0 || capacity <= 0 || (groupCount > 0 && groups == nullptr))
        return -1;

    long long totalTickets = 0;
    for (int i = 0; i < groupCount; ++i)
    {
        if (groups[i].visitors < 0 || groups[i].tickets < 0)
            return -1;
        totalTickets += groups[i].tickets;
    }

    return totalTickets / capacity + (totalTickets % capacity != 0);
}

int main()
{
    const ParkGroup groups[] = {
        ParkGroup(4, 4), ParkGroup(3, 4), ParkGroup(1, 1), ParkGroup(2, 1)};
    const int groupCount = static_cast<int>(sizeof(groups) / sizeof(groups[0]));
    const int rideCapacity = 4;

    const long long rides = minimumRides(groups, groupCount, rideCapacity);
    if (rides < 0)
    {
        cerr << "Invalid group, ticket, or ride-capacity data.\n";
        return 1;
    }

    int totalVisitors = 0;
    long long totalTickets = 0;
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