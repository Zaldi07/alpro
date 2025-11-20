#include <stdio.h>
#include <string.h>
int main()
{
    int i = 50000, j;
    char p1[20];
    char p2[20] = "tes123";
    scanf("%s", &p1);
    scanf("%d", &j);
    if (strcmp(p1, p2) == 0)
    {
        if (j <= i)
        {
            printf("berhasil\n");
            printf("sisa %d",i-j);
        }
        else
        {
            printf("gagal");
            printf("Saldo tidak mahi");
        }
    }
    else
    {
        printf("akun anda dibloker");
    }
}