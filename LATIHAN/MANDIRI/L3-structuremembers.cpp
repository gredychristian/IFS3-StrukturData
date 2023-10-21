#include <iostream>
#include <string>
using namespace std;

int main()
{    
//Struct Variable named myStructure
    struct
    {
        int myNum;
        string myStr;
    } myStructure;

    //Assign Values to myStructure members
    myStructure.myNum = 1;
    myStructure.myStr = "Hello Nig!";

    //Print myStructure members one by one
    cout << myStructure.myStr << endl;
    cout << myStructure.myNum << endl;

    //Combine myStructure members
    string combinedString = "myStr: " + myStructure.myStr + "\n" + "myNum: " + to_string(myStructure.myNum);
    cout << combinedString << endl;
    return 0;
}

