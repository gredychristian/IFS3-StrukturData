#include <iostream>
#include <string>
using namespace std;

//Declare Struct as data type named aircraft
struct aircraft
{
    string manufacture;
    string type;
    int year;
};

int main()
{
    system("cls");
    //From aircraft data type, create new variable air1 to store data in variable
    aircraft air1;
    air1.manufacture = "Boeing";
    air1.type = "B737-800";
    air1.year = 1990;

    //From aircraft data type, create new variable air1 to store data in variable
    aircraft air2;
    air2.manufacture = "Airbus";
    air2.type = "A340-400";
    air2.year = 2006;

    //Print Struct separated by their own Variables
    cout << air1.manufacture << " " << air1.type << " " << air1.year << endl;
    cout << air2.manufacture << " " << air2.type << " " << air2.year << endl;

    return 0;
}