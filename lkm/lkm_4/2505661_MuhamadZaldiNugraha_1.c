#include <stdio.h>

int main()
{
    int m, n;
    printf("Input nilai m :");
    scanf("%d", &m);
    printf("Input nilai n :");
    scanf("%d", &n);
    for (m = m; m < n; m++)
    {
        printf("%d ", m);
    }

    return 0;
}
