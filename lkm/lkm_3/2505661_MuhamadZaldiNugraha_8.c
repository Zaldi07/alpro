#include <stdio.h>

int main()
{
    int hari;

    printf("Program Jadwal Kuliah\n");
    printf("Masukkan nomor hari (1-7): ");
    scanf("%d", &hari);

    switch (hari)
    {
    case 1:
        printf("Kuliah Kalkulus\n");
        break;
    case 2:
        printf("Kuliah Algoritma\n");
        break;
    case 3:
        printf("Kuliah Pendidikan Agama Islam\n");
        break;
    case 4:
        printf("Kuliah Arsitektur dan Organisasi Komputer\n");
        break;
    case 5:
        printf("Kuliah Pendidikan Bahasa Indonesia\n");
        break;
    case 6:
        printf("Sabtu = Libur\n");
        break;
    case 7:
        printf("Minggu = Libur\n");
        break;
    default:
        printf("Input tidak valid! Masukkan angka 1-7.\n");
    }

    return 0;
}
