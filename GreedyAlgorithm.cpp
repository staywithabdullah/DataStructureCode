#include <bits/stdc++.h>
using namespace std;
struct CommunicationDevice
{
    string id;
    double weight;
    double range;
    double cost;
};
bool compare(CommunicationDevice a, CommunicationDevice b)
{
    double result1 = (double)a.range / (double)a.cost;
    double result2 = (double)b.range / (double)b.cost;
    if (result1 > result2)
        return true;
    else
        return false;
}
void Knapsack(vector<CommunicationDevice> &devices, int budget)
{
    sort(devices.begin(), devices.end(), compare);
    double totalCommunicationRange = 0;
    double totalCost = 0;
    cout << "\nSelected Devices:" << endl;
    for (CommunicationDevice &device : devices)
    {
        if (device.cost <= budget)
        {
            totalCommunicationRange += device.range;
            totalCost += device.cost;
            cout << device.id << endl;
            budget -= device.cost;
        }
    }
    cout << "\nTotal Communication Range: " << totalCommunicationRange << endl;
    cout << "Total Cost: " << totalCost << endl;
}
int main()
{
    int N;
    cin >> N;
    vector<CommunicationDevice> devices(N);
    for (int i = 0; i < N; i++)
    {
        cin >> devices[i].id;
        cin >> devices[i].weight;
        cin >> devices[i].range;
        cin >> devices[i].cost;
    }
    int budget;
    cin >> budget;
    Knapsack(devices, budget);
    return 0;
}
