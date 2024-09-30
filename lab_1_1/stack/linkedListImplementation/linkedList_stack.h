#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include "../stack.h"
#include "../../node/node.h"

template <typename T>
class LinkedListStack : public Stack<T> {
private:
    Node<T>* topNode;
    int size;

public:
    LinkedListStack();
    ~LinkedListStack();

    void push(const T& element) override;
    T pop() override;
    T top() const override;
    bool isEmpty() const override;
};

#include "linkedList_stack.cpp"

#endif
