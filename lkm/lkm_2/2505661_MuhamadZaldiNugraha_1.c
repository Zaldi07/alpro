#include <stdio.h>
int main()
{
    int jumlah;
    printf("Berapa total mahasiwa yang mengontrak mata kuliah Algoritma Pemograman sekarang ?");
    scanf("%d", &jumlah);
    if (jumlah < 45)
    {
        printf("Kuota kelas masih tersedia\n");
    }
    return 0;
}
