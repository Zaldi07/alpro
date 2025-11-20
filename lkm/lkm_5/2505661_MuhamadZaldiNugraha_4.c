#include <stdio.h>
int main()
{
    // stok tiket awal
    int stokTiket = 100;
    // array untuk menyimpan nama pembeli dan jumlah tiket yang dibeli
    char namaPembeli[stokTiket][50];
    // array untuk menyimpan jumlah pembelian tiket per pembeli
    int jumlahPembelian[stokTiket];
    // counter pembeli
    int pembeli = 0;

    // loop selama masih ada stok tiket
    while (stokTiket > 0)
    {

        // input nama pembeli dan jumlah tiket yang dibeli
        printf("Masukan nama pembeli untuk costumer ke-%d: ", pembeli + 1);
        scanf(" %s", &namaPembeli[pembeli]);
        int jumlahTiketYangDibeli;
        printf("Masukan jumlah tiket yang dibeli:");
        scanf("%d", &jumlahTiketYangDibeli);

        printf("\n");
        // cek apakah jumlah tiket yang dibeli melebihi stok tiket
        if (jumlahTiketYangDibeli > stokTiket)
        {
            printf("Maaf, stok tiket hanya tersisa %d\n", stokTiket);
            printf("Apakah anda tetap ingin membeli sisa tiket yang tersedia? (Y/N)\n");
            printf("1. Jika iya, maka anda dapat membeli sisa tiket yang tersedia (%d tiket)\n", stokTiket);
            printf("2. Jika tidak, maka pembelian dibatkalkan\n");
            char jawabanUser;
            printf("Jawaban: ");
            scanf(" %c", &jawabanUser);

            // jika user menjawab Y, maka jumlah tiket yang dibeli adalah sisa stok tiket
            if (jawabanUser == 'Y')
            {
                jumlahTiketYangDibeli = stokTiket;
                printf("Pembelian berhasil sebanyak %d tiket.\n", stokTiket);
            }
            else
            {
                // jika user menjawab N, maka pembelian dibatalkan
                printf("Pembelian dibatalkan\n");
                jumlahTiketYangDibeli = 0;
                jumlahPembelian[pembeli] = 0;
            }
        }
        // kurangi stok tiket dengan jumlah tiket yang dibeli
        stokTiket -= jumlahTiketYangDibeli;
        // simpan jumlah tiket yang dibeli ke array jumlahPembelian
        jumlahPembelian[pembeli] = jumlahTiketYangDibeli;
        // printf("sisa tiket %d \n:", stokTiket);

        // increment counter pembeli
        pembeli++;
        if (stokTiket == 0)
        {
            printf("Maaf, tiket sudah habis\n");
            break;
        }
    }
    // tampilkan rekapan penjualan
    int tiketTerjual = 0;
    int totalPenjualan = 0;

    //  penjumlahan tiket terjual dan total penjualan
    for (int i = 0; i < pembeli; i++)
    {

        tiketTerjual += jumlahPembelian[i];
        totalPenjualan += jumlahPembelian[i] * 35000;
    }

    printf("\nRekapan Penjualan\n");
    printf("Sisa tiket : %d\n", stokTiket);
    printf("Jumlah Customer : %d\n", pembeli);
    printf("Tiket terjual : %d\n", tiketTerjual);
    printf("Total Penjualan : Rp%d\n\ ", totalPenjualan);

    // rincian penjualan
    printf("Rincian Penjualan:\n");
    for (int i = 0; i < pembeli; i++)
    {
        printf("%d. %s = %d tiket (Rp%d)\n", i + 1, namaPembeli[i], jumlahPembelian[i], jumlahPembelian[i] * 35000);
    }

    return 0;
}
