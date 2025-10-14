#include <stdio.h>

int main()
{
    for (int baris = 1; baris <= 5; baris++)
    {
        for (int kolom = 1; kolom <= baris; kolom++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
