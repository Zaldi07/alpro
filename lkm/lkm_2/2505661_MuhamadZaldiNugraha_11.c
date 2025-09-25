#include <stdio.h>
int main()
{
    float ip;
    printf("Masukan IP Mahasiswa : ");
    scanf("%f", &ip);
    if (ip <= 3.00)
    {
        printf("Mahasiswa dapat mengontrak 20 SKS\n");
    }
    else if (ip < 3.50)
    {
        printf("Mahasiswa dapat mengontrak 23 SKS\n");
    }
    else
    {
        printf("Mahasiswa dapat mengontrak 24 SKS\n");
    }
    return 0;
}
