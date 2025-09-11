#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {

    // Dynamically allocating on the stack

    int StackArraySize;
    cout << "Enter the size of the array on the Stack: ";
    cin >> StackArraySize;

    // It is NOT standard C++ and is dangerous.
    // It might compile on some compilers as an extension, but it can easily
    // lead to a crash (a stack overflow) if 'size' is large.
    int StackArray[StackArraySize]; 



    int HeapArraySize;
    cout << "Enter the size of the array on the Heap: ";
    cin >> HeapArraySize;

    // We ask the heap for a chunk of memory AT RUNTIME.
    // The size can be anything we want.
    // 'my_array' is a pointer that lives on the stack 
    //(because [] is a function call with its on stack frame and allocation at compile time), but the large
    // block of integers it points to lives on the heap.
    int* HeapArray = new int[HeapArraySize]; 

    // ... use the array ...

    delete[] HeapArray; // We must manually give the memory back to the heap.
}









