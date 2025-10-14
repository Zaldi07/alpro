#include <stdio.h>

int main()
{
    int jumlahBilanganBulat;
    int totalBilanganGenap = 0;

    printf("Masukan jumlah bilangan bulat: ");
    scanf("%d", &jumlahBilanganBulat);

    int bilanganBulat[jumlahBilanganBulat];

    for (int i = 0; i < jumlahBilanganBulat; i++)
    {
        printf("Masukan bilangan ke-%d: ", i + 1);
        scanf("%d", &bilanganBulat[i]);

        if (bilanganBulat[i] % 2 == 0)
        {
            totalBilanganGenap++;
        }
    }

    printf("Total bilangan genap: %d", totalBilanganGenap);

    return 0;
}