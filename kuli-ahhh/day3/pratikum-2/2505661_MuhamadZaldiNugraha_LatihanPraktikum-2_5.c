#include <stdio.h>

int main()
{
    int pilihan;
    float a, b, hasil;

    printf("Menu:\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Pembagian\n");
    printf("Pilih operasi (1-4): ");
    scanf("%d", &pilihan);

    printf("Masukkan angka pertama: ");
    scanf("%f", &a);
    printf("Masukkan angka kedua: ");
    scanf("%f", &b);

    switch (pilihan)
    {
    case 1:
        hasil = a + b;
        printf("Hasil: %.2f\n", hasil);
        break;
    case 2:
        hasil = a - b;
        printf("Hasil: %.2f\n", hasil);
        break;
    case 3:
        hasil = a * b;
        printf("Hasil: %.2f\n", hasil);
        break;
    case 4:
        if (b != 0)
        {
            hasil = a / b;
            printf("Hasil: %.2f\n", hasil);
        }
        else
        {
            printf("Error: Pembagian dengan nol tidak diperbolehkan!\n");
        }
        break;
    default:
        printf("Pilihan tidak valid!\n");
    }

    return 0;
}
