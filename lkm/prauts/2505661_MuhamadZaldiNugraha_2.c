#include <stdio.h>
int main()
{
    int gajiHarian = 87500, hariKerja = 26, total;
    float bonus = 2.5 / 100;
    total = (gajiHarian * hariKerja) + ((gajiHarian * hariKerja) * bonus);
    printf("Total gaji bulanan: %d ", total);
}