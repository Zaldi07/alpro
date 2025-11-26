#include <stdio.h>

struct Paket
{
    char id[50];
    float weight;
    char destination[50];
};

void swap(struct Paket *a, struct Paket *b)
{
    struct Paket temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(struct Paket arr[], int jumlahPaket)
{
    for (int i = 0; i < jumlahPaket - 1; i++)
    {
        int indexMin = i;
        for (int j = i; j < jumlahPaket; j++)
        {
            if (arr[j].weight < arr[indexMin].weight)
            {
                indexMin = j;
            }
        }
        swap(&arr[i], &arr[indexMin]);
    }
}

void inputHandle(struct Paket arr[], int maxPaket, int *jumlahPaket)
{
    int indexPaket = 0;
    printf("=== Input data Paket ===\n");

    while (indexPaket < maxPaket)
    {

        printf("Masukan id Paket        :");
        scanf(" %[^\n]s", &arr[indexPaket].id);
        printf("Masukan Berat paket     :");
        scanf("%f", &arr[indexPaket].weight);
        printf("Masukan tujuan paket    :");
        scanf(" %[^\n]s", &arr[indexPaket].destination);
        indexPaket++;

        int lanjut;
        printf("\nmau tambah paket lagi gak ? (1 = ya, 0 = tidak): ");
        scanf("%d", &lanjut);

        if (lanjut == 0)
        {

            break;
        }
    }
    *jumlahPaket = indexPaket;
}

void printPaket(struct Paket arr[], int jumlahPaket, char judul[])
{
    printf("===============================================================");
    printf("\n              %s                                              \n", judul);
    printf("===============================================================\n");
    printf("| %-20s | %-15s | %-20s |\n", "ID Paket", "Berat (kg)", "Tujuan");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < jumlahPaket; i++)
    {
        printf("| %-20s | %.1f\t\t | %-20s |\n", arr[i].id, arr[i].weight, arr[i].destination);
    }
    printf("===============================================================\n");
}

int main()
{
    int maxPaket = 20;
    struct Paket Pakets[maxPaket];
    int jumlahPaket = 0;
    inputHandle(Pakets, maxPaket, &jumlahPaket);
    printPaket(Pakets, jumlahPaket, "Daftar Paket Awal");
    printf("\n\n");
    selectionSort(Pakets, jumlahPaket);
    printPaket(Pakets, jumlahPaket, "Daftar Paket Terurut (Teringan ke terberat)");

    return 0;
}