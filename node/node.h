#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T value;
    Node* next;
    Node* prev;

    Node(const T& value);
};

#include "node.cpp"

#endif