#include <stdio.h>
#include <stdlib.h>

int main()
{
    // deklerasikan variabel
    int jam, jumlahVirus, jumlahAwalVirus;

    // Input
    printf("Jumlah awal virus : ");
    scanf("%d", &jumlahAwalVirus);
    printf("Masukkan waktu dalam jam : ");
    scanf("%d", &jam);

    // dikarenakan virus bertumbuh 2 jam sekali maka di bagi 2 total jam nya.
    jumlahVirus = ((jam / 2) * 50) + jumlahAwalVirus;

    // Output
    printf("Jumlah virus setelah %d jam adalah %d\n", jam, jumlahVirus);

    return 0;
}
