#include <stdio.h>
int main()
{
    int n;
    printf("Masukkan banyaknya angka:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Masukan angka ke-%d :", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] > max)
        {
            max = arr[j];
        }
    }
    printf("Nilai maksimal pada array : %d", max);
    return 0;
}