#include <stdio.h>

int main()
{
    int n, row, col;
    printf("Masukan N:");
    scanf("%d", &n);
    for (row = n; row > 0; row--)
    {
        for (int spasi = 0; spasi < n - row; spasi++)
        {
            printf(" ");
        }

        for (col = 0; col < (row * 2) - 1; col++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
