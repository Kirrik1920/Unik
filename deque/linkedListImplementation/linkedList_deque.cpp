#include "linkedlist_deque.h"

// Node constructor
template <typename T>
Node<T>::Node(const T& value) : value(value), next(nullptr), prev(nullptr) {}

// LinkedListDeque constructor
template <typename T>
LinkedListDeque<T>::LinkedListDeque() : frontNode(nullptr), rearNode(nullptr), size(0) {}

// LinkedListDeque destructor
template <typename T>
LinkedListDeque<T>::~LinkedListDeque() {
    while (!isEmpty()) {
        popFront();
    }
}

// Insert element at the front of the deque
template <typename T>
void LinkedListDeque<T>::pushFront(const T& element) {
    Node<T>* newNode = new Node<T>(element);
    if (frontNode) {
        newNode->next = frontNode;
        frontNode->prev = newNode;
    }
    frontNode = newNode;
    if (!rearNode) {
        rearNode = frontNode;  // If deque was empty
    }
    ++size;
}

// Insert element at the back of the deque
template <typename T>
void LinkedListDeque<T>::pushBack(const T& element) {
    Node<T>* newNode = new Node<T>(element);
    if (rearNode) {
        newNode->prev = rearNode;
        rearNode->next = newNode;
    }
    rearNode = newNode;
    if (!frontNode) {
        frontNode = rearNode;  // If deque was empty
    }
    ++size;
}

// Remove element from the front of the deque
template <typename T>
T LinkedListDeque<T>::popFront() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    Node<T>* temp = frontNode;
    T value = temp->value;
    frontNode = frontNode->next;
    if (frontNode) {
        frontNode->prev = nullptr;
    } else {
        rearNode = nullptr;  // Deque is now empty
    }
    delete temp;
    --size;
    return value;
}

// Remove element from the back of the deque
template <typename T>
T LinkedListDeque<T>::popBack() {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    Node<T>* temp = rearNode;
    T value = temp->value;
    rearNode = rearNode->prev;
    if (rearNode) {
        rearNode->next = nullptr;
    } else {
        frontNode = nullptr;  // Deque is now empty
    }
    delete temp;
    --size;
    return value;
}

// Access the front element
template <typename T>
T LinkedListDeque<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    return frontNode->value;
}

// Access the rear element
template <typename T>
T LinkedListDeque<T>::back() const {
    if (isEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    return rearNode->value;
}

// Check if the deque is empty
template <typename T>
bool LinkedListDeque<T>::isEmpty() const {
    return size == 0;
}

// Stack interface implementation
template <typename T>
void LinkedListDeque<T>::push(const T& element) {
    pushBack(element);
}

template <typename T>
T LinkedListDeque<T>::pop() {
    return popBack();
}

template <typename T>
T LinkedListDeque<T>::top() const {
    return back();
}

// Queue interface implementation
template <typename T>
void LinkedListDeque<T>::enqueue(const T& element) {
    pushBack(element);
}

template <typename T>
T LinkedListDeque<T>::dequeue() {
    return popFront();
}
