#include <stdio.h>
#include <string.h>

int main()
{
    char kalimat[100] = "Saya aku bahagia";
    char *kata;
    kata = strtok(kalimat, " ");
    while (kata != NULL)
    {
        char hurufAwal = kata[0];
        int panjang = strlen(kata);
        printf("%c%d", hurufAwal, panjang);
        kata = strtok(NULL, " ");
    }

    return 0;
}