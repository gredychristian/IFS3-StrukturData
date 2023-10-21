#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *link;
};
typedef node* nodePtr;

int main()
{
    nodePtr head = NULL; // Inisialisasi head dengan NULL
    
    nodePtr headnode = new node; // Deklarasi dan alokasi memori untuk headnode
    headnode->data = 20;
    headnode->link = NULL;
    
    // Set head untuk menunjuk ke headnode
    head = headnode;
    
    // Lakukan apa yang diperlukan dengan linked list
    // ...
    
    // Jangan lupa untuk membebaskan memori jika tidak diperlukan lagi
    delete head;
    
    return 0;
}
