#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r, hasil_luas;
    float pi = 22.0 / 7;
    printf("Masukan jari-jari lingkaran : ");
    scanf("%d", &r);
    hasil_luas = pi * r * r;
    printf("Hasil = %d", hasil_luas);
    return 0;
}