#include <stdio.h>

int main()
{
    int jumlahLari;
    int hasil = 0;

    printf("Masukan jumlah berapa kali lari dalam seminggu: ");
    scanf("%d", &jumlahLari);

    int jumlahLangkah[jumlahLari];

    for (int i = 1; i <= jumlahLari; i++)
    {
        printf("Masukan jumlah langkah lari hari ke-%d: ", i);
        scanf("%d", &jumlahLangkah[i]);

        hasil += jumlahLangkah[i];
    }

    printf("Total langkah selama seminggu: %d langkah", hasil);

    return 0;
}