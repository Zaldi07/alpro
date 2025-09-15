#include <stdio.h>
#include <stdlib.h>
int main ()
{
   
//Program konversi CM ke KM
int ukuran_CM,  hasil;
//Proses Input (pakai scanf)
printf ("Masukan Jumlah (dalam CM): \n");
scanf ("/d", &ukuran_CM);
//Konversi CM ke KM
hasil = ukuran_CM * 10000;

printf(“Ukuran KM = %.2f”, hasil);
//Proses Output


    return 0;
}