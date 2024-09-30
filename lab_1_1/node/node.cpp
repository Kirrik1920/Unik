#include "node.h"

template <typename T>
Node<T>::Node(const T& value) : value(value), next(nullptr), prev(nullptr) {}