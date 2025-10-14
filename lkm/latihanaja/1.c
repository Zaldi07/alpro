#include <stdio.h>

int main()
{
    int tinggi;
    printf("Masukan tinggi");
    scanf("%d", &tinggi);
    for (int i = 0; i < tinggi; i++)
    {
        int spasi = 2 * (tinggi - 1 - i);

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        for (int t = 0; t < spasi; t++)
            printf(" ");

        for (int l = 0; l <= 2 * i; l++)
        {
            printf("#");
        }
        for (int t = 0; t < spasi; t++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}