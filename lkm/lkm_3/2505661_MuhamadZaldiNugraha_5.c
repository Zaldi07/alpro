#include <stdio.h>

int main()
{
    float total_belanja;
    float diskon = 0, total_bayar;

    printf("Masukkan total belanja: ");
    scanf("%f", &total_belanja);

    // Aturan diskon
    if (total_belanja >= 500000)
    {
        diskon = total_belanja * 0.20;
    }
    else if (total_belanja >= 250000)
    {
        diskon = total_belanja * 0.10;
    }
    else if (total_belanja >= 100000)
    {
        diskon = total_belanja * 0.05;
    }
    else
    {
        diskon = 0;
    }

    // Hitung total bayar
    total_bayar = total_belanja - diskon;

    // Output
    printf("Total belanja : Rp%.2f\n", total_belanja);
    printf("Diskon        : Rp%.2f\n", diskon);
    printf("Total bayar   : Rp%.2f\n", total_bayar);

    return 0;
}
