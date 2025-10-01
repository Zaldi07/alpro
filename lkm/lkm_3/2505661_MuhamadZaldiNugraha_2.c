#include <stdio.h>
int main()
{
    int jumlahPenonton, umurPenonton, maxPenonton = 100, hargaTiket;
    printf("Masukan jumlah penonton saat ini: ");
    scanf("%d", &jumlahPenonton);
    if (jumlahPenonton < 100)
    {
        int sisaKursi = maxPenonton - jumlahPenonton - 1;
        printf("Masukan umur penonton baru: ");
        scanf("%d", &umurPenonton);
        if (umurPenonton < 5)
        {

            printf("Gratis untuk balita\n");
            printf("Sisa kursi tersedia : %d orang\n", sisaKursi);
        }
        else if (umurPenonton >= 5 && umurPenonton <= 15)
        {
            hargaTiket = 45000;
            printf("harga tiket Rp 45.000\n");
            printf("Sisa kursi tersedia : %d orang\n", sisaKursi);
        }
        else if (umurPenonton > 15 && umurPenonton <= 60)
        {
            hargaTiket = 50000;
            printf("harga tiket Rp 50.000\n");
            printf("Sisa kursi tersedia : %d orang\n", sisaKursi);
        }
        else
        {
            hargaTiket = 40000;
            printf("harga tiket Rp 40.000\n");
            printf("Sisa kursi tersedia : %d orang\n", sisaKursi);
        }
    }
    else
    {
        printf("Kursi sudah penuh!\n");
    }

    return 0;
}
