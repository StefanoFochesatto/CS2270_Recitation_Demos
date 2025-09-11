#include <iostream>
using namespace std;

int main() {
    
    // --- Setup ---

    // C++ multidimensional arrays
    // This way creates a single contiguous block of 5 * 10 * sizeof(int) bytes on the stack.
    const int rows = 5;
    const int cols = 10;
    int matrix[rows][cols];


    // We can use an array of pointers to get the same access syntax as a double pointer.
    // First we declare an array of pointers to integers. This will hold pointers 
    // to the first element of each row in our stack-allocated matrix.
    int* row_pointers[rows];

    // --- Population ---

    for (int i = 0; i < rows; i++){
        // The expression 'matrix[i]' (which is of type int[10]) decays into a pointer
        // to its first element (type int*). We assign this pointer to our array.
        // This is pointer to pointer assignment
        row_pointers[i] = matrix[i];
    }
    
    cout << "Pointer lookup table created for the stack array." << endl;

    // --- Usage Example 1: Using the array of pointers ---
    
    cout << "\nModifying matrix[1][5] using row_pointers..." << endl;
    row_pointers[1][5] = 123; // This syntax works because row_pointers[1] is an int* and [] is a function which returns a reference(dereferenced pointer/ alias)

    // Prove that the original stack memory was changed
    cout << "Value via row_pointers: " << row_pointers[1][5] << endl;
    cout << "Value in original matrix: " << matrix[1][5] << endl;


    // --- Usage Example 2: Using a true double pointer ---

    // So we've seen an array of pointers ('row_pointers') will decay into a 
    // pointer to its first element i.e a pointer to a pointer, so a double pointer (int**) when assigned.
    int** p_matrix = row_pointers;

    cout << "\nModifying matrix[4][8] using a double pointer..." << endl;
    p_matrix[4][8] = 456; // This is the classic double pointer access syntax.

    // Prove that this also changed the original stack memory
    cout << "Value via p_matrix: " << p_matrix[4][8] << endl;
    cout << "Value in original matrix: " << matrix[4][8] << endl;


    return 0;
}
