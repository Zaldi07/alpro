#include <stdio.h>
#include <stdlib.h>

int main()
{
    // mendeklarasikan variabel
    int A, B, C, D, hasil;

    // Proses Input
    printf("Masukkan nilai A: ");
    scanf("%d", &A);

    printf("Masukkan nilai B: ");
    scanf("%d", &B);

    printf("Masukkan nilai C: ");
    scanf("%d", &C);

    printf("Masukkan nilai D: ");
    scanf("%d", &D);

    // Proses Hitung
    hasil = A * B - C + D;

    // Output Hasil
    printf("Hasil dari %d x %d - %d + %d = %d\n", A, B, C, D, hasil);

    return 0;
}