#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "../stack.h"
#include <stdexcept>

template <typename T>
class ArrayStack : public Stack<T> {
private:
    T* array;
    int topIndex;
    int capacity;

public:
    ArrayStack(int capacity = 10);
    ~ArrayStack();

    void push(const T& element) override;
    T pop() override;
    T top() const override;
    bool isEmpty() const override;
};

#include "array_stack.cpp"

#endif
