#include <stdio.h>

int main()
{
    int i = 0;
    int jumlahHari = 5;
    int sesi;
    while (i < jumlahHari)
    {

        sesi = 1;
        printf("hari %d:\n", i + 1);
        while (sesi <= 4)
        {
            printf(" sesi %d\n", sesi);
            sesi++;
        }
        printf("\n");
        i++;
    }
}