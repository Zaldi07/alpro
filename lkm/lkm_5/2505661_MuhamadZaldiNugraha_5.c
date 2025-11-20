#include <stdio.h>

int main()
{
    int jumlahHalte;
    int totalPenumpang;
    printf("=== Program Total Penumpang Bus ===\n");
    printf("Masukan Jumlah Halte :");
    scanf("%d", &jumlahHalte);
    int penumpang[jumlahHalte];
    for (int halte = 0; halte < jumlahHalte; halte++)
    {
        printf("Masukan jumlah penumpang di halte ke-%d: ", halte + 1);
        scanf("%d", &penumpang[halte]);
        totalPenumpang += penumpang[halte];
    }

    printf("Total penumpang selama perjalanan : %d", totalPenumpang);

    return 0;
}