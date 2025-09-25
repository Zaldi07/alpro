#include <stdio.h>
int main()
{
    int hadir;
    printf("Total persentase kehadiran: ");
    scanf("%d", &hadir);
    if (hadir > 80)
    {
        printf("Lulus.\n");
    }
    else if (hadir > 60 && hadir <= 80)
    {
        printf("Perlu perbaikan nilai.\n");
    }
    else
    {
        printf("Tidak lulus.\n");
    }
    return 0;
}
