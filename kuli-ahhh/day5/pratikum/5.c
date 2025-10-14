#include <stdio.h>

int main()
{
    for (int baris = 1; baris <= 5; baris++)
    {

        for (int spasi = 5; spasi >= baris; spasi--)
        {
            printf(" ");
        }

        for (int kolom = 1; kolom <= (baris * 2 - 1); kolom++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}