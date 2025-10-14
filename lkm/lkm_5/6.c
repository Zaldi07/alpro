#include <stdio.h>

int main()
{
    int jumlahHari, totalPengunjung;
    float rataRata;
    printf("=== Program Rata-rata Pengunjung Toko ===\n");
    printf("Masukan jumlah hari berjualan :");
    scanf("%d", &jumlahHari);
    int pengunjung[jumlahHari];
    for (int i = 0; i < jumlahHari; i++)
    {
        printf("Masukan jumlah pengunjung hari ke-%d: ", i + 1);
        scanf("%d", &pengunjung[i]);
        totalPengunjung += pengunjung[i];
    }
    rataRata = (float)totalPengunjung / jumlahHari;

    printf("Rata-rata pengunjung per hari : %.2f", rataRata);

    return 0;
}