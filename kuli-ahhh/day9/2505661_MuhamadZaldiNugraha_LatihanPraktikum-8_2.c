#include <stdio.h>
#include <stdlib.h>

int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}
int main()
{

    int n, target;
    printf("Masukkan banyaknya data: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Masukkan Data yang Ingin Dicari: ");
    scanf("%d", &target);

    int hasil = sequentialSearch(arr, n, target);

    if (hasil != -1)
    {
        printf("%d berada di indeks ke-%d", target, hasil);
    }
    else
    {
        printf("%d tidak ditemukan", target);
    }

    return 0;
}