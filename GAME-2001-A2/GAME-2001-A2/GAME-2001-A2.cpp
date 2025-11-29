// GAME-2001-A2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

// ------------------------------------------------------------
// Student Info
// ------------------------------------------------------------
const string studentName = "Tyron Fajardo";
const string studentNumber = "101542713";

// ------------------------------------------------------------
// Example user-defined type for testing
// ------------------------------------------------------------
struct NetworkMessage
{
    int id;
    string payload;
};

// Simple print helper for NetworkMessage
ostream& operator<<(ostream& os, const NetworkMessage& msg)
{
    os << "[id=" << msg.id << ", payload=\"" << msg.payload << "\"]";
    return os;
}

// ------------------------------------------------------------
// Helper functions to run different tests
// ------------------------------------------------------------
template <typename T, typename Compare>
void DrainAndPrint(PriorityQueue<T, Compare>& pq, const string& title)
{
    cout << "------------------------------------------------------------\n";
    cout << title << "\n";
    cout << "------------------------------------------------------------\n";

    while (!pq.Empty())
    {
        cout << "Priority: " << pq.FrontPriority()
            << " | Value: " << pq.Front() << "\n";
        pq.Pop();
    }

    cout << endl;
}

// ------------------------------------------------------------
// main - test the priority queue with different data types
// ------------------------------------------------------------
int main()
{
    cout << "Assignment 2 - Priority Queue (Linked List)\n";
    cout << "Student: " << studentName << " (" << studentNumber << ")\n\n";

    // -------------------- Test 1: int + less_cmp --------------------
    PriorityQueue<int, less_cmp> intAsc;
    intAsc.Push(5, 100);
    intAsc.Push(1, 200);
    intAsc.Push(3, 300);
    intAsc.Push(3, 400);     // same priority as 3, should be before first node with >= 3

    DrainAndPrint(intAsc, "Int Queue - ascending priorities (less_cmp)");

    // -------------------- Test 2: int + greater_cmp -----------------
    PriorityQueue<int, greater_cmp> intDesc;
    intDesc.Push(5, 100);
    intDesc.Push(1, 200);
    intDesc.Push(3, 300);
    intDesc.Push(7, 400);

    DrainAndPrint(intDesc, "Int Queue - descending priorities (greater_cmp)");

    // -------------------- Test 3: string + less_cmp -----------------
    PriorityQueue<string, less_cmp> stringPQ;
    stringPQ.Push(10, "low-ish priority");
    stringPQ.Push(1, "very important");
    stringPQ.Push(5, "medium");
    stringPQ.Push(1, "another very important");

    DrainAndPrint(stringPQ, "String Queue - ascending priorities (less_cmp)");

    // -------------------- Test 4: NetworkMessage + less_cmp --------
    PriorityQueue<NetworkMessage, less_cmp> msgPQ;
    msgPQ.Push(2, { 1, "Player joined" });
    msgPQ.Push(5, { 2, "Chat message" });
    msgPQ.Push(1, { 3, "Server warning" });
    msgPQ.Push(2, { 4, "Inventory update" });

    DrainAndPrint(msgPQ, "NetworkMessage Queue - ascending priorities (less_cmp)");

    cout << "All tests complete.\n";

    return 0;
}


