#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {

                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// step
// i = 0
// nested
// j = 0
// arr[j+1] < arr[j] -> ( 50 < 20)
// j = 1
// arr[j+1] < arr[j] -> (40 < 50) -> swap (20,40,50,30)
// j = 2
// arr[j+1] < arr[j] -> (30 < 50) -> swap (20,40,30,50)
// step
// i = 1
// nested
// dst

int main()
{
    int arr[] = {20, 50, 40, 30};
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}