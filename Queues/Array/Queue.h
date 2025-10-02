#ifndef QUEUE_H
#define QUEUE_H


class Queue {
private:
    int* arr;       // Pointer to the array that stores queue elements.
    int capacity;   // The maximum capacity of the queue.
    int front;      // Index of the front element.
    int rear;       // Index of the rear element.
    int count;      // Current number of elements in the queue.

public:
    //Constructor
    Queue(int size = 10); 

    //Destructor
    ~Queue();


    void enqueue(int value);


    int dequeue();

    int peek();


    bool isEmpty();


    bool isFull();


    void display();
};

#endif
