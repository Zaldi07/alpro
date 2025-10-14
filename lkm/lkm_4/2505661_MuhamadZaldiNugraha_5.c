#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Masukan angka:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            int hasil = i * j;
            printf("%d * %d = %d \n", i, j, hasil);
        }
    }

    return 0;
}
