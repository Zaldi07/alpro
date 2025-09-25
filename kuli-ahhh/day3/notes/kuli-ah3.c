#include <stdio.h>

int main()
{
    int hargaTiketAnak = 20000;
    int hargaTiketPelajar = 30000;
    int hargaTiketDewasa = 40000;
    int hargaTiketLansia = 25000;

    char kategory[];

    char
    printf("Masukan berat badan anda");
    scanf("%d", &beratBadan);
    printf("Masukan tinggi badan anda");
    scanf("%d", &tinggiBadan);

    ideal = beratBadan / (tinggiBadan * tinggiBadan);
    printf("%f", ideal);

    if (ideal < 50)
{
        printf("berat badan anda ideal");
    }

    return 0;
}