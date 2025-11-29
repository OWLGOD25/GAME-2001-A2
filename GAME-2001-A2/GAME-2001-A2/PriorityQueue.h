#pragma once

#include "LinkedList.h"
#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Comparator functors for priorities
// ------------------------------------------------------------

// lower number means "higher priority" (default)
struct less_cmp
{
    bool operator()(int lhs, int rhs) const
    {
        return lhs < rhs;
    }
};

// higher number means "higher priority"
struct greater_cmp
{
    bool operator()(int lhs, int rhs) const
    {
        return lhs > rhs;
    }
};

// ------------------------------------------------------------
// PriorityQueue<T, Compare>
//   Wraps LinkedList<T> and uses Compare to keep nodes sorted.
// ------------------------------------------------------------
template <typename T, typename Compare = less_cmp>
class PriorityQueue
{
public:
    PriorityQueue()
    {
        // default-constructed Compare
    }

    bool Empty() const
    {
        return list.Empty();
    }

    size_t Size() const
    {
        return list.Size();
    }

    // --------------------------------------------------------
    // Push - insert an element with a given priority
    // --------------------------------------------------------
    void Push(int priority, const T& value)
    {
        list.InsertSorted(priority, value, compare);
    }

    // --------------------------------------------------------
    // Pop - remove the highest-priority element (front of list)
    // --------------------------------------------------------
    void Pop()
    {
        list.PopFront();
    }

    // --------------------------------------------------------
    // Front - return the highest-priority element
    // (assumes queue is not empty)
    // --------------------------------------------------------
    T& Front()
    {
        return list.FrontData();
    }

    const T& Front() const
    {
        return list.FrontData();
    }

    int FrontPriority() const
    {
        return list.FrontPriority();
    }

    // --------------------------------------------------------
    // Clear the whole queue
    // --------------------------------------------------------
    void Clear()
    {
        list.Clear();
    }

private:
    LinkedList<T> list;
    Compare       compare;
};
