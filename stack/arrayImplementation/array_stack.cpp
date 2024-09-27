#include "array_stack.h"


template <typename T>
ArrayStack<T>::ArrayStack(int capacity) : topIndex(-1), capacity(capacity) {
    array = new T[capacity];
}


template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] array;
}


template <typename T>
void ArrayStack<T>::push(const T& element) {
    if (topIndex == capacity - 1) {
        throw std::overflow_error("Stack is full");
    }
    array[++topIndex] = element;
}


template <typename T>
T ArrayStack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return array[topIndex--];
}


template <typename T>
T ArrayStack<T>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return array[topIndex];
}


template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return topIndex == -1;
}
