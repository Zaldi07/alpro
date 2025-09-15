#include <stdio.h>
#include <stdlib.h>
int main()
{
    int jmlSweater, jmlGamis, jmlJaket, total_pesanan, total_setelah_diskon;
    float diskon = 0.1;
    printf("Masukan jumlah pesanan\n");
    printf("Sweater (50.000): ");
    scanf("%d", &jmlSweater);
    printf("Gamis (200.000):");
    scanf("%d", &jmlGamis);
    printf("Jaket (85.000):");
    scanf("%d", &jmlJaket);

    total_pesanan = (jmlSweater * 50000) + (jmlGamis * 200000) + (jmlJaket * 85000);
    printf("total_pesanan: %d\n", total_pesanan);
    if (jmlSweater > 0 && jmlJaket > 0 && jmlGamis > 0)
    {
        total_setelah_diskon = total_pesanan - (total_pesanan * diskon);
        printf("harga setelah diskon: %d", total_setelah_diskon);
    }
    else
    {
        printf("Mohon maaf anda tidak mendapatkan diskon:)");
    }
    return 0;
}