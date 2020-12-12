# Write a program for congestion control using Leaky bucket algorithm.

bucketSize = int(input("Enter the Bucket Size: "))
outgoingRate = int(input("Enter the Outgoing Rate: "))
n = int(input("Enter the Number of Input Packets: "))
store = 0

while n:
    incoming_pktSize = int(input("\nEnter the Incoming Packet Size: "))
    if incoming_pktSize <= (bucketSize - store):
        store += incoming_pktSize
        print("Bucket Buffer Size ", store, " out of ", bucketSize)
    else:
        print("Discarded ", (incoming_pktSize -
                             (bucketSize-store)), " Incoming Packets.")
        print("Bucket Buffer Size ", store, " out of ", bucketSize)
        store = bucketSize
    store -= outgoingRate
    n -= 1
