#include <stdio.h>
int main()
{
    int lamaParkir, biayaParkir;
    printf("Masukan lama parkir (jam): ");
    scanf("%d", &lamaParkir);
    if (lamaParkir <= 5)
    {
        biayaParkir = 5000 + (lamaParkir - 1) * 3000;
        printf("Biaya parkir adalah Rp %d\n", biayaParkir);
    }
    else if (lamaParkir > 5)
    {
        biayaParkir = 25000;
        printf("Biaya parkir adalah Rp %d\n", biayaParkir);
    }
    else
    {
        biayaParkir = 5000;
        printf("Biaya parkir adalah Rp %d\n", biayaParkir);
    }
    return 0;
}
