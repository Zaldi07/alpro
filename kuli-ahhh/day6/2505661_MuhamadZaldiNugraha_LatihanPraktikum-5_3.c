#include <stdio.h>
int main()
{
    int matriks[2][2];
    int matriks2[2][2];
    printf("Matriks pertama : ");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("Matriks kedua : ");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matriks2[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int campuranArray = matriks[i][j] + matriks2[i][j];
            printf("%d ", campuranArray);
        }
        printf("\n");
    }

    return 0;
}