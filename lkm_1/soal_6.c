#include <stdio.h>

int main()
{
    int totalSiswa, siswaLulus;
    float persentase;

    // Input total siswa
    printf("Jumlah siswa: ");
    scanf("%d", &totalSiswa);

    // Input jumlah siswa lulus
    printf("Jumlah siswa lulus: ");
    scanf("%d", &siswaLulus);

    // Hitung persentase kelulusan
    persentase = (float)siswaLulus / totalSiswa * 100;

    // Output hasil dengan 2 angka di belakang koma
    printf("\nPersentase kelulusan: %.2f%%\n", persentase);

    return 0;
}
