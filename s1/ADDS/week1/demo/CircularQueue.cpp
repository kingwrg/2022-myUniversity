#include "CircularQueue.h"
#include <stdlib.h>

// Constructor with capacity
CircularQueue::CircularQueue(int capacity) {
    frames = new int[capacity];
    this->capacity = capacity;
    frames_read = 0;
    frames_written = 0;
}

// Add in frame
void CircularQueue::enqueue(int frame) {
    frames[frames_written % capacity] = frame;
    frames_written++;
}

// Remove frame
int CircularQueue::dequeue() {
    int ans = frames[frames_read % capacity];
    if (frames_read < frames_written) {
        frames_read++;
    }
    return ans; 
}

// Destructor
CircularQueue::~CircularQueue() {
    free(frames);
}