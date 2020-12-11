#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int incoming_pktSize, outgoingRate, bucketSize, n;
    int store = 0;

    cout << "Enter the Bucket Size: ";
    cin >> bucketSize;

    cout << "Enter the Outgoing Rate: ";
    cin >> outgoingRate;

    cout << "Enter the Number of Input Packets: ";
    cin >> n;

    while (n)
    {
        cout << "\nEnter the Incoming Packet Size: ";
        cin >> incoming_pktSize;

        cout << "Incoming Packet Size is: " << incoming_pktSize << endl;

        if (incoming_pktSize <= (bucketSize - store))
        {
            store += incoming_pktSize;
            cout << "Bucket Buffer Size " << store << " out of " << bucketSize << endl;
        }
        else
        {
            cout << "Discarded " << (incoming_pktSize - (bucketSize - store)) << " Incoming Packet\n";
            cout << "Bucket Buffer Size " << store << " out of " << bucketSize << endl;
            store = bucketSize;
        }
        store -= outgoingRate;
        n--;
    }
    return 0;
}
