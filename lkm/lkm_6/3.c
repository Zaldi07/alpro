#include <stdio.h>

struct buku
{
    char judul[24];
    char penulis[24];
    char penerbit[24];
    int isbn;
};

void showDataBook(struct buku arr[], int lengthOfArray)
{
    printf("\nDaftar Buku di Perpustakaan:\n");
    printf("NO\t Judul\t\t Penulis\t Penerbit\t ISBN\n");
    for (int i = 0; i < lengthOfArray; i++)
    {
        printf("%d\t %s\t\t %s\t\t %s\t %d\n", i + 1, arr[i].judul, arr[i].penulis, arr[i].penerbit, arr[i].isbn);
    }
}

void handleInput(struct buku data[], int jmlBuku)
{
    for (int i = 0; i < jmlBuku; i++)
    {
        printf("Buku ke-%d\n", i + 1);
        printf("Judul: ");
        scanf(" %[^\n]s", data[i].judul);
        printf("Penulis: ");
        scanf(" %[^\n]s", data[i].penulis);
        printf("Penerbit: ");
        scanf(" %[^\n]s", data[i].penerbit);
        printf("ISBN: ");
        scanf("%d", &data[i].isbn);
    }
}

int main()
{
    int jmlBuku;
    printf("Masukan jumlah buku:");
    scanf("%d", &jmlBuku);
    struct buku data[jmlBuku];
    handleInput(data, jmlBuku);
    showDataBook(data, jmlBuku);

    return 0;
}