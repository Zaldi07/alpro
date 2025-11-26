#include <stdio.h>
int main()
{

    // pengulangan akan dilakukan mulai dari 1 sampai kondisi tidak terpenuhi
    // maka nilai i yang memenuhi kondisi adalah (1,2,3,4,5)

    // pengulangan 1  | i=1;
    // i == 1 -> true -> maka menampilkan "Hello Buku"
    // pengulangan 2  | i=2;
    // i == 2 -> true -> maka menampilkan "Hello Pensil"
    // pengulangan 3  | i=3;
    // i != 3 -> false -> maka menampilkan else yaitu -> "Hello alat tulis lainnya"
    // Pengulangan 4  | i=4;
    // i != 3 -> true -> maka menampilkan "Hello penghapus"
    // Pengulangan 5  | i=5;
    // i != 3 -> true -> maka menampilkan "Hello penghapus"
    for (int i = 1; i <= 5; i++)
    {
        if (i == 1)
        {
            printf("Hello Buku\n");
        }
        else if (i == 2)
        {
            printf("Hello Pensil\n");
        }
        else if (i != 3)
        {
            printf("Hello Penghapus\n");
        }
        else
        {
            printf("Hello Alat tulis Lainnya\n");
        }
    }
}