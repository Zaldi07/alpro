#include <stdio.h>

int main()
{
    char upi, kemakom;

    printf("Apakah Peserta Mahasiswa UPI (Y/T) : ");
    scanf(" %c", &upi);

    if (upi == 'Y' || upi == 'y')
    {
        printf("Apakah Peserta Mahasiswa Kemakom (Y/T) : ");
        scanf(" %c", &kemakom);

        if (kemakom == 'Y' || kemakom == 'y')
        {
            printf("Peserta mendapatkan diskon 15%%\n");
        }
        else
        {
            printf("Peserta mendapatkan diskon 10%%\n");
        }
    }
    else
    {
        printf("Peserta mendapatkan harga normal\n");
    }

    return 0;
}
