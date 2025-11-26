#include <stdio.h>
int main()
{
    int harga, diskon, total;
    harga = 250000;

    if (harga > 200000)
    {
        diskon = harga * 0.25;
        total = harga - diskon;
    }

    printf("Total harga setelah diskon: %d", total);

    return 0;
}