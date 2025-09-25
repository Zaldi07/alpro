#include <stdio.h>
#include <stdlib.h>

int main()
{
    // deklarasi harga menu makanan
    int hargaNasi = 30000;
    int hargaMie = 20000;
    int hargaSate = 10000;

    // variabel untuk menyimpan inputan user
    int jmlNasi, jmlMie, jmlSate;

    // Inputan
    printf("POV: Jadi pelayanan restoran\n");
    printf("Mau beli berapa Nasi Goreng? ");
    scanf("%d", &jmlNasi);

    printf("Mau beli berapa Mie Goreng? ");
    scanf("%d", &jmlMie);

    printf("Mau beli berapa Sate Ayam? ");
    scanf("%d", &jmlSate);

    // menghitung total harga pesanan
    int total = (jmlNasi * hargaNasi) + (jmlMie * hargaMie) + (jmlSate * hargaSate);

    // Output
    printf("\n=== Rincian Pesanan Warung Mang Ohim ===\n");
    printf("Nasi Goreng WokWok (%d x Rp%d) = Rp %d\n", jmlNasi, hargaNasi, jmlNasi * hargaNasi);
    printf("Mie Goreng TekTek  (%d x Rp%d) = Rp %d\n", jmlMie, hargaMie, jmlMie * hargaMie);
    printf("Sate Ayam Madura  (%d x Rp%d) = Rp %d\n", jmlSate, hargaSate, jmlSate * hargaSate);

    printf("\nTotal yang harus dibayar pelanggan = Rp %d\n", total);

    return 0;
}
 