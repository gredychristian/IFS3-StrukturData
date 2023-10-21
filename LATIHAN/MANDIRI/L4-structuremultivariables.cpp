#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("cls");
    //Struct
    struct
    {
        string merek;
        string model;
        int tahun;
    } motor1, motor2; //One Struct can be used in Multiple Variables
    
    //Assign Value to motor1 (First Struct Variable)
    motor1.merek = "Yamaaf";
    motor1.model = "Racing";
    motor1.tahun = 2013;

    //Assifn Value to motor2 (Second Struct Variable)
    motor2.merek = "Totoya";
    motor2.model = "City";
    motor2.tahun = 2021;

    //Print Struct by the Variables
    cout << motor1.merek << " " << motor1.model << " " << motor1.tahun << endl;
    cout << motor2.merek << " " << motor2.model << " " << motor2.tahun << endl;
}