#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("cls");

    string food = "Tahu Tek";   //A variable assigned with valua "Tahu Tek"
    string &meal = food;        //A variable meal with ampersand references to variable food value

    cout << food << endl;       //Print food
    cout << meal << endl;       //Print meal which is alredy set refers to food
    cout << &meal<< endl;       //Ampersand in front of variable is for identify the memory address of a variable.
    
    meal = "Tahu Ting";         //Assign new value to meal replaces the previous meal references
    cout << meal << endl;       //Print meal normally
    cout << &meal<< endl;       //The memory address will always be the same as long as the variables are the same
}