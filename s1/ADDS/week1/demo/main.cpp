#include "CircularQueue.h"
#include <iostream>

using namespace std;

int main(void) {
    CircularQueue<string, 3> myQueue;

    myQueue.enqueue("hello");
    myQueue.enqueue("world");
    myQueue.enqueue("see");
    myQueue.enqueue("ya");

    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;

    return 0;
}