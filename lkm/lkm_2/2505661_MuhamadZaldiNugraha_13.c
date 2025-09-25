#include <stdio.h>

int main()
{
    int kode;
    char input[30];

    printf("Metode Transfer\n");
    printf("(1) Via Bank\n");
    printf("(2) Via Virtual Account\n");
    printf("(3) Via E-Wallet\n");
    printf("Pilih metode transfer: ");
    scanf("%d", &kode);

    switch (kode)
    {
    case 1:
        printf("Via Bank\n");
        printf("Masukkan nomor rekening: ");
        scanf("%s", input);
        printf("Transfer berhasil.\n");
        break;
    case 2:
        printf("Via Virtual Account\n");
        printf("Masukkan kode VA: ");
        scanf("%s", input);
        printf("Transfer berhasil.\n");
        break;
    case 3:
        printf("Via E-Wallet\n");
        printf("Masukkan nomor telepon: ");
        scanf("%s", input);
        printf("Transfer berhasil.\n");
        break;
    default:
        printf("Kode tidak dikenal\n");
    }

    return 0;
}
