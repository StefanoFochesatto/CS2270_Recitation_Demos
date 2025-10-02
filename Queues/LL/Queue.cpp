#include <iostream>
#include "Queue.h"

// Constructor implementation: Initializes front and rear pointers to nullptr.
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // If the queue is empty, the new node is both the front and the rear.
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        // Otherwise, link the current rear node to the new node...
        rear->next = newNode;
        // ...and update the rear pointer to the new node.
        rear = newNode;
    }
    std::cout << value << " has been enqueued." << std::endl;
}

int Queue::dequeue() {
    // Check for queue underflow (dequeuing from an empty queue).
    if (isEmpty()) {
        std::cout << "Error: Queue is empty. Cannot dequeue." << std::endl;
        return -1; 
    }

    // Update new front pointer
    Node* temp = front;
    int value = temp->data;
    front = front->next;

    // Check if that was the last node in queue
    if (front == nullptr) {
        rear = nullptr;
    }

    // Delete the old front node to free its memory.
    delete temp;

    std::cout << value << " has been dequeued." << std::endl;
    return value;
}

int Queue::peek() {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty. Cannot peek." << std::endl;
        return -1;
    }
    return front->data;
}


bool Queue::isEmpty() {
    // If front is nullptr, the queue is empty.
    return (front == nullptr);
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    Node* temp = front;
    std::cout << "Queue (front to rear): ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


// --- Main function to demonstrate the Queue ---
int main() {
    std::cout << "Creating a new Queue...\n";
    Queue myQueue;

    std::cout << "\n--- Enqueue Operations ---\n";
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.display();

    std::cout << "\n--- Peek Operation ---\n";
    std::cout << "Front element is: " << myQueue.peek() << std::endl;

    std::cout << "\n--- Dequeue Operations ---\n";
    myQueue.dequeue();
    myQueue.display();

    myQueue.enqueue(40);
    myQueue.display();

    std::cout << "\n--- Emptying the Queue ---\n";
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.display();

    std::cout << "\n--- Underflow Tests ---\n";
    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;
    myQueue.dequeue(); // Attempting to dequeue from an empty queue.
    myQueue.peek();    // Attempting to peek at an empty queue.

    return 0;
}