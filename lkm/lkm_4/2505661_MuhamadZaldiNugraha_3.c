#include <stdio.h>

int main()
{
    int n, total = 1;

    printf("Input nilai n :");
    scanf("%d", &n);
    printf("Proses: %d! = ", n);
    for (int i = n; i > 0; i--)
    {
        printf("%d", i);
        if (i > 1)
        {

            printf(" X ");
        }

        total *= i;
    }
    printf("\nFaktorial dari %d adalah %d", n, total);

    return 0;
}
