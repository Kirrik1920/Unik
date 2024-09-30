#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
    virtual void push(const T& element) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Stack() {}
};

#endif
