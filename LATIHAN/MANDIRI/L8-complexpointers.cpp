#include <iostream>
using namespace std;

//COMPLEX POINTER ILLUSTRATION
int main()
{
    system("cls");
    int i = 5;  //Assign 5 as i variable.
    int j = 10; //Assign 10 as j variable.

    int *ptr;   //Declare a pointer-to-integer variable.
    int **pptr; //Declare a pointer-to-pointer-to-integer variable.
    
    ptr = &i;   //Store address of i into ptr.
    pptr = &ptr;//Store address of ptr into pptr.
    
    cout << ptr << endl;    //Print the address of i.
    cout << *ptr << endl;   //Print the value of i.
    cout << pptr << endl;   //Print the address of ptr (ptr is filled with the address of i [line 14]).
    cout << &ptr << endl;   //Print the address of ptr but using ampersand (direct read address).
    cout << *pptr << endl;  //Print the value of ptr.
    cout << **pptr << endl; //Print the value of i.
    cout << &pptr << endl << endl;  //Print the address of pptr.
    
    *ptr = 3;   //New assign value 3 into the variable that is pointed by the pointer.
    cout << i << endl;  //Print i
    **pptr = 7; //New assign value 7 into the variable that is pointed by the pointer.
    cout << i << endl << endl;  //Print i
    
    ptr = &j;   //New assign pointer replace address i with the address of j.
    cout << ptr << endl;    //Print the address of j.
    **pptr = 9;             //New assign 9 into j from pointer-to-pointer-to-integer variable (pptr).
    cout << j << endl;   //Print the address of j.
    cout << **pptr << endl; //Print the value of j.
    *pptr = &i;             //Store address of i into pptr.
    cout << *pptr << endl;  //Print the value of ptr.            
    *ptr = -2;              //New assign -2 into j from pointer-to-integer variable (ptr).
    cout << i;              //Print the value of i.

    return 0;
}