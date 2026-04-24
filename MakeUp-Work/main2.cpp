#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue q;
    int choice, val;

    do {
        cout << "\nQueue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (front)\n";
        cout << "4. Size\n";
        cout << "5. Print queue\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                try {
                    q.enqueue(val);
                    cout << val << " enqueued.\n";
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            case 2:
                try {
                    val = q.dequeue();
                    cout << val << " dequeued.\n";
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            case 3:
                try {
                    cout << "Front: " << q.front() << "\n";
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            case 4:
                cout << "Size: " << q.size() << "\n";
                break;
            case 5:
                q.print();
                break;
            case 6:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}