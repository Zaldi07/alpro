#include <stdio.h>

int main()
{
    int jumlahItem, totalHarga;
    printf("Masukan jumlah menu yang akan dipesan: ");
    scanf("%d", &jumlahItem);
    int harga[jumlahItem];
    char namaItem[jumlahItem][30];

    for (int i = 0; i < jumlahItem; i++)
    {
        printf("Masukan nama menu : ");
        scanf("%s", &namaItem[i]);
        printf("Masukan harga menu : ");
        scanf("%d", &harga[i]);
        totalHarga += harga[i];
    }
    printf("Daftar menu yang dipesan: ");

    for (int j = 0; j < jumlahItem; j++)
    {
        printf("%s, ", namaItem[j]);
    }
    printf("\nTotal harga: %d\n", totalHarga);

    return 0;
}