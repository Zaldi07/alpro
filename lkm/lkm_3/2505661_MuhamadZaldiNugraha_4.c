#include <stdio.h>

int main()
{
    int angka;

    printf("Masukan bilangan : ");
    scanf("%d", &angka);
    if (angka > 0 && angka % 2 == 0)
    {
        printf("Bilangan %d adalah genap positif", angka);
    }
    else if (angka > 0 && angka % 2 != 0)
    {
        printf("Bilangan %d adalah ganjil positif", angka);
    }
    else if (angka < 0 && angka % 2 == 0)
    {
        printf("Bilangan %d adalah genap negatif", angka);
    }
    else if (angka < 0 && angka % 2 != 0)
    {
        printf("Bilangan %d adalah ganjil negatif", angka);
    }
    else
    {
        printf("Bilangan %d adalah genap 0", angka);
    }

    return 0;
}
