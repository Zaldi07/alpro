#include <stdio.h>

int main()
{
    int hargaHP = 1000000, hargaLaptop = 5000000, hargaPower = 100000;
    float diskonHP = 0.15, diskonLaptop = 0.05, diskonPower = 0.20;

    // jumlah beli
    int jmlHP = 2, jmlLaptop = 1, jmlPower = 2;

    // hitung harga setelah diskon
    float totalLaptop = jmlLaptop * (hargaLaptop - (hargaLaptop * diskonLaptop));
    float totalHP = jmlHP * (hargaHP - (hargaHP * diskonHP));
    float totalPower = jmlPower * (hargaPower - (hargaPower * diskonPower));

    float totalBayar = totalLaptop + totalHP + totalPower;

    printf("Total harga setelah diskon: Rp %.0f\n", totalBayar);
    return 0;
}
