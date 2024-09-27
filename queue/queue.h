#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
public:
    virtual void enqueue(const T& element) = 0;
    virtual T dequeue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Queue() {}
};

#endif
