#pragma once

#include "Node.h"
#include <cstddef>   // size_t
using namespace std;

// ------------------------------------------------------------
// LinkedList<T> - simple singly linked list to back PriorityQueue
// ------------------------------------------------------------
template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        listSize = 0;
    }

    ~LinkedList()
    {
        Clear();
    }

    bool Empty() const
    {
        return head == nullptr;
    }

    size_t Size() const
    {
        return listSize;
    }

    // ------------------------------------------------------------
    // Get the data at the front of the list (assumes not empty)
    // ------------------------------------------------------------
    T& FrontData()
    {
        return head->data;
    }

    const T& FrontData() const
    {
        return head->data;
    }

    int FrontPriority() const
    {
        return head->priority;
    }

    // ------------------------------------------------------------
    // PopFront - remove the first node from the list
    // ------------------------------------------------------------
    void PopFront()
    {
        if (head == nullptr)
            return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        listSize--;
    }

    // ------------------------------------------------------------
    // Clear the list
    // ------------------------------------------------------------
    void Clear()
    {
        while (!Empty())
        {
            PopFront();
        }
    }

    // ------------------------------------------------------------
    // PushFront - insert a node at the front (not used by PQ,
    // but handy for extra testing if you want)
    // ------------------------------------------------------------
    void PushFront(int priority, const T& value)
    {
        Node<T>* node = new Node<T>(priority, value);
        node->next = head;
        head = node;
        listSize++;
    }

    // ------------------------------------------------------------
    // InsertSorted - insert a new node in priority order.
    // Compare is a functor like less_cmp or greater_cmp.
    //
    // For less_cmp (a < b):
    //   lower priority number comes first (higher priority).
    //
    // We insert BEFORE the first node that is "not strictly ahead"
    // of our new priority (i.e., before first node with equal or
    // lower priority in the "less_cmp" sense).
    // ------------------------------------------------------------
    template <typename Compare>
    void InsertSorted(int priority, const T& value, Compare comp)
    {
        Node<T>* newNode = new Node<T>(priority, value);

        // Insert at front if list is empty or
        // the current head should NOT be before the new node
        // according to the comparator.
        if (head == nullptr || !comp(head->priority, priority))
        {
            newNode->next = head;
            head = newNode;
            listSize++;
            return;
        }

        // Walk forward while the next node still has "higher" priority
        // than the new one according to comp.
        Node<T>* current = head;
        while (current->next != nullptr &&
            comp(current->next->priority, priority))
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        listSize++;
    }

private:
    Node<T>* head;
    size_t   listSize;

    // PriorityQueue will use our internals directly
    template <typename U, typename Compare>
    friend class PriorityQueue;
};
