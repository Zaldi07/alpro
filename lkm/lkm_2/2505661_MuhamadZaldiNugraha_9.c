#include <stdio.h>
int main()
{
    int jumlah;
    printf("Masukan jumlah siswa : ");
    scanf("%d", &jumlah);
    if (jumlah % 5 == 0)
    {
        printf("Buat kelompok dengan maksimal anggota 5 orang\n");
    }
    else if (jumlah % 4 == 0)
    {
        printf("Buat kelompok dengan maksimal anggota 4 orang\n");
    }
    else
    {
        printf("Buat kelompok dengan maksimal anggota 3 orang\n");
    }
    return 0;
}
