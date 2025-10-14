#include <stdio.h>

int main()
{
    int tinggi;
    printf("Masukan tinggi mahkota:");
    scanf("%d", &tinggi);

    // outer loop -> 0 , 1 , 2 , 3
    for (int i = 0; i < tinggi; i++)
    {
        // value of spasi ->
        // misal tinggi 4
        // 1. 2 * (tinggi - 1 - 0) = 6;
        // 2. 2 * (tinggi - 1 - 1) = 4;
        // 3. 2 * (tinggi - 1 - 2) = 2;
        // 4. 2 * (tinggi - 1 - 3) = 0;

        int spasi = 2 * (tinggi - 1 - i);

        

        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        for (int t = 0; t < spasi; t++)
            printf(" ");

        for (int l = 0; l <= 2 * i; l++)
        {
            printf("*");
        }
        for (int t = 0; t < spasi; t++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}