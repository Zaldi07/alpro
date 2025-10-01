#include <stdio.h>

int main()
{
    int pilihan, porsi;
    float harga, total, diskon = 0, total_bayar;

    printf("=== Program Kasir Kantin Kampus ===\n");
    printf("Menu:\n");
    printf("1. Nasi Goreng  Rp15.000\n");
    printf("2. Mie Ayam     Rp12.000\n");
    printf("3. Soto Ayam    Rp10.000\n");
    printf("-----------------------------------\n");
    printf("Pilih menu (1-3): ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        printf("Masukkan jumlah porsi: ");
        scanf("%d", &porsi);
        harga = 15000;
        total = harga * porsi;
        if (porsi > 5)
        {
            diskon = total * 0.10;
        }
        total_bayar = total - diskon;
        printf("Anda membeli Nasi Goreng %d porsi\n", porsi);
        printf("Total bayar: Rp%.0f\n", total_bayar);
        break;

    case 2:
        printf("Masukkan jumlah porsi: ");
        scanf("%d", &porsi);
        harga = 12000;
        total = harga * porsi;
        if (porsi > 6)
        {
            diskon = total * 0.08;
        }
        total_bayar = total - diskon;
        printf("Anda membeli Mie Ayam %d porsi\n", porsi);
        printf("Total bayar: Rp%.0f\n", total_bayar);
        break;

    case 3:
        printf("Masukkan jumlah porsi: ");
        scanf("%d", &porsi);
        harga = 10000;
        total = harga * porsi;
        if (porsi >= 3)
        {
            diskon = total * 0.05;
        }
        total_bayar = total - diskon;
        printf("Anda membeli Soto Ayam %d porsi\n", porsi);
        printf("Total bayar: Rp%.0f\n", total_bayar);
        break;

    default:
        printf("Menu tidak tersedia.\n");
        break;
    }

    return 0;
}
