#ifndef ARRAY_DEQUE_H
#define ARRAY_DEQUE_H

#include "../deque.h"
#include <stdexcept>

template <typename T>
class ArrayDeque : public Deque<T> {
private:
    T* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int size;

    void resize();

public:
    ArrayDeque(int capacity = 10);
    ~ArrayDeque();

    void pushFront(const T& element) override;
    void pushBack(const T& element) override;
    T popFront() override;
    T popBack() override;
    T front() const override;
    T back() const override;
    bool isEmpty() const override;


    void push(const T& element) override { pushBack(element); }
    T pop() override { return popBack(); }
    T top() const override { return back(); }


    void enqueue(const T& element) override { pushBack(element); }
    T dequeue() override { return popFront(); }
};

#include "array_deque.cpp"

#endif
