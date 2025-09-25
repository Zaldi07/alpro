#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Program konversi CM ke KM
    float ukuran_CM, hasil;
    // Proses Input (pakai scanf)
    printf("Masukan Ukuran dalam cm :");
    scanf("%f", &ukuran_CM);
    hasil = ukuran_CM / 100000;


    printf("Ukuran KM =  %.2f ", hasil);

    return 0;
}