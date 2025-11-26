#include <stdio.h>
int main()
{
    int jual1 = 250000, modal1 = 200000;
    int jual2 = 250000, modal2 = 200000;
    int jual3 = 250000, modal3 = 200000;
    int total;
    int keuntungan1, keuntungan2, keuntungan3;
    keuntungan1 = jual1 - modal1;
    keuntungan2 = jual2 - modal2;
    keuntungan3 = jual3 - modal3;

    total = keuntungan1 + keuntungan2 + keuntungan3;
    printf("Total keuntungan toko: %d", total);
    return 0;
}