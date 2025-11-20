#include <stdio.h>
int main()
{
    int jumlah = 0;
    float total = 0, nilai = 0;
    char lanjut;
    do
    {
        printf("Masukan nilai mahasiswa: ");
        scanf("%f", &nilai);

        printf("Apakah ingin menambah data mahasiswa lagi ? (y/t) : ");
        scanf(" %c", &lanjut);
        total += nilai;
        jumlah += 1;

    } while (lanjut == 'Y' || lanjut == 'y');

    printf("\nJumlah mahasiswa: %d\n", jumlah);
    printf("Total nilai: %.2f\n", total);
    printf("Rata-rata nilai: %.2f\n ", (float)total / jumlah);
}