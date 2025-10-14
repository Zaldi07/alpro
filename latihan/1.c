#include <stdio.h>
int main()
{
    int row = 5;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2 * i; j++)
        {
            printf("#");
        }

        for (int j = 0; j < (row * 2) - 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}