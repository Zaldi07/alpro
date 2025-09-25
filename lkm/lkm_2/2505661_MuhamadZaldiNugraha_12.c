#include <stdio.h>

int main()
{
    int berat, sistole, diastole;

    printf("Masukan Berat Badan Siswa : ");
    scanf("%d", &berat);

    if (berat >= 50)
    {
        printf("Masukkan tekanan darah siswa (format sistole/diastole):\n");
        printf("Sistole (angka atas): ");
        scanf("%d", &sistole);
        printf("Diastole (angka bawah): ");
        scanf("%d", &diastole);

        if (sistole < 90 || diastole < 60)
        {
            printf("Tensi terlalu rendah! Siswa harus dirujuk ke rumah sakit atau puskesmas.\n");
        }
        else if (sistole > 140 || diastole > 90)
        {
            printf("Tensi terlalu tinggi! Siswa harus dirujuk ke rumah sakit atau puskesmas.\n");
        }
        else
        {
            printf("Siswa Cukup sehat untuk mengikuti pemeriksaan darah.\n");
        }
    }
    else
    {
        printf("Siswa tidak bisa mengikuti pemeriksaan darah karena berat badan kurang dari 50kg.\n");
    }

    return 0;
}
