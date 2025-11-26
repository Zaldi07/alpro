#include <stdio.h>

struct Painting
{
    char id[50];
    char name[50];
    int est_year;
};

void swap(struct Painting *a, struct Painting *b)
{
    struct Painting temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(struct Painting arr[], int jumlahPainting)
{
    for (int i = 0; i < jumlahPainting - 1; i++)
    {
        int indexMax = i;
        for (int j = i; j < jumlahPainting; j++)
        {
            if (arr[j].est_year > arr[indexMax].est_year)
            {
                indexMax = j;
            }
        }
        swap(&arr[i], &arr[indexMax]);
    }
}

void inputHandle(struct Painting arr[], int maxPainting, int *jumlahPainting)
{
    int indexPainting = 0;
    printf("=== Input data lukisan ===\n");

    while (indexPainting < maxPainting)
    {

        printf("Masukan id lukisan      :");
        scanf(" %[^\n]s", &arr[indexPainting].id);
        printf("Masukan nama lukisan    :");
        scanf(" %[^\n]s", &arr[indexPainting].name);
        printf("Masukan tahun dibuat    :");
        scanf("%d", &arr[indexPainting].est_year);
        indexPainting++;

        int lanjut;
        printf("\nmau tambah lukisan lagi gak ? (1 = ya, 0 = tidak): ");
        scanf("%d", &lanjut);

        if (lanjut == 0)
        {

            break;
        }
    }
    *jumlahPainting = indexPainting;
}

void printPainting(struct Painting arr[], int jumlahpainting, char judul[])
{
    printf("===============================================================");
    printf("\n              %s                                              \n", judul);
    printf("===============================================================\n");
    printf("| %-20s | %-20s | %-10s |\n", "ID Lukisan", "Nama Lukisan", "Tahun Dibuat");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < jumlahpainting; i++)
    {
        printf("| %-20s | %-20s | %-10d     |\n", arr[i].id, arr[i].name, arr[i].est_year);
    }
    printf("===============================================================\n");
}

int main()
{
    int maxPainting = 10;
    struct Painting paintings[maxPainting];
    int jumlahPainting = 0;
    inputHandle(paintings, maxPainting, &jumlahPainting);
    printPainting(paintings, jumlahPainting, "Daftar Lukisan Awal");
    printf("\n\n");
    selectionSort(paintings, jumlahPainting);
    printPainting(paintings, jumlahPainting, "Daftar Lukisan Terurut (Terbaru ke terlama)");

    return 0;
}