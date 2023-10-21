#include <stdio.h>
#include <conio.h>

int main()
{
    int x;
    int *px;

    x = 10;
    px = &x;

    printf("nilai x akses langsung = %d\n", x);
    printf("alamat nilai x = %d\n", px);
    printf("akses tak langsung dengan pointer = %d", *px);

    return 0;
}