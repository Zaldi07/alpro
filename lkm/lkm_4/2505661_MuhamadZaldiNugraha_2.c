#include <stdio.h>

int main()
{
    int n, i;

    printf("Input nilai n :");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        if (i % 2 == 1)
        {

            printf("%d ", i);
        }
    }

    return 0;
}
