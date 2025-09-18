#include <iostream>

using namespace std;

void foo(int val) {
    int *num_ptr = new int(val);
    cout << "num_ptr = " << num_ptr << endl;
    cout << "*num_ptr = " << *num_ptr << endl;

    delete num_ptr;
    cout << "*num_ptr = " << *num_ptr << endl;
}

int main(int argc, char* argv[]) {
    cout << "Hello, " << argv[1] << endl;

    int size = stoi(argv[2]);
    int *arr = new int[size];
    arr[size] = 10;

    int num;
    cout << "Enter a number: ";
    cin >> num;
    foo(num);

    //delete[] arr;

    return 0;
}  

// g++ Valgrind_Byers.cpp -g 
// valgrind --leak-check=summary ./a.out World 10