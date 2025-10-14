#include <stdio.h>
int main()
{
    int bilanganBulat[5];
    int total = 0;

    printf("input :");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &bilanganBulat[i]);
        total += bilanganBulat[i];
    }

    printf("total : %d", total);
    return 0;
}
