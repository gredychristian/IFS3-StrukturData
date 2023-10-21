#include <stdio.h>

//10, 12
//pass by value
int tambahkan(int a, int b)
{
    return a + b;
}

int ptrTambahkan(int *a, int *b)
{
    return *a + *b;
}

int main()
{
    int angkaA = 10;
    int angkaB = 12;

    printf("%d\n", tambahkan(angkaA, angkaB));
    printf("%d\n", ptrTambahkan(&angkaA, &angkaB));
    return 0;
}