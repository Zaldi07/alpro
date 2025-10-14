#include <stdio.h>

int main()
{
    int bilanganBulat[15];
    printf("Masukan 15 bilangan bulat acak:");
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &bilanganBulat[i]);
    }

    printf("Bilangan ganjil :");
    for (int j = 0; j < 15; j++)
    {
        if (bilanganBulat[j] % 2 != 0)
        {
            printf("%d ", bilanganBulat[j]);
        }
    }

    printf("\nBilangan genap :");
    for (int k = 0; k < 15; k++)
    {
        if (bilanganBulat[k] % 2 == 0)
        {
            printf("%d ", bilanganBulat[k]);
        }
    }

    printf("\n--------------------------------");

    return 0;
}