#include <stdio.h>
#include <string.h>

int main()
{
    int umur, harga;
    char hari[10];

    printf("Masukkan umur: ");
    scanf("%d", &umur);
    printf("Masukkan hari (Senin-Sabtu/Minggu): ");
    scanf("%s", hari);

    if (umur < 12)
    {
        harga = 30000;
    }
    else if (umur <= 18)
    {
        harga = 40000;
    }
    else
    {

        if (strcmp(hari, "Sabtu") == 0 || strcmp(hari, "Minggu") == 0 || strcmp(hari, "sabtu") == 0 || strcmp(hari, "minggu") == 0)
        {
            harga = 60000;
        }
        else
        {
            harga = 50000;
        }
    }

    printf("Harga tiket: Rp%d\n", harga);
    return 0;
}