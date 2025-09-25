#include <stdio.h>

int main()
{
    int pilihan, jarak;
    int tarif_per_km;
    int total, total_setelah_diskon;

    printf("Pilih kendaraan:\n");
    printf("1. Motor (Rp2000/km)\n");
    printf("2. Mobil (Rp3500/km)\n");
    printf("3. Mobil Premium (Rp6000/km)\n");
    printf("4. Bus (Rp8000/km)\n");

    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
        tarif_per_km = 2000;
    }
    else if (pilihan == 2)
    {
        tarif_per_km = 3500;
    }
    else if (pilihan == 3)
    {
        tarif_per_km = 6000;
    }
    else if (pilihan == 4)
    {
        tarif_per_km = 8000;
    }
    else
    {
        printf("Pilihan kendaraan tidak tersedia.\n");
        return 0;
    }

    printf("Masukkan jarak perjalanan (km): ");
    scanf("%d", &jarak);

    total = tarif_per_km * jarak;
    printf("Tarif sebelum diskon: Rp%d\n", total);

    if (jarak > 50)
    {
        total_setelah_diskon = total - (total * 10 / 100);
        printf("Diskon 10%% diterapkan\n");
    }
    else
    {
        total_setelah_diskon = total;
    }

    printf("Total tarif: Rp%d\n", total_setelah_diskon);

    return 0;
}
