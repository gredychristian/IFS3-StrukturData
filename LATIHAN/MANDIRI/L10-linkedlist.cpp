#include <iostream>
#include <cstdlib>
using namespace std;

// Declaration struct and the component.
struct Node
{
    int data;
    Node *next;
};

int main()
{
    system("cls");
    Node *node1, *node2, *node3;

    node1 = new Node();
    node2 = new Node();
    node3 = new Node();

    // Assign node1
    node1 -> data = 10;
    node1 -> next = node2;

    // Assign node2
    node2 -> data = 20;
    node2 -> next = node3;

    // Assign node3
    node3 -> data = 30;
    node3 -> next = NULL;

    // Print linked list
    Node *cur;
    cur = node1;

    while( cur != NULL)
    {
        cout << cur -> data << " -> ";

        cur = cur -> next;
    }
    cout << "NULL";
    
    return 0;
}