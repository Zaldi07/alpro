#include <stdio.h>

int main()
{
    int nilai;

    printf("Masukkan nilai akhir: ");
    scanf("%d", &nilai);

    if (nilai >= 70)
    {
        printf("Lulus\n");
        if (nilai >= 90)
        {
            printf("Lulus dengan predikat A\n");
        }
        else
        {
            printf("Lulus dengan predikat B\n");
        }
    }
    else
    {
        printf("Tidak lulus\n");
    }

    return 0;
}
