#include "linkedList_queue.h"
#include "../../node/node.h"
#include <stdexcept>




template <typename T>
LinkedListQueue<T>::LinkedListQueue() : frontNode(nullptr), rearNode(nullptr), size(0) {}


template <typename T>
LinkedListQueue<T>::~LinkedListQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}


template <typename T>
void LinkedListQueue<T>::enqueue(const T& element) {
    Node<T>* newNode = new Node<T>(element);
    if (rearNode) {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    if (!frontNode) {
        frontNode = rearNode;
    }
    ++size;
}


template <typename T>
T LinkedListQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    Node<T>* temp = frontNode;
    T value = temp->value;
    frontNode = frontNode->next;
    if (!frontNode) {
        rearNode = nullptr;
    }
    delete temp;
    --size;
    return value;
}


template <typename T>
T LinkedListQueue<T>::front() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return frontNode->value;
}


template <typename T>
bool LinkedListQueue<T>::isEmpty() const {
    return size == 0;
}
