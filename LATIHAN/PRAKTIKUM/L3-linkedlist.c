#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//===
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void transverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);

//===

int main()
{
    node *head;
    char pilih;

    head = NULL;
    do
    {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambahkan data di Depan.\n");
        printf("2. Tambahkan data di Tengah.\n");
        printf("4. Cetak isi list\n");
        printf("Masukkan pilihan Anda (q = Keluar) -> ");
        fflush(stdin);
        scanf("%c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '4')
            transverse(head);
        getch();
    }
    while (pilih != 'q');

    return 0;
}

//===
/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/
//===
void tambahAwal(node **head)
{
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    fflush("Masukkan bilangan -> ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = NULL;
        pNew->next = *head;
        *head = pNew;
    }

    else
    {
        printf("Alokasi memori Gagal");
        getch();
    }
}

//===
void tambahData(node **head)
{
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    transverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur -> data != pos)
    {
        pCur = pCur -> next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan");
        getch();
    }

    else if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal");
        getch();
    }

    else
    {
        pNew -> data = bil;
        pNew -> next = NULL;
        pNew -> next = pCur -> next;
        pCur -> next = pNew;
    }
}

//===
void transvers(node *head)
{
    node *pWalker;

    system("cls");
        pWalker = head;
        while (pWalker != NULL)
        {
            printf("%d", pWalker -> data);
            pWalker = pWalker -> next;
            printf(" -> ");
        }
        printf("NULL");
}

//===
void insertNode(node **head, node *pPre, node *pNew){
    
    if (pPre == NULL)
    {
	    pNew -> next = *head;
       *head = pNew;
    }
    
    else
    {
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
    }
}

