#include <stdlib.h>

// Constructor with capacity
template <typename T, size_t capacity> 
CircularQueue<T, capacity>::CircularQueue() {
    values = (T*) malloc(capacity * sizeof(T));
    values_read = 0;
    values_written = 0;
}

// Add in frame
template <typename T, size_t capacity> 
void CircularQueue<T, capacity>::enqueue(T element) {
    values[values_written % capacity] = element;
    values_written++;
}

// Remove frame
template <typename T, size_t capacity> 
T CircularQueue<T, capacity>::dequeue() {
    T ans = values[values_read % capacity];
    if (values_read < values_written) {
        values_read++;
    }
    return ans; 
}

// Destructor
template <typename T, size_t capacity> 
CircularQueue<T, capacity>::~CircularQueue() {
    free(values);
}