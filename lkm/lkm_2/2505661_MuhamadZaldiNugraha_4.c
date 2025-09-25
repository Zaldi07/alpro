#include <stdio.h>
int main()
{
    int nilai;
    printf("Masukan Nilai Ujian");
    scanf("%d", &nilai);
    if (nilai >= 60)
    {
        printf("Lulus Ujian\n");
    }
    else
    {
        printf("Mengulang Ujian\n");
    }
    return 0;
}
