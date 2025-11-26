#include <stdio.h>
#include <string.h>
int main()
{
    int liter, total = 0;
    char lanjut[10];
    int hargaBensin = 13500;

    printf("Apakah ingin mengisi bensin? (ya/tidak): ");
    scanf(" %s", &lanjut);

    while (strcmp(lanjut, "ya") == 0 || strcmp(lanjut, "Ya") == 0)
    {
        printf("Masukan jumlah liter: ");
        scanf("%d", &liter);
        printf("Apakah ingin mengisi bensin? (ya/tidak): ");
        scanf(" %s", &lanjut);

        total += hargaBensin * liter;
    }
    printf("Total yang harus dibayar: Rp%d", total);
    return 0;
}