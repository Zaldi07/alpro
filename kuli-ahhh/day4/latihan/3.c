#include <stdio.h>

int main()
{
    int teori, pratikum, kehadiran, rata_rata;

    printf("Masukkan teori: ");
    scanf("%d", &teori);
    printf("Masukkan pratikum: ");
    scanf("%d", &pratikum);
    printf("Masukkan kehadiran: ");
    scanf("%d", &kehadiran);

    rata_rata = (teori + pratikum) / 2;

    if (teori <= 100 && pratikum <= 100 && kehadiran <= 16)

    {
        printf("Rata-rata nilai (teori & pratikum): %n", rata_rata);

        if (teori >= 60 && pratikum >= 70 && kehadiran >= 12)
        {
            printf("status kelulusan : lulus");
            if (rata_rata >= 90)
            {
                printf("Predikat  Sangat baik\n");
            }
            else if (rata_rata >= 80 && rata_rata < 90)
            {
                printf("Predikat  Baik\n");
            }
            else if (rata_rata >= 70 && rata_rata < 80)
            {
                printf("Predikat  Cukup\n");
            }
            else
            {
                printf("Predikat  Kurang\n");
            }
        }
        else
        {

            printf("status kelulusan : tidak lulus\n");
            if (pratikum < 70)
            {
                printf("Tidak lulus karena nilai pratikum kurang dari 70\n");
            }
            if (teori < 60)
            {

                printf("Tidak lulus karena nilai teori kurang dari 60\n");
            }
            if (kehadiran < 12)
            {

                printf("Tidak lulus karena kehadiran kurang dari 12\n");
            }
        }
    }
    else
    {
        if (teori > 100)
        {
            printf("input nilai teori anda melebihi nilai maksimum (0-100)\n");
        }
        if (pratikum > 100)
        {
            printf("input nilai pratikum anda melebihi nilai maksimum (0-100)\n");
        }
        if (kehadiran > 16)
        {
            printf("input absensi anda melebihi jumlah maksimum (0-16)\n");
        }
    }

    return 0;
}