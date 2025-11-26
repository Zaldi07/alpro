#include <stdio.h>
int main()
{
    int kode, harga;
    printf("Masukan kode minuman (1-4): ");
    scanf("%d", &kode);

    switch (kode)
    {
    case 1:
        printf("Anda memilih Teh Botol");
        harga = 5000;
        break;

    case 2:
        printf("Anda memilih Kopi Hitam");
        harga = 7000;
        break;
    case 3:
        printf("Anda memilih Air Mineral");
        harga = 3000;
        break;
    case 4:
        printf("Anda memilih Susu");
        harga = 8000;
        break;
    default:
        printf("Kode tidak tersedia");
        break;
    }

    if (harga > 0)
    {

        printf("\nHarga: Rp%d\n", harga);
    }

    return 0;
}