#include <stdio.h>
#include <string.h>

struct barang
{
    char kodeBarang[5];
    char namaBarang[15];
    int hargaBarang;
    int stokBarang;
};
// fungsi untuk mencari data barang , jika data ada maka akan return index dan jika tidak ada maka return -1
int searchDataBarang(struct barang arr[], char kode[5], int lengthOfArray)
{
    int dataFound = -1;
    for (int k = 0; k < lengthOfArray; k++)
    {
        if (strcmp(kode, arr[k].kodeBarang) == 0)
        {
            dataFound = k;
        }
    }

    return dataFound;
}
// prosedur untuk menampilkan data barang
void showListStock(struct barang arr[], int lengthOfArray)
{
    printf("%-5s %-10s %-20s %-10s %-10s\n",
           "No", "Kode", "Nama Barang", "Harga", "Stok");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < lengthOfArray; i++)
    {

        printf("%-5d %-10s %-20s %-10d %-10d \n", i + 1, arr[i].kodeBarang, arr[i].namaBarang, arr[i].hargaBarang, arr[i].stokBarang);
    }
    printf("------------------------------------------------------\n");
}

void handleInput(struct barang arr[], int lengthOfArray)
{
    for (int i = 0; i < lengthOfArray; i++)
    {
        printf("\nBarang ke-%d\n", i + 1);
        printf("Kode\t: ");
        scanf(" %[^\n]s", arr[i].kodeBarang);
        printf("Nama\t: ");
        scanf(" %[^\n]s", arr[i].namaBarang);
        printf("Harga\t: ");
        scanf("%d", &arr[i].hargaBarang);
        printf("Stok\t: ");
        scanf("%d", &arr[i].stokBarang);
    }
}

void handleTransaksi(struct barang arr[], int jumlahBarang)
{
    int jumlahTransaksi;
    printf("\n==== FASE 2: PROSES TRANSAKSI ====\n");
    printf("Masukkan jumlah transaksi:");
    scanf("%d", &jumlahTransaksi);
    for (int j = 0; j < jumlahTransaksi; j++)
    {
        char TempkodeBarang[5];
        int tempJumlahBeli = 0, dataFound = 0;
        printf("Transaksi ke-%d\n", j + 1);
        printf("Kode Barang :");
        scanf(" %[^\n]s", TempkodeBarang);

        int idxBrg = searchDataBarang(arr, TempkodeBarang, jumlahBarang);
        if (idxBrg == -1)
        {
            printf("Kode barang %s tidak ditemukan\n", TempkodeBarang);
        }
        else
        {
            printf("Jumlah beli :");
            scanf("%d", &tempJumlahBeli);
            if (arr[idxBrg].stokBarang >= tempJumlahBeli)
            {
                arr[idxBrg].stokBarang = arr[idxBrg].stokBarang - tempJumlahBeli;
                printf("Transaksi %s (Jumlah: %d) berhasil\n\n", arr[idxBrg].namaBarang, tempJumlahBeli);
            }
            else
            {
                printf("Stok %s tidak mencukupi (sisa: %d). Transaksi dibatalkan.\n\n", arr[idxBrg].namaBarang, arr[idxBrg].stokBarang);
            }
        }
    }
};

int main()
{
    int jumlahBarang;

    printf("\n====== FASE 1: INPUT BARANG ======\n");
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlahBarang);

    struct barang data[jumlahBarang];
    handleInput(data, jumlahBarang);

    printf("\n====== DAFTAR STOK AWAL ======\n");
    showListStock(data, jumlahBarang);

    handleTransaksi(data, jumlahBarang);

    printf("\n====== DAFTAR STOK BARANG TERBARU ======\n");
    showListStock(data, jumlahBarang);

    return 0;
}