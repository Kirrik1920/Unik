#include "linkedList_stack.h"
#include "../../node/node.h"

#include <stdexcept>



template <typename T>
LinkedListStack<T>::LinkedListStack() : topNode(nullptr), size(0) {}


template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    while (!isEmpty()) {
        pop();
    }
}


template <typename T>
void LinkedListStack<T>::push(const T& element) {
    Node<T>* newNode = new Node<T>(element);
    newNode->next = topNode;
    topNode = newNode;
    ++size;
}


template <typename T>
T LinkedListStack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    Node<T>* temp = topNode;
    T value = temp->value;
    topNode = topNode->next;
    delete temp;
    --size;
    return value;
}


template <typename T>
T LinkedListStack<T>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return topNode->value;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return topNode == nullptr;
}
