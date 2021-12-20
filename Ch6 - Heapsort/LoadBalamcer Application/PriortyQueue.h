#define QUEUE_H

template <class T>

class PriortyQueue
{
private:
    T *elements;
    int size;

public:
    PriortyQueue()
    {
        size = 0;
        elements = new T[size];
    }

    void enqueue(T element);
    void MaxHeapify(T arr[], int i);
    void BuildMaxHeap(T arr[]);
    void resize(int newSize);
    T dequeue();
    T peek();
    bool isEmpty();
};

#include "PriortyQueue.cpp"