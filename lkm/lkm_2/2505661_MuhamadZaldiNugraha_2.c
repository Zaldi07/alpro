#include <stdio.h>
int main()
{
    int tarik;
    printf("Tuliskan nominal penarikan uang: ");
    scanf("%d", &tarik);
    if (tarik > 5000000)
    {
        printf("Anda melebihi limit penarikan.\n");
    }
    return 0;
}
