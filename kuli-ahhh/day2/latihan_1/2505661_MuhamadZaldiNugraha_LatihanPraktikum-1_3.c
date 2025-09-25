#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Harga barang dan jumlah pembelian
    int hargaBaju = 100000, jmlBaju = 2;
    int hargaCelana = 150000, jmlCelana = 1;
    int hargaSepatu = 200000, jmlSepatu = 3;
    // Total sebelum diskon
    int totalHargaBaju = hargaBaju * jmlBaju;
    int totalHargaCelana = hargaCelana * jmlCelana;
    int totalHargaSepatu = hargaSepatu * jmlSepatu;

    // Menjumlahkan total sebelum diskon

    int totalSebelumDiskon = totalHargaBaju + totalHargaCelana + totalHargaSepatu;

    // Total sesudah diskon
    int totalBajuDiskon = totalHargaBaju - (totalHargaBaju * 5 / 100);
    int totalCelanaDiskon = totalHargaCelana - (totalHargaCelana * 32 / 100);
    int totalSepatuDiskon = totalHargaSepatu - (totalHargaSepatu * 56 / 100);

    // menjumlahkan total sesudah diskon
    float totalSesudahDiskon = totalBajuDiskon + totalCelanaDiskon + totalSepatuDiskon;

    // Output
    printf("Total sebelum diskon = Rp %d\n", totalSebelumDiskon);
    printf("Total sesudah diskon = Rp %.0f\n", totalSesudahDiskon);

    return 0;
}
