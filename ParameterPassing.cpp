#include <iostream>
using namespace std;

void PassByValue(int ptr){
    cout << "value of ptr in PassByValue: " << ptr << endl;
    cout << "address of ptr in PassByPvalue: " << &ptr << endl;

}

void PassByReference(int &ptr){
    cout << "value of ptr in PassByReference: " << ptr << endl;
    cout << "address of ptr in PassByReference: " << &ptr << endl;
}

void PassByPointer(int* ptr){
    cout << "dereference value of ptr in PassByPointer: " << *ptr << endl;
    cout << "value of ptr in PassByPointer: " << ptr << endl;
    cout << "value of ptr in PassByPointer: " << &ptr << endl;



}

void PassPointerByReference(int* &ptr){
    cout << "dereference value of ptr in PassPointerByReference: " << *ptr << endl;
    cout << "address of ptr in PassPointerByReference: " << ptr << endl;
    cout << "value of ptr in PassPointerByReference: " << &ptr << endl;


}

int main(){
    int ptr;
// 2. Create a pointer variable that points to our data.
    int* pointer_to_value = &ptr;
    cout << "value of ptr in main: " << ptr << endl;
    cout << "address of ptr in main: " << &ptr << endl;
    PassByValue(ptr);
    PassByReference(ptr);
    PassByPointer(pointer_to_value);
    PassPointerByReference(pointer_to_value);




return 0;

}
