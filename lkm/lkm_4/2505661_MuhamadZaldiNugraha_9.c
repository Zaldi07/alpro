#include <stdio.h>

int main()
{
    int n, row, col;
    printf("Masukan N:");
    scanf("%d", &n);
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            // if (row % 2 == 1)
            // {
            //     if (col % 2 == 0)
            //     {
            //         printf(". ");
            //     }
            //     else
            //     {
            //         printf("# ");
            //     }
            // }
            // else
            // {
            //     if (col % 2 == 1)
            //     {
            //         printf(". ");
            //     }
            //     else
            //     {
            //         printf("# ");
            //     }
            // }
            if ((row + col) % 2 == 0)
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }

        printf("\n");
    }

    return 0;
}
