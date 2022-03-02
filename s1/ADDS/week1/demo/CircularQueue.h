#ifdef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <array>
// No should not using namespace std;

class CircularQueue {
    public:
        void add(int frame);
        int getNext();
        CircularQueue(int capacity);
        // ??? ~CircularQueue();

    private:
        int front;
        int capacity;
        int current_size;
        std::array<int> frames;

};

#endif