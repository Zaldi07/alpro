#include <stdio.h>

int main()
{
    int hargaBensin = 10000;
    float konsumsiPerKM = 0.1;

    // Data pesanan
    int argo1 = 21000, jarak1 = 7;
    int argo2 = 105000, jarak2 = 35;
    int argo3 = 150000, jarak3 = 45;

    // Hitung biaya bensin
    int totalJarak = jarak1 + jarak2 + jarak3;
    int totalPendapatan = argo1 + argo2 + argo3;
    float totalBiayaBensin = (jarak1 + jarak2 + jarak3) * konsumsiPerKM * hargaBensin;
    float pendapatanBersih = totalPendapatan - totalBiayaBensin;

    printf("Total Pendapatan Kotor: Rp %d\n", totalPendapatan);
    printf("Total Harga Bensin: Rp %.0f\n", totalBiayaBensin);
    printf("Total Pendapatan Bersih: Rp %.0f\n", pendapatanBersih);

    return 0;
}
