#include <stdio.h>

struct Barang
{
    char nama[24];
    int harga;
    int jumlah;
};

void showData(struct Barang barang[], int jmlBrg)
{
    printf("\nDaftar Barang\n");
    printf("Nama Barang\t Harga\t Jumlah\tTotal Nilai\n");

    for (int i = 0; i < jmlBrg; i++)
    {
        printf("%-10s\t %-4d\t %-4d\t %-10d \n", barang[i].nama, barang[i].harga, barang[i].jumlah, barang[i].harga * barang[i].jumlah);
    }
}

void handleInput(struct Barang barang[], int jmlBrg)
{
    printf("Input Data Barang:\n");
    for (int i = 0; i < jmlBrg; i++)
    {
        printf("Barang ke-%d\n", i + 1);
        printf("Nama Barang : ");
        scanf(" %[^\n]s", barang[i].nama);
        printf("Harga Satuan: ");
        scanf("%d", &barang[i].harga);
        printf("Jumlah Stok : ");
        scanf("%d", &barang[i].jumlah);
    }
}

int main()
{
    int jmlBrg = 5;
    struct Barang data[jmlBrg];
    handleInput(data, jmlBrg);
    showData(data, jmlBrg);

    return 0;
}