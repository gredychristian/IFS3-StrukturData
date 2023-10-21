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
void hapusAwal(node **head);
void hapusAkhir(node **head);
void hapusData(node **head);
void traverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
int hitungJumlah(node *head);
int hitungNominal(node *head);

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
        printf("4. Hapus data di Depan.\n");
        printf("5. Hapus data di Tengah.\n");
        printf("6. Hapus data di Akhir.\n");
        printf("7. Cetak isi list.\n");
        printf("8. Hitung jumlah data.\n");
        printf("9. Hitung total nominal data.\n");
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
            hapusAwal(&head);
        else if (pilih == '5')
            hapusData(&head);
        else if (pilih == '6')
            hapusAkhir(&head);
        else if (pilih == '7')
        {
            traverse(head);
            printf("NULL\n");
            printf("(Enter untuk Lanjut)");
            fflush(stdin);
            getchar();
            system("cls");
        }
        else if (pilih == '8')
        {
            int jumlah = hitungJumlah(head);
            printf("Jumlah data dalam linked list: %d\n", jumlah);
            printf("(Enter untuk Lanjut)");
            fflush(stdin);
            getchar();
            system("cls");
        }
        else if (pilih == '9')
        {
            int total = hitungNominal(head);
            printf("Total nominal data dalam linked list: %d\n", total);
            printf("(Enter untuk Lanjut)");
            fflush(stdin);
            getchar();
            system("cls");
        }
    }
    
    while (pilih != 'x');

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
    printf("\nData berhasil ditambahkan setelah data %d\n", pos);
    printf("(Enter untuk Lanjut)");
    getchar();
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
    printf("Data terakhir berhasil ditambahkan\n");
    printf("(Enter untuk Lanjut)");
    getchar();
    system("cls");
}

void hapusAwal(node **head)
{
    if (*head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    node *hapus = *head;
    *head = (*head)->next;
    free(hapus);
    printf("Data di awal linked list berhasil dihapus\n");
    printf("(Enter untuk Lanjut)");
    getchar();
    system("cls");
}

void hapusAkhir(node **head)
{
    if (*head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        printf("Data terakhir dalam linked list berhasil dihapus\n");
        printf("(Enter untuk Lanjut)");
        getchar();
        system("cls");
        return;
    }

    node *pCur = *head;
    while (pCur->next->next != NULL)
    {
        pCur = pCur->next;
    }

    free(pCur->next);
    pCur->next = NULL;
    printf("Data terakhir dalam linked list berhasil dihapus\n");
    printf("(Enter untuk Lanjut)");
    getchar();
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
        pCur = pCur->next;
    }

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan\n");
    }
    else
    {
        if (pPre == NULL)
        {
            *head = pCur->next;
        }
        else
        {
            pPre->next = pCur->next;
        }
        free(pCur);
        printf("\nData %d berhasil dihapus\n", pos);
    }
    printf("(Enter untuk Lanjut)");
    getchar();
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

int hitungJumlah(node *head)
{
    int jumlah = 0;
    node *pCur = head;
    while (pCur != NULL)
    {
        jumlah++;
        pCur = pCur->next;
    }
    return jumlah;
}

int hitungNominal(node *head)
{
    int total = 0;
    node *pCur = head;
    while (pCur != NULL)
    {
        total += pCur->data;
        pCur = pCur->next;
    }
    return total;
}
