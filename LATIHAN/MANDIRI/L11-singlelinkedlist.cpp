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
    head -> data = data; // Head -> data = data means that the value of data is based on how value is assigned in parameters [check at int main()].
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

// Add new node after the given value.
void addMid(int data)
{}

// Remove front node.
void delFront()
{
    del = head;
    head = head -> next;
    delete del;
}

// Remove node after the given value.
void delMid(int data)
{}

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
    head = NULL;// Initialize head with NULL to prevent any uneccessary data appear in the linked list.
    string i;
    int data;
    int pil;
    int exit = 0;

    while (!exit)
    {
        system("cls");
        cout << "|============================|" << endl;
        cout << "|     SINGLE LINKED LIST     |" << endl;
        cout << "|============================|" << endl;
        
        cout << "1. Tambah data di depan\n3. Tambah data di akhir\n";
        cout << "4. Hapus data di depan\n6. Hapus data di akhir\n";
        cout << "7. Cetak list\n8. Keluar\n";
        cout << "Pilihan menu = ";
        cin >> pil;

        switch(pil)
        {
            case 99999:// Add new node
            cout << "\nMasukkan nilai: ";
            cin >> data;
            addList(data);
            break;

            case 1:// Add new node to the front
            cout << "\nMasukkan nilai: ";
            cin >> data;
            addFront(data);
            break;

            case 2:// Add new node to the middle
            cout << "\nMasukkan nilai: ";
            cin >> data;
            addMid(data);
            break;
            
            case 3:// Add new node to the rear
            cout << "\nMasukkan nilai: ";
            cin >> data;
            addRear(data);
            break;

            case 4:// Delete front node
            delFront();
            break;

            case 5:// Delete middle node
            delMid(data);
            break;

            case 6:// Delete rear node
            delRear();
            break;

            case 7:// Print single linked list
            printList();
            cout << "NULL" << endl << endl;
            cout << "[Tekan 'x' Untuk Lanjut] ";
            cin >> i;
            break;

            case 8:
            exit = 1;
            break;

            default:;
        }
    }

    return 0;
}