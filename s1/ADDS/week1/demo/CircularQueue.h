#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <stddef.h>

// No should not using namespace std;

template <typename T, size_t capacity> 
class CircularQueue {
    public:
        void enqueue(T element);
        T dequeue();
        CircularQueue();
        ~CircularQueue();

    private:
        int values_read;
        int values_written;
        T* values;
};

#include "CircularQueue.tpp"  

#endif