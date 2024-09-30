#ifndef LINKEDLIST_DEQUE_H
#define LINKEDLIST_DEQUE_H

#include "../deque.h"
#include "../../node/node.h"
#include <stdexcept>


template <typename T>
class LinkedListDeque : public Deque<T> {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
    int size;

public:

    LinkedListDeque();

    ~LinkedListDeque();

    void pushFront(const T& element) override;

    void pushBack(const T& element) override;

    T popFront() override;

    T popBack() override;

    T front() const override;

    T back() const override;

    bool isEmpty() const override;

    void push(const T& element) override;

    T pop() override;

    T top() const override;

    void enqueue(const T& element) override;

    T dequeue() override;
};

#include "linkedList_deque.cpp"

#endif
