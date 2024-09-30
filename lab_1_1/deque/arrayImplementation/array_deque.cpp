#include "array_deque.h"
using namespace std;
template <typename T>
ArrayDeque<T>::ArrayDeque(int capacity) : capacity(capacity), size(0), frontIndex(0), rearIndex(0) {
    data = new T[capacity];
}

template <typename T>
ArrayDeque<T>::~ArrayDeque() {
    delete[] data;
}

template <typename T>
void ArrayDeque<T>::resize() {
    T* newData = new T[capacity * 2];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[(frontIndex + i) % capacity];
    }
    frontIndex = 0;
    rearIndex = size;
    capacity *= 2;
    delete[] data;
    data = newData;
}

template <typename T>
void ArrayDeque<T>::pushFront(const T& element) {
    if (size == capacity) {
        resize();
    }
    frontIndex = (frontIndex - 1 + capacity) % capacity;
    data[frontIndex] = element;
    ++size;
}

template <typename T>
void ArrayDeque<T>::pushBack(const T& element) {
    if (size == capacity) {
        resize();
    }
    data[rearIndex] = element;
    rearIndex = (rearIndex + 1) % capacity;
    ++size;
}

template <typename T>
T ArrayDeque<T>::popFront() {
    if (isEmpty()) {
        throw out_of_range("Deque is empty");
    }
    T value = data[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    --size;
    return value;
}

template <typename T>
T ArrayDeque<T>::popBack() {
    if (isEmpty()) {
        throw out_of_range("Deque is empty");
    }
    rearIndex = (rearIndex - 1 + capacity) % capacity;
    T value = data[rearIndex];
    --size;
    return value;
}

template <typename T>
T ArrayDeque<T>::front() const {
    if (isEmpty()) {
        throw out_of_range("Deque is empty");
    }
    return data[frontIndex];
}

template <typename T>
T ArrayDeque<T>::back() const {
    if (isEmpty()) {
        throw out_of_range("Deque is empty");
    }
    return data[(rearIndex - 1 + capacity) % capacity];
}

template <typename T>
bool ArrayDeque<T>::isEmpty() const {
    return size == 0;
}
