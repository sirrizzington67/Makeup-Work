# Mini Project 2: Queuing System

## File Structure
```
MiniProject2_Queue/
├── include/
│   └── Queue.h       # Class declaration and public API
├── src/
│   └── Queue.cpp     # Full method implementations
├── main.cpp          # Interactive terminal menu
├── TESTING.md        # Test cases and expected results
└── README.md
```

## Build & Run
```bash
g++ -std=c++11 -I include main.cpp src/Queue.cpp -o queue
./queue
```

## Example Usage
```
--- Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek (front)
4. Size
5. Print queue
6. Exit
Choice: 1
Enter value to enqueue: 42
42 enqueued.

Choice: 3
Front: 42

Choice: 2
42 dequeued.

Choice: 6
Exiting.
```

## Design Notes
- Array-based circular queue with fixed capacity (CAP = 10)
- Wrap-around handled with modulo arithmetic on head and tail indices
- enqueue and dequeue throw runtime_error on invalid operations