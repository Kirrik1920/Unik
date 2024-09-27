#ifndef DEQUE_H
#define DEQUE_H

#include "../stack/stack.h"
#include "../queue/queue.h"

// Deque interface implementing both Stack and Queue
template <typename T>
class Deque : public Stack<T>, public Queue<T> {
public:
    virtual void pushFront(const T& element) = 0;
    virtual void pushBack(const T& element) = 0;
    virtual T popFront() = 0;
    virtual T popBack() = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Deque() {}
};

#endif
