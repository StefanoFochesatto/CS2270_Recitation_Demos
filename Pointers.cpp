#include <iostream>
#include <vector> 


using namespace std;

int main(int argc, char* argv[]) {

    // Data
    int actualInt = 4200000;                     
    char actualChar = 'H';        
    vector<int> actualVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

    // Declare typed pointers.
    int* p;
    char* p2;
    vector<int>* p3;

    // Initilize pointers to data. 
    p = &actualInt;      
    p2 = &actualChar;  
    p3 = &actualVec;
                         
    // Printing pointer sizes, 8 bytes in 64 bit computer
    cout << "--- Pointer Variable Sizes ---" << endl;
    cout << "Size of int* p:    " << sizeof(p) << " bytes" << endl;
    cout << "Size of char* p2:  " << sizeof(p2) << " bytes" << endl;
    cout << "Size of char* p3:  " << sizeof(p3) << " bytes" << endl;

    // For comparison, show the size of the types they point to.
    cout << "Size of pointed-to type 'int': " << sizeof(int) << " bytes" << endl;
    cout << "Size of pointed-to type 'char': " << sizeof(char) << " byte" << endl;
    cout << "Size of pointed-to type 'char': " << sizeof(actualVec) << " byte" << endl;
    cout << "------------------------------" << endl << endl;

    // Demonstrating dereferencing for small types compatable with cout
    cout << "--- Dereferencing (Accessing the Data) ---" << endl;
    cout << "Value stored in actualInt:         " << actualInt << endl;
    cout << "Value read via *p (int pointer):    " << *p << endl; // p points to actualInt, *p reads an int.

    cout << "Value stored in actualChar:      " << actualChar << endl;
    // *p2 reads the single character at the address p2 points to.
    cout << "Value read via *p2 (char pointer): " << *p2 << endl; // p2 points to 'H', so *p2 shows 'H'.


    // Let's modify the data through the pointers to show they are working.
    *p = 123;         // Change the integer value through the int pointer.
    *p2 = 'W';        // Change the *first character* of the string through the char pointer.

    cout << "\nAfter modifying data: " << endl;
    cout << "actualInt after *p = 123:         " << actualInt << endl;       // Shows the original int variable was modified.
    cout << "actualChar after *p2 = 'W':      " << actualChar << endl;     // Shows the string variable was modified.
    cout << "------------------------------------------" << endl << endl;



    // Lets identify some differences between arrays and pointers
    int arr[5] = {10, 20, 30, 40, 50};
    int* p4;
    
    // Will this compile?
    p4 = arr;

    cout << "value of p4: " << p4 << endl;
    cout << "address of arr[0]: " << &arr[0] << endl;
    cout << "value of arr: " << arr << endl;



}