#include <stdio.h>
int main()
{
    int n;
    printf("Masukan banyaknya angka: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Masukan angka ke-%d :", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Output: \n");
    for (int j = 0; j < n; j++)
    {
        printf("Angka index ke-%d: %d\n", j, arr[j]);
    }
