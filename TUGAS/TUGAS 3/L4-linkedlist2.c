#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void traverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);

int main()
{
    node *head = NULL;
    char pilih;
    system("cls");

    do
    {
        printf("\n>>> PROGRAM LINKED LIST <<<\n\n");
        printf("1. Tambahkan data di Depan.\n");
        printf("2. Tambahkan data di Tengah.\n");
        printf("3. Tambahkan data di Akhir.\n");
        printf("4. Hapus data di Tengah.\n");
        printf("5. Cetak isi list.\n");
        printf("x. Keluar.\n");
        printf("Masukkan pilihan Anda -> ");
        fflush(stdin);
        scanf(" %c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4')
            hapusData(&head);
        else if (pilih == '5')
        {
            traverse(head);
            printf("NULL\n");
            printf("(Enter untuk Lanjut)");
            fflush(stdin);
            getch();
            system("cls");
        }
    } while (pilih != 'x');

    return 0;
}

void tambahAwal(node **head)
{
    int bil;
    node *pNew;

    printf("Masukkan bilangan = ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
    }
    else
    {
        printf("Alokasi memori Gagal");
    }
    system("cls");
}

void tambahData(node **head)
{
    int pos, bil;
    node *pNew, *pCur;

    traverse(*head);
    printf("\nPosisi penyisipan setelah data = ");
    scanf("%d", &pos);
    printf("Bilangan yang dimasukkan = ");
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("Node tidak ditemukan");
    }
    else if (pNew == NULL)
    {
        printf("Alokasi memori gagal");
    }
    else
    {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
    printf("\n(Enter untuk Lanjut)");
    getch();
    system("cls");
}

void tambahAkhir(node **head)
{
    int bil;
    node *pNew, *pCur;

    pCur = *head;
    while (pCur != NULL && pCur->next != NULL)
    {
        pCur = pCur->next;
    }

    printf("Masukkan bilangan = ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = NULL;

        if (pCur != NULL)
        {
            pCur->next = pNew;
        }
        else
        {
            *head = pNew;
        }
    }
    else
    {
        printf("Alokasi memori Gagal");
    }
    system("cls");
}

void hapusData(node **head)
{
    int pos;
    node *pCur = *head;
    node *pPre = NULL;

    traverse(*head);
    printf("\nData yang ingin dihapus = ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pPre = pCur;
        pCur = pCur -> next;
    }

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan (Enter untuk Lanjut)\n");
        getch();
    }

    else
    {
        if (pPre == NULL)
        {
            *head = pCur -> next;
        }
        else
        {
            pPre -> next = pCur -> next;
        }
        free(pCur);
        printf("\nBerhasil menghapus data (Enter untuk Lanjut)\n");
        getch();
    }
    system("cls");
}

void traverse(node *head)
{
    node *pWalker;

    pWalker = head;
    printf("\n");
    while (pWalker != NULL)
    {
        printf("%d", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != NULL)
        {
            printf(" -> ");
        }
    }
    printf(" -> ");
}
/*
void insertNode(node **head, node *pPre, node *pNew)
{
    if (pPre == NULL)
    {
        pNew->next = *head;
        *head = pNew;
    }
    else
    {
        pNew->next = pPre->next;
        pPre->next = pNew;
    }
}
*/