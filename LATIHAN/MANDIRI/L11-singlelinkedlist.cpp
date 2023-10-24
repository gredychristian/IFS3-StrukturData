#include <iostream>
#include <cstdlib>
using namespace std;

// Declaration struct and the component.
struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr; // Inisialisasi dengan nullptr
Node *tail = nullptr; // Inisialisasi dengan nullptr
Node *cur, *temp, *del;

// Create single linked list.
void addList(int data)
{
    temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Add new node at the front.
void addFront(int data)
{
    temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

// Add new node after the given value.
void addMid(int data, int pos)
{
    temp = new Node();
    temp->data = data;
    cur = head;
    int nomor = 1;

    while (nomor < pos - 1)
    {
        cur = cur->next;
        nomor++;
    }
    temp->next = cur->next;
    cur->next = temp;
}

// Add new node at the rear.
void addRear(int data)
{
    temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (tail == nullptr)
    {
        // Jika linked list kosong, inisialisasi baik head dan tail dengan node baru.
        head = temp;
        tail = temp;
    }
    else
    {
        // Jika linked list tidak kosong, tambahkan node baru setelah tail dan perbarui tail.
        tail->next = temp;
        tail = temp;
    }
}

// Remove front node.
void delFront()
{
    del = head;
    head = head->next;
    delete del;
}

// Remove node after the given value.
void delMid(int data)
{
    // Tambahkan logika penghapusan di sini
}

// Remove rear node.
void delRear()
{
    if (head == nullptr) {
        cout << "Linked list sudah kosong." << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = nullptr;
    delete del;
}

// Print single linked list.
void printList()
{
    cur = head;

    while (cur != nullptr)
    {
        cout << cur->data;
        if (cur->next != nullptr) {
            cout << " -> ";
        }
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

// Main function.
int main()
{
    head = nullptr; // Initialize head dengan nullptr
    tail = nullptr; // Initialize tail dengan nullptr
    string i;
    int data, pos;
    int pil;
    int exit = 0;

    while (!exit)
    {
        system("cls");
        cout << "|============================|" << endl;
        cout << "|     SINGLE LINKED LIST     |" << endl;
        cout << "|============================|" << endl;

        cout << "1. Tambah data di depan\n2. Tambah data di tengah\n3. Tambah data di akhir\n";
        cout << "4. Hapus data di depan\n6. Hapus data di akhir\n";
        cout << "7. Cetak list\n8. Keluar\n";
        cout << "Pilihan menu = ";
        cin >> pil;

        switch (pil)
        {
        case 1: // Add new node to the front
            cout << "\nMasukkan nilai: ";
            cin >> data;
            addFront(data);
            break;

        case 2: // Add new node to the middle
            cout << endl;
            printList();
            cout << endl;
            cout << "Masukkan nilai: ";
            cin >> data;
            cout << "Nilai dimasukkan ke posisi: ";
            cin >> pos;
            addMid(data, pos);
            break;

        case 3: // Add new node to the rear
            cout << "\nMasukkan nilai: ";
            cin >> data;
            addRear(data);
            break;

        case 4: // Delete front node
            delFront();
            break;

        case 5: // Delete middle node
            delMid(data);
            break;

        case 6: // Delete rear node
            delRear();
            break;

        case 7: // Print single linked list
            printList();
            cout << "[Tekan 'x' Untuk Lanjut] ";
            cin >> i;
            break;

        case 8:
            exit = 1;
            break;

        default:
            break;
        }
    }

    return 0;
}
