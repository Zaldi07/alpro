#include <stdio.h>

int main()
{
    int angka;

    printf("Masukan angka :");
    scanf("%d", &angka);
    if (angka > 0)
    {
        printf("%d adalah bilangan positif", angka);
    }
    else if (angka < 0)
    {
        printf("%d Angka adalah bilangan negatif", angka);
    }
    else
    {
        printf("%d adalah bilangan 0", angka);
    }

    return 0;
}
