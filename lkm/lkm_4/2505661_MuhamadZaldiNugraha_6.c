#include <stdio.h>

int main()
{
    // int n, row, col;
    // printf("Masukan N:");
    // scanf("%d", &n);
    // for (row = 1; row <= n; row++)
    // {
    //     for (col = 1; col <= row; col++)
    //     {
    //         printf("%d ", col);
    //     }
    //     printf("\n");
    // }
    // int i = 0;
    // int j;
    // while (i < 5)
    // {

    //     j = 0;

    //     while (j <= i)
    //     {
    //         printf("%d ", j + 1);
    //         j++;
    //     }
    //     i++;
    //     printf("\n");
    // }

    // int i = 0;
    // int j;
    // int space;
    // while (i < 5)
    // {

    //     j = 0;

    //     space = 5 - i;
    //     while (space > 1)
    //     {
    //         printf(" ");
    //         space--;
    //     }

    //     while (j <= i)
    //     {
    //         printf("%d ", j + 1);
    //         j++;
    //     }
    //     i++;
    //     printf("\n");
    // }

    // int i = 0;
    // int j;
    // int space;
    // while (i < 5)
    // {

    //     j = 0;

    //     space = 5 - i;
    //     while (space > 1)
    //     {
    //         printf(" ");
    //         space--;
    //     }

    //     while (j <= i)
    //     {
    //         printf("%d ", j + 1);
    //         j++;
    //     }
    //     i++;
    //     printf("\n");
    // }


    int i = 0;
    int j;
    int space;
    while (i > 5)
    {

        j = 0;

        space = 5 - i;
        while (space > 1)
        {
            printf(" ");
            space--;
        }

        while (j <= i)
        {
            printf("%d ", j + 1);
            j++;
        }
        i++;
        printf("\n");
    }


    return 0;
}
