#include <stdio.h>

struct Mahasiswa
{
    char nama[30];
    int nim;
    float nilai1;
    float nilai2;
    float nilai3;
    float rataRata;
};

int rataRataTertinggi(struct Mahasiswa arr[], int n)
{
    int idxMax = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].rataRata > arr[idxMax].rataRata)
        {
            idxMax = i;
        }
    }

    return idxMax;
}

int main()
{
    int jmlMhs, nilaiMax = 0;

    printf("Masukan jumlah mahasiswanya: ");
    scanf("%d", &jmlMhs);
    struct Mahasiswa data[jmlMhs];

    for (int i = 0; i < jmlMhs; i++)
    {
        printf("Mahasiswa ke %d\n", i + 1);
        printf("Nama    :");
        // scanf(" %s", data[i].nama);
        scanf(" %[^\n]s", data[i].nama);
        printf("NIM     :");
        scanf("%d", &data[i].nim);
        printf("Nilai1  :");
        scanf("%f", &data[i].nilai1);
        printf("Nilai2  :");
        scanf("%f", &data[i].nilai2);
        printf("Nilai3  :");
        scanf("%f", &data[i].nilai3);
        printf("\n");

        float tempRataRata = (data[i].nilai1 + data[i].nilai2 + data[i].nilai3) / 3;
        data[i].rataRata = tempRataRata;
    }
    printf("=== Data NILAI MAHASISWA ===\n");
    printf("Nama\t NIM\t Rata-rata\n");
    for (int j = 0; j < jmlMhs; j++)
    {
        printf("%s\t %d\t %.2f\n", data[j].nama, data[j].nim, data[j].rataRata);
    }

    int max = rataRataTertinggi(data, jmlMhs);
    printf("Mahasiswa dengan rata-rata tertinggi (%.2f) - %s (NIM: %d)", data[max].rataRata, data[max].nama, data[max].nim);

    return 0;
}