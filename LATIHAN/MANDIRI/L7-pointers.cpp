#include <iostream>
using namespace std;

//GENERAL USAGE OF POINTERS
int generalPointers()
{
    system("cls");
    string jajan = "Sempol";    //Declare variable jajan and assign a value.
    int harga = 1000;           //Declare variable harga and assign a value.
    cout << jajan << endl;      //Print jajan.
    cout << harga << endl;      //Print harga.
    cout << "Address Langsung Jajan " << &jajan << endl;     //Print the memory address of jajan with direct access.
    cout << "Address Langsung Harga " << &harga << endl;     //Print the memory address of harga with direct access.

    /*
    When a variable was declared with * symbol, it makes the new variable
    able to read the memory address of the other variable.
    */
    string *ptrs = &jajan;
    cout << "Address Tidak Langsung Jajan " << ptrs << endl; //Print the memory address of jajan from pointer (indirect).
    int *ptri = &harga;
    cout << "Address Tidak Langsung Harga " << ptri << endl << endl; //Print the memory address of harga from pointer (indirect).

    return 0;
}

//ALTERNATIVE USAGE OF POINTERS
int alterPointers()
{
    string mobil = "Totoya";
    string *addr;
    addr = &mobil;
    cout << "Address Langsung Mobil " << &mobil << endl;    //Direct access of memory address.
    cout << "Address Tidak Langsung Mobil " << addr << endl;//Indirect access of memory address.
    cout << "Value Dari Address Pointer Mobil " << *addr << endl << endl;//Dereference: Access the memory address of variable and output its value using pointer.

    return 0;
}

//MODIFY POINTERS
int modifyPointers()
{
    string jajan = "Sempol";    //Declare variable jajan and assign a value.
    cout << jajan << endl;      //Print jajan.
    cout << &jajan << endl;
    
    string *ptr = &jajan;       //Pointer assigned with the memory address of jajan.
    
    *ptr = "Gethuk";            // Change the value of variable jajan by accessing from it's memory address with pointer.
    cout << *ptr << endl;       // Output of the new value by accessing from the memory address.
    cout << jajan << endl;      // Output of the new valua by direct access to variable jajan.
    cout << ptr << endl;        //Output memory address of variable jajan.

    return 0;
}


//MAIN FUNCTION
int main()
{
    generalPointers();
    alterPointers();
    modifyPointers();

    return 0;
}