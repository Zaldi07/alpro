#include <stdio.h>
int main()
{
    int penumpang;
    printf("Masukan jumlah penumpang: ");
    scanf("%d", &penumpang);
    if (penumpang > 6)
    {
        printf("Anda melebihi batas penumpang.\n");
    }
    return 0;
}
