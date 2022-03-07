#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

// No should not using namespace std;

template <typename T, size_t capacity>;
class CircularQueue {
    public:
        void enqueue(T element);
        T dequeue();
        CircularQueue(int capacity);
        ~CircularQueue();

    private:
        int frames_read;
        int capacity;
        int frames_written;
        int* frames;
};

#endif