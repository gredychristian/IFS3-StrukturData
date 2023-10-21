#include <stdio.h>
#include <stdlib.h>
// CIRCULAR LINKED LIST
// IN C LANGUAGE

// STRUCT NODE
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// INSERT NODE
void insertNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    system("cls");
}

// DELETE NODE
void deleteNode(int data)
{
    if (head == NULL) {
        printf("Circular Linked List kosong.\n");
        return;
    }
    struct Node *current = head, *prev = NULL;
    int found = 0;

    do {
        if (current->data == data) {
            if (current == head) {
                struct Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                head = head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            found = 1;
            printf("Data %d telah dihapus dari list.\n", data);
            break;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    if (!found) {
        printf("Data %d tidak ditemukan dalam list.\n", data);
    }
    printf("(Enter untuk Lanjut)");
    fflush(stdin);
    getchar();
    system("cls");
}

// DISPLAY NODE
void display()
{
    if (head == NULL) {
        printf("Circular Linked List kosong.\n");
        return;
    }

    struct Node *current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("...\n");
}

// MAIN MENU
int main() {
    int menus, data;
    system("cls");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampilkan Data\n");
        printf("4. Keluar\n");
        printf("Pilih operasi (1/2/3/4): ");
        scanf("%d", &menus);

        switch (menus) {
            case 1:
                printf("Masukkan data yang akan ditambahkan: ");
                scanf("%d", &data);
                insertNode(data);
                break;
            case 2:
                if (head == NULL)
                {
                    printf("Circular Linked List kosong.\n");
                }
                else
                {
                    display();
                    printf("Masukkan data yang akan dihapus: ");
                    scanf("%d", &data);
                    deleteNode(data);
                }
                break;
            case 3:
                printf("Isi dari Circular Linked List:\n");
                display();
                printf("(Enter untuk Lanjut)");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                system("cls");
                exit(0);
            default:
                system("cls");
        }
    }

    return 0;
}
