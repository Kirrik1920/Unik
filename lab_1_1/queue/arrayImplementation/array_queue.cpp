#include "array_queue.h"

template <typename T>
ArrayQueue<T>::ArrayQueue(int capacity) : frontIndex(0), rearIndex(-1), capacity(capacity), size(0) {
    array = new T[capacity];
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] array;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& element) {
    if (size == capacity) {
        throw std::overflow_error("Queue is full");
    }
    rearIndex = (rearIndex + 1) % capacity;
    array[rearIndex] = element;
    ++size;
}

template <typename T>
T ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    T value = array[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    --size;
    return value;
}


template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return array[frontIndex];
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return size == 0;
}
