#ifndef QUEUE_H
#define QUEUE_H

const int CAP = 10;

class Queue {
public:
    Queue();

    void enqueue(int item); // Adds item to the rear; throws if full
    int  dequeue();         // Removes and returns front item; throws if empty
    int  front() const;     // Returns front item without removing; throws if empty
    bool isEmpty() const;   // Returns true if queue has no elements
    bool isFull()  const;   // Returns true if queue is at capacity
    int  size()    const;   // Returns number of elements in queue
    void clear();           // Resets queue to empty state
    void print()   const;   // Prints all elements front to rear

private:
    int data[CAP];
    int itsHead;  // Index of front element
    int itsTail;  // Index of next open slot
    int itsSize;
};

#endif