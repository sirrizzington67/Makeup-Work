#include "Queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Initializes an empty queue
Queue::Queue() : itsHead(0), itsTail(0), itsSize(0) {}

void Queue::enqueue(int item) {
    if (isFull())
        throw runtime_error("Queue is full.");
    data[itsTail] = item;
    itsTail = (itsTail + 1) % CAP; // Wrap around to front if at end
    itsSize++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw runtime_error("Queue is empty.");
    int item = data[itsHead];
    itsHead = (itsHead + 1) % CAP; // Wrap around to front if at end
    itsSize--;
    return item;
}

int Queue::front() const {
    if (isEmpty())
        throw runtime_error("Queue is empty.");
    return data[itsHead];
}

bool Queue::isEmpty() const {
    return itsSize == 0;
}

bool Queue::isFull() const {
    return itsSize == CAP;
}

int Queue::size() const {
    return itsSize;
}

void Queue::clear() {
    itsHead = 0;
    itsTail = 0;
    itsSize = 0;
}

void Queue::print() const {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue (front to rear): ";
    for (int i = 0; i < itsSize; i++)
        cout << data[(itsHead + i) % CAP] << " ";
    cout << "\n";
}