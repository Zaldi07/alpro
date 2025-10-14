#include <stdio.h>

int main()
{
    for (int kolom = 1; kolom <= 5; kolom++)
    {

        for (int spasi = 5; spasi >= kolom; spasi--)
        {
            printf(" ");
        }

        for (int baris = 1; baris <= (kolom * 2 - 1); baris++)
        {
            printf("*");
        }

        printf("\n");
    }

    for (int kolom = 5; kolom >= 1; kolom--)
    {

        for (int spasi = 5; spasi >= kolom; spasi--)
        {
            printf(" ");
        }

        for (int baris = 1; baris <= (kolom * 2 - 1); baris++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}