#include <iostream>
#include "./deque/arrayImplementation/array_deque.h"
#include "./deque/linkedListImplementation/linkedList_deque.h"

#include "./queue/arrayImplementation/array_queue.h"
#include "./queue/linkedListImplementation/linkedList_queue.h"

#include "./stack/arrayImplementation/array_stack.h"
#include "./stack/linkedListImplementation/linkedList_stack.h"

using namespace std;
int main() {



    ArrayStack<int> arrayStack(5);
    arrayStack.push(10);
    arrayStack.push(20);
    arrayStack.push(30);
    std::cout << "Array Stack Top: " << arrayStack.top() << std::endl;
    std::cout << "Array Stack Pop: " << arrayStack.pop() << std::endl;

    cout << "-------------------------------------" << endl;

    LinkedListStack<int> linkedListStack;
    linkedListStack.push(40);
    linkedListStack.push(50);
    linkedListStack.push(60);
    std::cout << "LinkedList Stack Top: " << linkedListStack.top() << std::endl;
    std::cout << "LinkedList Stack Pop: " << linkedListStack.pop() << std::endl;

    cout << "----------------------------------------" << endl;

    ArrayQueue<int> arrayQueue(5);
    arrayQueue.enqueue(10);
    arrayQueue.enqueue(20);
    arrayQueue.enqueue(30);
    std::cout << "Array Queue Front: " << arrayQueue.front() << std::endl;
    std::cout << "Array Queue Dequeue: " << arrayQueue.dequeue() << std::endl;


    cout << "----------------------------------------" << endl;

    LinkedListQueue<int> linkedListQueue;
    linkedListQueue.enqueue(40);
    linkedListQueue.enqueue(50);
    linkedListQueue.enqueue(60);
    std::cout << "LinkedList Queue Front: " << linkedListQueue.front() << std::endl;
    std::cout << "LinkedList Queue Dequeue: " << linkedListQueue.dequeue() << std::endl;


    cout << "----------------------------------------" << endl;


    ArrayDeque<int> deque;

    deque.pushFront(10);
    deque.pushBack(20);

    cout << "Front element: " << deque.front() << endl;
    cout << "Back element: " << deque.back() << endl;

    deque.pushFront(5);
    cout << "New Front element: " << deque.front() << endl;

    cout << "Popping front: " << deque.popFront() << endl;
    cout << "Popping back: " << deque.popBack() << endl;


    cout << "----------------------------------------" << endl;

    LinkedListDeque<int> deque2;

    deque2.pushFront(10);
    deque2.pushBack(20);

    cout << "Front element: " << deque2.front() << endl;
    cout << "Back element: " << deque2.back() << endl;

    deque2.pushFront(5);
    cout << "New Front element: " << deque2.front() << endl;

    cout << "Popping front: " << deque2.popFront() << endl;
    cout << "Popping back: " << deque2.popBack() << endl;

    cout << "Is deque empty? " << (deque2.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
