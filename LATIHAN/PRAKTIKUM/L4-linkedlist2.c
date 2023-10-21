#include <stdio.h>
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
void traverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);

int main()
{
    node *head = NULL;
    char pilih;

    do
    {
        printf("Masukkan pilihan\n");
        printf("1. Tambahkan data di Depan.\n");
        printf("2. Tambahkan data di Tengah.\n");
        printf("3. Tambahkan data di Akhir.\n");
        printf("4. Cetak isi list.\n");
        printf("Masukkan pilihan Anda (q = Keluar) -> ");
        fflush(stdin);
        scanf(" %c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4')
        {
            traverse(head);
            printf("NULL\n");
            printf("\nTekan Enter untuk lanjut...");
            fflush(stdin);
            getchar();
        }
    } while (pilih != 'q');

    return 0;
}

void tambahAwal(node **head)
{
    int bil;
    node *pNew;

    printf("Masukkan bilangan -> ");
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
}

void tambahData(node **head)
{
    int pos, bil;
    node *pNew, *pCur;

    traverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    scanf("%d", &pos);
    printf("Bilangan : ");
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
}

void tambahAkhir(node **head)
{
    int bil;
    node *pNew, *pCur;

    traverse(*head);

    pCur = *head;
    while (pCur != NULL && pCur->next != NULL)
    {
        pCur = pCur->next;
    }

    printf("Masukkan bilangan -> ");
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
}

void traverse(node *head)
{
    node *pWalker;

    pWalker = head;
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