#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

#include "../queue.h"
#include "../../node/node.h"


template <typename T>
class LinkedListQueue : public Queue<T> {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
    int size;

public:
    LinkedListQueue();
    ~LinkedListQueue();

    void enqueue(const T& element) override;
    T dequeue() override;
    T front() const override;
    bool isEmpty() const override;
};

#include "linkedList_queue.cpp"

#endif
