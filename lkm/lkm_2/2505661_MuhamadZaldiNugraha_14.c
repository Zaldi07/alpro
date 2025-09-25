#include <stdio.h>

int main()
{
    int kode;

    printf("Kode Presensi\n");
    printf("(1) Hadir\n");
    printf("(2) Sakit\n");
    printf("(3) Tidak ada keterangan\n");
    printf("Masukkan kode presensi: ");
    scanf("%d", &kode);

    switch (kode)
    {
    case 1:
        printf("Hadir\n");
        break;
    case 2:
        printf("Sakit\n");
        break;
    case 3:
        printf("Tidak ada keterangan\n");
        break;
    default:
        printf("Kode tidak valid\n");
    }

    return 0;
}
