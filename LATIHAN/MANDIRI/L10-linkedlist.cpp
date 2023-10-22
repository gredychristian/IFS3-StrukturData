#include <iostream>
#include <cstdlib>
using namespace std;

// Declaration struct and the component.
struct Node
{
    int data;
    Node *next;
};
Node *head, *tail, *cur;

void addList(int data)
{
    head = new Node();
    head -> data = data;
    head -> next = NULL;
    tail = head;
}

void printList()
{
    cur = head;

    while( cur != NULL)
    {
        cout << cur -> data << " -> ";

        cur = cur -> next;
    }
    cout << "NULL";
}

int main()
{
    system("cls");
    addList(20);
    printList();

    return 0;
}