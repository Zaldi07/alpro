#include <stdio.h>
int main()
{

    // karena menggunakan do while maka pasti melakukan 1 eksekusi kode
    // karna x dimulai 1 dan kondisi pengulangan adalah x <= 4 maka nilai  x yg memenuhi pengulangan ialah 1,2,3,4
    // 1. jika x adalah ganjil maka total akan bertambah 2
    // 2. jika x adalah genap maka akan ditambah nilai x

    // 1. +2
    // 2. +2
    // 3. +2
    // 4. +4

    // sehingga total nya adalah 10

    int x = 1, total = 0;
    do
    {
        if (x % 2 == 0)
        {
            total = total + x;
            printf("Tambah %d\n", x);
        }
        else
        {
            total = total + 2;
            printf("Tambah 2\n");
        }
        x++;
    } while (x <= 4);
    printf("Total Akhir = %d\n", total);
    return 0;
}