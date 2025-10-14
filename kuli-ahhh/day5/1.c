#include <stdio.h>

int main()
{
    int pilihan, n, i, j, spasi;

    printf("Pilih jenis segitiga:\n");
    printf("1. Segitiga Siku-siku (kota)\n");
    printf("2. Segitiga Sama Kaki\n");
    printf("Masukkan pilihan (1/2): ");
    scanf("%d", &pilihan);

    printf("Masukkan tinggi segitiga: ");
    scanf("%d", &n);

    if (pilihan == 1)
    {
        // Segitiga siku-siku
        for (i = 1; i <= n; i++)
        {
            for (j = 1;  <= i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (pilihan == 2)
    {
        // Segitiga sama kaki
        for (i = 1; i <= n; i++)
        {
            for (spasi = 1; spasi <= n - i; spasi++)
            {
                printf(" ");
            }
            for (j = 1; j <= (2 * i - 1); j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else
    {
        printf("Pilihan tidak valid.\n");
    }

    return 0;
}