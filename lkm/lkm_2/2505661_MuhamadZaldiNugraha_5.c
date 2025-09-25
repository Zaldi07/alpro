#include <stdio.h>
int main()
{
    int dana, pengeluaran;
    printf("Dana Yang Tersedia : ");
    scanf("%d", &dana);
    printf("Jumlah pengeluaran : ");
    scanf("%d", &pengeluaran);
    if (pengeluaran <= dana)
    {
        printf("Uang Cukup\n");
    }
    else
    {
        printf("Uang Kurang\n");
    }
    return 0;
}
