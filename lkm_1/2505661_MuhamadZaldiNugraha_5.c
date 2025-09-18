#include <stdio.h>

int main()
{
    // Harga buku (konstanta)
    int hargaOlahraga = 13000;
    int hargaPKN = 17500;
    int hargaBahasa = 20000;

    // Variabel jumlah pesanan
    int jmlOlahraga, jmlPKN, jmlBahasa;

    // Input jumlah buku
    printf("=========== Pembelian Buku ===========\n");
    printf("Jumlah pemesanan buku Olahraga : ");
    scanf("%d", &jmlOlahraga);
    printf("Jumlah pemesanan buku PKN : ");
    scanf("%d", &jmlPKN);
    printf("Jumlah pemesanan buku Bahasa Indonesia : ");
    scanf("%d", &jmlBahasa);

    // Hitung total
    int total = (jmlOlahraga * hargaOlahraga) + (jmlPKN * hargaPKN) + (jmlBahasa * hargaBahasa);

    // Output total pembelian
    printf("\nTotal pembelian: Rp. %d\n", total);

    return 0;
}
