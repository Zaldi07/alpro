#include <stdio.h>
int main()
{
    int n;
    printf("Masukkan banyaknya angka:");
    scanf("%d", &n);
    float arr[n], result, temp;
    for (int i = 0; i < n; i++)
    {
        printf("Masukan angka ke-%d :", i + 1);
        scanf("%f", &arr[i]);
        temp += arr[i];
    }

    result = temp / n;
    printf("Nilai Rata-rata : %.2f", result);
    return 0;
}