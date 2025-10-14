#include <stdio.h>

int main()
{
    int bilanganBulat[10], jumlahPenjumlahanGanjil = 0, jumlahPerkalianGenap = 1;
    printf("Masukan 10 bilangan bulat acak:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &bilanganBulat[i]);
    }

    for (int j = 0; j < 10; j++)
    {
        if (j % 2 != 0)
        {
            jumlahPenjumlahanGanjil += bilanganBulat[j];
        }
        else
        {
            jumlahPerkalianGenap *= bilanganBulat[j];
        }
    }

    printf("Hasil penjumlahan bilangan dengan indeks ganjil : %d\n", jumlahPenjumlahanGanjil);
    printf("Hasil perkalian bilangan dengan indeks genap : %d\n", jumlahPerkalianGenap);
    printf("--------------------------------");

    return 0;
}