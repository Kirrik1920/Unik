#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "../queue.h"
#include <stdexcept>

template <typename T>
class ArrayQueue : public Queue<T> {
private:
    T* array;
    int frontIndex;
    int rearIndex;
    int capacity;
    int size;

public:
    ArrayQueue(int capacity = 10);
    ~ArrayQueue();

    void enqueue(const T& element) override;
    T dequeue() override;
    T front() const override;
    bool isEmpty() const override;
};

#include "array_queue.cpp"

#endif
