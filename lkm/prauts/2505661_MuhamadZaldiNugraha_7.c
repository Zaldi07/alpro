#include <stdio.h>

int main()
{
    int kode;
    printf("Masukan kode sinyal (1-3): ");
    scanf("%d", &kode);
    if (kode == 1)
    {
        printf("Warna: Merah\nStatus: Berhenti");
    }
    else if (kode == 2)
    {
        printf("Warna: Kuning\nStatus: Hati-hati");
    }
    else
    {
        printf("Warna: Hijau\nStatus: Jalan");
    }

    return 0;
}