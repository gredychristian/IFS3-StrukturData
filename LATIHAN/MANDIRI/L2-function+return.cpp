#include <iostream>
using namespace std;

//FUNCTION + RETURN (1)
//Returns the result of the calculation to the function caller without parameter.
int tambah1 ()
{
    int a = 1, b = 2, ops;  //Variables are declared inside the function with fixed values.
    ops = a + b;            //Cannot modify the values because it's already set in the function.
    return ops;             //More syntax.
}

//FUCTION + RETURN (2)
//Returns the result of the calculation to the function caller with parameter.
int tambah2 (int a, int b)  //Variables are declared in parameter.
{                           
    return a + b;           //Values can be modified while calling the function in main function.
}                           //Less syntax.

//FUNCTION + RETURN (3)
//Void does not return a value.
void sapa()
{
    cout << "Halo Bung" << endl;
    return;                 //However, return is still needed to end the function execution.
}

//FUNCTION + RETURN (4)
//Conditional function return with parameter.
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    } 
    else
    {
        return b;
    }
}

//EXECUTNG ALL FUNCTIONS
int main()
{
    system("cls");
    cout << tambah1() << endl;      //(1) Print tambah1 normally.
    cout << tambah2(3, 5) << endl;  //(2) Assign new values based on it's parameters while calling the function.
    sapa();                         //(3) Calling function.
    cout << "Nilai terbesar adalah " << max(3, -1) << endl;     //(4) Calling function with conditional return.

    return 0;
}