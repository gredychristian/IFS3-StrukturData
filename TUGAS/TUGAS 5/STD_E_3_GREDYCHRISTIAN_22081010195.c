#include <stdio.h>
#include <stdlib.h>

//GREDY CHRISTIAN HENDRAWAN PUTRA
//NPM 22081010195
//INFORMATIKA - UPN VETERAN JAWA TIMUR

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void tambahAwal(node **head, node **tail);
void tambahData(node **head, node **tail);
void tambahAkhir(node **head, node **tail);
void hapusAwal(node **head, node **tail);
void hapusAkhir(node **head, node **tail);
void hapusData(node **head, node **tail);
void traverseForward(node *head);
void traverseBackward(node *tail);
void insertNode(node **head, node **tail, node *pPre, node *pNew);
int hitungJumlah(node *head);
int hitungNominal(node *head);

int main()
{
    node *head = NULL;
    node *tail = NULL;
    char pilih;
    system("cls");

    do
    {
        printf("\n>>> PROGRAM DOUBLE LINKED LIST <<<\n\n");
        printf("1. Tambahkan data di Depan.\n");
        printf("2. Tambahkan data di Tengah.\n");
        printf("3. Tambahkan data di Akhir.\n");
        printf("4. Hapus data di Depan.\n");
        printf("5. Hapus data di Tengah.\n");
        printf("6. Hapus data di Akhir.\n");
        printf("7. Cetak isi list (maju).\n");
        printf("8. Cetak isi list (mundur).\n");
        printf("9. Hitung jumlah data.\n");
        printf("0. Hitung total nominal data.\n");
        printf("x. Keluar.\n");
        printf("Masukkan pilihan Anda -> ");
        fflush(stdin);
        scanf(" %c", &pilih);
        if (pilih == '1')
            tambahAwal(&head, &tail);
        else if (pilih == '2')
            tambahData(&head, &tail);
        else if (pilih == '3')
            tambahAkhir(&head, &tail);
        else if (pilih == '4')
            hapusAwal(&head, &tail);
        else if (pilih == '5')
            hapusData(&head, &tail);
        else if (pilih == '6')
            hapusAkhir(&head, &tail);
        else if (pilih == '7')
            traverseForward(head);
        else if (pilih == '8')
            traverseBackward(tail);
        else if (pilih == '9')
        {
            int jumlah = hitungJumlah(head);
            printf("Jumlah data dalam linked list: %d\n", jumlah);
            printf("(Enter untuk Lanjut)");
            fflush(stdin);
            getchar();
            system("cls");
        }
        else if (pilih == '0')
        {
            int total = hitungNominal(head);
            printf("Total nominal data dalam linked list: %d\n", total);
            printf("(Enter untuk Lanjut)");
            fflush(stdin);
            getchar();
            system("cls");
        }
    } while (pilih != 'x');

    return 0;
}

void tambahAwal(node **head, node **tail)
{
    int bil;
    node *pNew;

    printf("Masukkan bilangan = ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->prev = NULL;
        pNew->next = *head;

        if (*head != NULL)
        {
            (*head)->prev = pNew;
        }

        *head = pNew;

        if (*tail == NULL)
        {
            *tail = pNew;
        }
    }
    else
    {
        printf("Alokasi memori Gagal");
    }
    system("cls");
}

void tambahData(node **head, node **tail)
{
    int pos, bil;
    node *pNew, *pCur;

    traverseForward(*head);
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
        pNew->prev = pCur;
        pNew->next = pCur->next;

        if (pCur->next != NULL)
        {
            pCur->next->prev = pNew;
        }

        pCur->next = pNew;

        if (pCur == *tail)
        {
            *tail = pNew;
        }
    }
    printf("\nData berhasil ditambahkan setelah data %d\n", pos);
    printf("(Enter untuk Lanjut)");
    getchar();
    system("cls");
}

void tambahAkhir(node **head, node **tail)
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
        pNew->prev = pCur;
        pNew->next = NULL;

        if (pCur != NULL)
        {
            pCur->next = pNew;
        }
        else
        {
            *head = pNew;
        }

        *tail = pNew;
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

void hapusAwal(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    node *hapus = *head;
    *head = (*head)->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    else
    {
        *tail = NULL;
    }

    free(hapus);
    printf("Data di awal linked list berhasil dihapus\n");
    printf("(Enter untuk Lanjut)");
    getchar();
    system("cls");
}

void hapusAkhir(node **head, node **tail)
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
        *tail = NULL;
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
    *tail = pCur;
    printf("Data terakhir dalam linked list berhasil dihapus\n");
    printf("(Enter untuk Lanjut)");
    getchar();
    system("cls");
}

void hapusData(node **head, node **tail)
{
    int pos;
    node *pCur = *head;
    node *pPre = NULL;

    traverseForward(*head);
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

        if (pCur->next != NULL)
        {
            pCur->next->prev = pPre;
        }

        if (pCur == *tail)
        {
            *tail = pPre;
        }

        free(pCur);
        printf("\nData %d berhasil dihapus\n", pos);
    }
    printf("(Enter untuk Lanjut)");
    getchar();
    system("cls");
}

void traverseForward(node *head)
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

void traverseBackward(node *tail)
{
    node *pWalker = tail;

    printf("\n");
    while (pWalker != NULL)
    {
        printf("%d", pWalker->data);
        pWalker = pWalker->prev;
        if (pWalker != NULL)
        {
            printf(" -> ");
        }
    }
    printf(" -> ");
}

void insertNode(node **head, node **tail, node *pPre, node *pNew)
{
    if (pPre == NULL)
    {
        pNew->next = *head;
        pNew->prev = NULL;
        (*head)->prev = pNew;
        *head = pNew;
    }
    else
    {
        pNew->next = pPre->next;
        pNew->prev = pPre;
        pPre->next = pNew;

        if (pNew->next != NULL)
        {
            pNew->next->prev = pNew;
        }
        else
        {
            *tail = pNew;
        }
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
