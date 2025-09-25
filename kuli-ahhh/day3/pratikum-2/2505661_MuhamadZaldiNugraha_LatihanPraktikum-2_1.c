#include <stdio.h>

int main()
{
    int pilihan;
    printf("silahkan pilih menu di bawah ini guys\n");
    printf("1. matcha \n");
    printf("2. bundle (matcha + thai tea)\n");
    printf("Masukan pilihan anda :");
    scanf("%d", &pilihan);
    if (pilihan == 1)
    {
        printf("Maaf anda tidak mendapatkan diskon guys\n");
    }
    else
    {

        printf("Selamat anda mendapatkan diskon\n");
    }

    return 0;
}
