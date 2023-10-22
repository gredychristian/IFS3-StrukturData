#include <iostream>
#include <cstdlib>
using namespace std;

// Declaration struct and the component.
struct Node
{
    int data;
    Node *next;
};
Node *head, *tail, *cur, *temp, *del;

// Create single linked list.
void addList(int data)
{
    head = new Node();
    head -> data = data;
    head -> next = NULL;
    tail = head;
}

// Add new node at the front.
void addFront(int data)
{
    temp = new Node();
    temp -> data = data;
    temp -> next = head;
    head = temp;
}

// Add new node at the rear.
void addRear(int data)
{
    temp = new Node();
    temp -> data = data;
    temp -> next = NULL;
    tail -> next = temp;
    tail = temp;
}

// Remove front node.
void delFront()
{
    del = head;
    head = head -> next;
    delete del;
}

// Remove rear node.
void delRear()
{
    del = tail;
    cur = head;
    while (cur -> next != tail)
    {
        cur = cur -> next;
    }
    tail = cur;
    tail -> next = NULL;
    delete del;
}

// Print single linked list.
void printList()
{
    cur = head;

    while( cur != NULL)
    {
        cout << cur -> data << " -> ";

        cur = cur -> next;
    }
}

// Main function.
int main()
{
    system("cls");
    cout << "<<< FRONT - REAR >>>" << endl << endl;
    
    // Add new first list
    addList(20);
    printList();
    cout << "NULL" << endl << endl;

    // Add front list
    addFront(40);
    printList();
    cout << "NULL" << endl << endl;

    //Add rear list
    addRear(50);
    printList();
    cout << "NULL" << endl << endl;

    // Delete front list
    delFront();
    printList();
    cout << "NULL" << endl << endl;

    // Add rear list
    addRear(60);
    printList();
    cout << "NULL" << endl << endl;

    // Delete rear list
    delRear();
    printList();
    cout << "NULL" << endl << endl;

    return 0;
}