#include <stdio.h>
int main()
{
    int kolom, baris;
    printf("Masukan banyak angka untuk baris ");
    scanf("%d", &baris);
    printf("Masukan banyak angka untuk kolom ");
    scanf("%d", &kolom);

    int arr[baris][kolom];

    printf("Masukan Angka: \n");
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int k = 0; k < baris; k++)
    {
        int jumlahBaris = 0;
        for (int l = 0; l < kolom; l++)
        {
            jumlahBaris += arr[k][l];
        }
        printf("Jumlah baris ke-%d: %d\n", k + 1, jumlahBaris);
    }

    return 0;
}