#include <stdio.h>

int main()
{
    int pilihan;
    float suhuC, suhuF;

    printf("=== Program Ramalan Cuaca Mimin ===\n");
    printf("1. Cerah\n");
    printf("2. Hujan\n");
    printf("3. Berawan\n");
    printf("4. Badai\n");
    printf("5. Kabut\n");
    printf("Pilih kondisi cuaca (1-5): ");
    scanf("%d", &pilihan);

    
    if (pilihan >= 1 && pilihan <= 5)
    {
        printf("Masukkan suhu dalam Celsius: ");
        scanf("%f", &suhuC);

   
        suhuF = (suhuC * 9 / 5) + 32;

        printf("\n=== Hasil Ramalan Cuaca ===\n");
        switch (pilihan)
        {
        case 1:
            printf("Cuaca: Cerah\n");
            break;
        case 2:
            printf("Cuaca: Hujan\n");
            break;
        case 3:
            printf("Cuaca: Berawan\n");
            break;
        case 4:
            printf("Cuaca: Badai\n");
            break;
        case 5:
            printf("Cuaca: Kabut\n");
            break;
        }
        printf("Suhu: %.2f °C\n", suhuC);
        printf("Suhu: %.2f °F\n", suhuF);
    }
    else
    {
        printf("Pilihan cuaca tidak valid.\n");
    }

    return 0;
}
