#include "CircularQueue.h"
#include <iostream>

using namespace std;

int main(void) {
    CircularQueue myQueue(3);

    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;

    return 0;
}