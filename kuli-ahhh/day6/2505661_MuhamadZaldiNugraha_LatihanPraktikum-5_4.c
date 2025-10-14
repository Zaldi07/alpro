#include <stdio.h>
int main()
{
    char hari[7][10] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
    char sesi[3][10] = {"Pagi", "Siang", "Sore"};
    int jumlahPengunjung[7][3];
    int totalPagi = 0;
    int totalSiang = 0;
    int totalSore = 0;

    printf("=== Input Data Pengunjung Perpustakaan ===\n");

    for (int i = 0; i < 7; i++)
    {
        printf("Hari %s:\n", hari[i]);
        for (int j = 0; j < 3; j++)
        {
            printf("Masukan jumlah pengunjung sesi %s: ", sesi[j]);
            scanf("%d", &jumlahPengunjung[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < 7; k++)
    {
        int totalPengunjung = 0;
        printf("%s:\n", hari[k]);
        for (int l = 0; l < 3; l++)
        {
            printf("    Sesi %s : %d Pengunjung\n", sesi[l], jumlahPengunjung[k][l]);
            totalPengunjung += jumlahPengunjung[k][l];
        }
        printf("    Total pengunjung hari %s : %d\n", hari[k], totalPengunjung);
        printf("\n");
    }

    for (int n = 0; n < 7; n++)
    {
        totalPagi += jumlahPengunjung[n][0];
        totalSiang += jumlahPengunjung[n][1];
        totalSore += jumlahPengunjung[n][2];
    }

    float rataPagi = (float)totalPagi / 7;
    float rataSiang = (float)totalSiang / 7;
    float rataSore = (float)totalSore / 7;
    printf("===== Rata-rata pengunjugn persesi =====\n");
    printf("Sesi pagi: %.2f Pengunjung rata-rata\n", rataPagi);
    printf("Sesi siang: %.2f Pengunjung rata-rata\n", rataSiang);
    printf("Sesi sore: %.2f Pengunjung rata-rata\n", rataSore);

    return 0;
}