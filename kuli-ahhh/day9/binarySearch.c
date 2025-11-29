#include <stdio.h>
int main()
{
    int binarySearch(int arr[], int n, int target)
    {
        int low = 0;
        int high = n - 1;
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

            printf("low: %d , mid:%d , high: %d\n", low, mid, high);
        }

        return -1;
    }

    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n = 6, target;
    // scanf("%d", &n);
    scanf("%d", &target);
    int hasil = binarySearch(arr, n, target);
    printf("%d", hasil);
    return 0;
}