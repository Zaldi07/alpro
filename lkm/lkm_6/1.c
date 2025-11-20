#include <stdio.h>
struct Karyawan
{
    char nama[50];
    int id_karyawan;
    int tunjangan;
    int gaji_pokok;
    int potongan;
    float gaji_bersih;
};

int hitungGajiBersih(struct Karyawan data)
{
    int gajiBersih = data.gaji_pokok + data.tunjangan - data.potongan;
    return gajiBersih;
}
void gajiTertinggi(struct Karyawan data[], int jumlahKaryawan)
{
    int maxGaji = data[0].gaji_bersih;
    int idx = 0;
    for (int i = 0; i < jumlahKaryawan; i++)
    {
        if (data[i].gaji_bersih > maxGaji)
        {
            idx = i;
            maxGaji = data[i].gaji_bersih;
        }
    }

    printf("Karyawan dengan gaji bersih tertinggi (%.2f)\n", data[idx].gaji_bersih);
    for (int j = 0; j < jumlahKaryawan; j++)
    {
        if (data[j].gaji_bersih == maxGaji)
        {
            printf("- %s (ID:%d)\n", data[j].nama, data[j].id_karyawan);
        }
    }
}

void handleInput(struct Karyawan data[], int jumlahKaryawan)
{
    for (int i = 0; i < jumlahKaryawan; i++)
    {
        printf("\nKaryawan ke-%d\n", i + 1);
        printf("Nama        \t:");
        scanf(" %[^\n]s", data[i].nama);
        printf("ID Karyawan \t:");
        scanf("%d", &data[i].id_karyawan);
        printf("Gaji Pokok   \t:");
        scanf("%d", &data[i].gaji_pokok);
        printf("Tunjangan   \t:");
        scanf("%d", &data[i].tunjangan);
        printf("Potongan    \t:");
        scanf("%d", &data[i].potongan);
        data[i].gaji_bersih = hitungGajiBersih(data[i]);
    }
}

void printDataKaryawan(struct Karyawan data[], int jumlahKaryawan)
{
    printf("\n===== DATA GAJI KARYAWAN =====\n");
    for (int i = 0; i < jumlahKaryawan; i++)
    {
        printf("Nama\t ID\t Gaji Bersih\n");
        printf("%s\t %d\t %.2f\t\n", data[i].nama, data[i].id_karyawan, data[i].gaji_bersih);
    }
}

int main()
{
    int jumlahKaryawan;
    printf("Masukan jumlah karyawan : ");
    scanf("%d", &jumlahKaryawan);
    struct Karyawan data[jumlahKaryawan];
    handleInput(data, jumlahKaryawan);
    printDataKaryawan(data, jumlahKaryawan);
    gajiTertinggi(data, jumlahKaryawan);

    return 0;
}