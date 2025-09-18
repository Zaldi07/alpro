#include <stdio.h>

int main()
{
    int beratBadan, tinggiBadan, ideal;
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