#include <stdio.h>
#include <string.h>

int SequentialSearch(char arr[5][50], int n, char target[10])
{

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], target) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    char names[5][50] = {"Azmi", "Dhafin", "Fathia", "Nisa", "Tuska"};
    int lengthOfArray = sizeof(names) / sizeof(names[0]);

    for (int i = 0; i < 5; i++)
    {
        char name[50];
        printf("Masukan nama yang mau dicari: ");
        scanf(" %s", &name);

        int hasil = SequentialSearch(names, lengthOfArray, name);

        if (hasil < 0)
        {
            printf("Tidak ditemukan\n", name);
        }
        else
        {
            printf("Ditemukan di indeks ke-%d\n", hasil);
        }
    }

    return 0;
}
