#pragma once

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Node class - holds a single element for the priority queue
// ------------------------------------------------------------
template <typename T>
class Node
{
public:
    int priority;       // priority value (lower = higher priority for less_cmp)
    T   data;           // stored data (template type)
    Node<T>* next;      // link to next node (singly-linked list)

    Node()
    {
        priority = 0;
        next = nullptr;
    }

    Node(int p, const T& value)
    {
        priority = p;
        data = value;
        next = nullptr;
    }
};
