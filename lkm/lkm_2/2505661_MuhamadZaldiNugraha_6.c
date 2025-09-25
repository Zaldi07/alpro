#include <stdio.h>
int main()
{
    int usia;
    printf("Masukan Usia Siswa : ");
    scanf("%d", &usia);
    if (usia >= 17)
    {
        printf("Usia sudah cukup\n");
    }
    else
    {
        printf("Usia belum cukup\n");
    }
    return 0;
}
