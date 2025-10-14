#include <stdio.h>

int main()
{
    int time = 10;
    while (time > 0)
    {
        printf("Waktu tersisa %d detik\n", time);
        time--;
    }
    printf("Waktu habis!\n");
    return 0;
}