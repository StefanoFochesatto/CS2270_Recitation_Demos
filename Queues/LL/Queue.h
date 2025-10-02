#ifndef QUEUE_H
#define QUEUE_H

/**
 * @class Queue
 * @brief Implementation using LL
 */
class Queue {
private:
    struct Node {
        int data;  
        Node* next; 
    };

    Node* front; 
    Node* rear;  

public:
    //Constructor
    Queue();
    //Destructor
    ~Queue();

    //Add data from the rear
    void enqueue(int value);

    //Remove data from the front
    int dequeue();

    // Whose next!?
    int peek();

    // Is anybody in Line
    bool isEmpty();

    // Print the queue. 
    void display();
};

#endif // QUEUE_H