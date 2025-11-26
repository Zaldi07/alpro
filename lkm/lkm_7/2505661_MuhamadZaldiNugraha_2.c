#include <stdio.h>
#include <string.h>
struct Book
{
    char title[50];
};
void swap(struct Book *a, struct Book *b)
{
    struct Book temp = *a;
    *a = *b;
    *b = temp;
}

void sort_books(struct Book book[], int jumlahBuku)
{
    for (int i = 0; i < jumlahBuku - 1; i++)
    {
        for (int j = 0; j < jumlahBuku - 1; j++)
        {
            if (strcmp(book[j].title, book[j + 1].title) > 0)
            {
                // printf("%d", strcmp(book[j].title, book[j + 1].title));
                swap(&book[j], &book[j + 1]);
            }
        }
    }
}

void handleInput(struct Book books[], int jumlahBuku)
{
    printf("Masukkan judul buku:\n");
    for (int i = 0; i < jumlahBuku; i++)
    {
        printf("Judul ke-%d: ", i + 1);
        scanf(" %[^\n]s", books[i].title);
    }
}

void print_books(struct Book book[], int jumlahBuku)
{
    printf("\nDaftar judul buku setelah diurutkan:\n");
    for (int i = 0; i < jumlahBuku; i++)
    {
        printf("%d. %s\n", i + 1, book[i]);
    }
}
int main()
{

    int jumlahBuku;
    printf("Masukakan jumlah judul buku yang akan diurutkan (maks 100): ");
    scanf("%d", &jumlahBuku);
    struct Book Books[jumlahBuku];
    handleInput(Books, jumlahBuku);
    sort_books(Books, jumlahBuku);
    print_books(Books, jumlahBuku);
}