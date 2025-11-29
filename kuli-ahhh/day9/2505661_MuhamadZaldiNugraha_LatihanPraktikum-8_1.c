#include <stdio.h>
int binarySearch(int arr[], int target, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13}, target = 0;

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMasukkan angka yang ingin dicari: ");
    scanf("%d", &target);
    int result = binarySearch(arr, target, 7);

    if (result != -1)
    {
        printf("Elemen %d ditemukan pada indeks %d\n", target, result);
    }
    else
    {
        printf("Elemen %d tidak ditemukan\n", target);
    }
    return 0;
}