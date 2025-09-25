#include <stdio.h>

int main()
{
    int usia, harga;
    char member;

    printf("Masukkan usia pengunjung: ");
    scanf("%d", &usia);

    // Tentukan kategori harga
    if (usia <= 12)
    {
        harga = 20000;
        printf("Kategori: Anak\n");
    }
    else if (usia >= 13 && usia <= 25)
    {
        harga = 30000;
        printf("Kategori: Pelajar\n");
    }
    else if (usia >= 26 && usia <= 60)
    {
        harga = 40000;
        printf("Kategori: Dewasa\n");
    }
    else
    {
        harga = 25000;
        printf("Kategori: Lansia\n");
    }

    // Tanya member
    printf("Apakah punya kartu member? (Y/T): ");
    scanf(" %c", &member); // ada spasi biar gak ke-skip

    if (member == 'Y' || member == 'y')
    {
        harga -= 5000;
        printf("Diskon member sebesar Rp5000 diterapkan.\n");
    }

    printf("Harga tiket akhir: Rp%d\n", harga);

    return 0;
}
