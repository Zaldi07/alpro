#include <stdio.h>

int main()
{
    int userChoice;
    do
    {
        printf("Apakah saat ini masih hujan (1: Ya, 2: Tidak)? ");
        scanf("%d", &userChoice);
    } while (userChoice != 2);

    printf("Hujan raat!\n");
    return 0;
}