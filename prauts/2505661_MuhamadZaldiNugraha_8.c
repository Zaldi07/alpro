#include <stdio.h>
int main()
{
    int id, prefix, suffix;
    printf("Masukan ID (4 digit) : ");
    scanf("%d", &id);
    if (id < 1000 || id > 9999)
    {
        printf("ID tidak valid!\n");
        return 0;
    }

    prefix = id / 100;
    suffix = id % 100;

    if ((prefix % 2 == 0 && suffix % 3 == 0) || ((prefix + suffix) % 7 == 0) || (prefix == suffix))
    {
        printf("Akses DIIZINKAN\n");
    }
    else
    {
        printf("AKses DITOLAK\n");
    }

    return 0;
}