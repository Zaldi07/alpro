#include <stdio.h>

int main()
{
    int lama, biaya;

    printf("Masukkan lama parkir (jam): ");
    scanf("%d", &lama);

    if (lama <= 2)
    {
        biaya = 5000;
    }
    else
    {
        biaya = 10000;
    }

    printf("Biaya parkir: Rp%d\n", biaya);

    return 0;
}
