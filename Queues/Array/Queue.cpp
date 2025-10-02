#include <iostream>
#include "Queue.h"


Queue::Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = 0;   // Front is at the first index initially.
    rear = -1;   // Rear is -1 as the queue is initially empty.
    count = 0;   // No elements in the queue initially.
}


Queue::~Queue() {
    delete[] arr;
}


bool Queue::isFull() {
    return count == capacity;
}


bool Queue::isEmpty() {
    return count == 0;
}


void Queue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Error: Queue is full (overflow). Cannot enqueue " << value << "." << std::endl;
        return;
    }
    // Calculate the new rear position in a circular fashion.
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
    std::cout << value << " has been enqueued." << std::endl;
}


int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty (underflow). Cannot dequeue." << std::endl;
        return -1; 
    }
    int value = arr[front];
    // Calculate the new front position in a circular fashion.
    front = (front + 1) % capacity;
    count--;
    std::cout << value << " has been dequeued." << std::endl;
    return value;
}

/**
 * @brief Returns the value of the front element without removing it.
 * @return The data from the front element.
 */
int Queue::peek() {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty. Cannot peek." << std::endl;
        return -1; 
    }
    return arr[front];
}


void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Queue (front to rear): ";
    int current = front;
    for (int i = 0; i < count; i++) {
        std::cout << arr[current] << " ";
        current = (current + 1) % capacity;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Creating a new Queue with capacity 5...\n";
    Queue myQueue(5);

    std::cout << "\n--- Enqueue Operations ---\n";
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.display();

    std::cout << "\n--- Dequeue Operations ---\n";
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.display();

    std::cout << "\n--- Enqueue to Wrap Around ---\n";
    myQueue.enqueue(50);
    myQueue.enqueue(60);
    myQueue.display();

    std::cout << "\n--- Overflow Test ---\n";
    myQueue.enqueue(70); // This will make the queue full.
    myQueue.display();
    std::cout << "Is the queue full? " << (myQueue.isFull() ? "Yes" : "No") << std::endl;
    myQueue.enqueue(80); // This enqueue attempt should fail.

    std::cout << "\n--- Emptying the Queue ---\n";
    myQueue.dequeue();
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