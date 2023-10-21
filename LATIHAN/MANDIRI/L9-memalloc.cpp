#include <iostream>
#include <cstdlib>  //cstdlib is used to use malloc function.
using namespace std;
/* EXAMPLE 1
int main()
{
    // Memory allocation based on how many bytes in memory you want to allocate to run program.
    // size_t is an integer data type which can assign greater than or equal to 0 integer values.
    size_t s = 0;   // use size_t as memory allocation specified in "s" byte.
    int* ptr = (int*)malloc(s); // malloc declaration and initialization.

    // return condition if the memory block is not initialized.
    if (ptr == NULL)
    {
        cout << "Null pointer has been returned. Memory has not allocated" << endl;
    }

    // condition printing the message if the memory has been allocated.
    else
    {
        cout << "Memory has been allocated at address " << ptr << endl;
    }

    free(ptr);  // free function is used to dynamically de-allocate the memory.
    return 0;
}
*/

// EXAMPLE 2
int main()
{
    // variable declaration.
    // Memory allocation based on how many integers can be stored.
    int var_len = 10;   // use var_len to determine how many integer can be stored in memory.
    
    // pointer variable declaration.
    int* ptr;

    // allocating memory to the pointer variable using malloc().
    // malloc declaration by scanning the size of integer and calculate it in bytes.
    ptr = (int*) malloc(sizeof(int)*var_len);
    
    for(int i = 0; i < var_len; i++)
    {
        cout << "Enter a number\t\t: " << endl;
        cin >> *(ptr+i);
    }

    cout << "Entered elements are\t: " << endl;
    for(int i = 0; i < var_len; i++)
    {
        cout << *(ptr+i) << endl;
    }

    free(ptr);
    return 0;
}