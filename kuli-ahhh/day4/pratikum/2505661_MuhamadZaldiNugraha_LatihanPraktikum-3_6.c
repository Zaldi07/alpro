#include <stdio.h>

int main()
{
    int bulanKerja;
    printf("Masukkan lama bulan kerja: ");
    scanf("%d", &bulanKerja);
    if (bulanKerja % 7 == 0)
    {
        printf("bulan %d mendapat bonus\n", bulanKerja);
    }
    else
    {
        printf("bulan %d bukan bonus\n", bulanKerja);
        printf("%d", bulanKerja % 7);
        printf("Bonus berikut dalam %d bulan\n", 7 - (bulanKerja % 7));
    }
    return 0;
}