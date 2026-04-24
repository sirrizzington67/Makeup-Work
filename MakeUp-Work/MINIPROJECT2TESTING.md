# TESTING.md

## Test 1: Enqueue Until Full

Enqueue 10 items (CAP = 10). On the 11th enqueue, expect error:
```
Error: Queue is full.
```

## Test 2: Dequeue Until Empty
Dequeue all items one by one. On the next dequeue, expect error:
```
Error: Queue is empty.
```

## Test 3: Wrap-Around (Circular Indexing)
1. Enqueue 10 items to fill the queue
2. Dequeue 3 items (head moves forward)
3. Enqueue 3 new items (tail wraps around to front of array)
4. Print queue — should show correct front-to-rear order with no gaps

## Test 4: Mixed Operations
1. Enqueue 5 items
2. Dequeue 2 items
3. Peek — should return the 3rd item originally enqueued
4. Enqueue 3 more items
5. Check size — should return 6
6. Clear — size should return 0