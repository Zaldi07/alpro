#include <stdio.h>

int main()
{
    float berat, tinggi, bmi;

   
    printf("Masukkan berat badan (kg): ");
    scanf("%f", &berat);
    printf("Masukkan tinggi badan (meter): ");
    scanf("%f", &tinggi);

    bmi = berat / (tinggi * tinggi);

   
    printf("BMI Anda: %.2f\n", bmi);

    if (bmi < 18.5)
    {
        printf("Kategori: Kurus\n");
    }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        printf("Kategori: Normal\n");
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        printf("Kategori: Gemuk\n");
    }
    else
    {
        printf("Kategori: Obesitas\n");
    }

    return 0;
}
