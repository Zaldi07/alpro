#include <stdio.h>
int main()
{

    int totalGenap = 0, totalGanjil = 0, totalBilangan;
    printf("Masukan jumlah bilangan :");
    scanf("%d", &totalBilangan);
    for (int i = 0; i < totalBilangan; i++)
    {
        int temp = 0;
        printf("Masukan bilangan ke-%d :", i + 1);
        scanf("%d", &temp);
        if (temp % 2 == 0)
        {
            totalGenap += temp;
        }
        else
        {
            totalGanjil += temp;
        }
    }
    printf("Jumlah total genap  : %d", totalGenap);
    printf("Jumlah total ganjil : %d", totalGanjil);

    return 0;
}