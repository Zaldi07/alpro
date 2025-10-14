#include <stdio.h>

int main()
{
    int jumlahMahasiswa;
    int totalNilai = 0;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlahMahasiswa);
    int nilai[jumlahMahasiswa];
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
        totalNilai += nilai[i];
    }
    float rataRata = (float)totalNilai / jumlahMahasiswa;
    printf("Rata-rata nilai: %.2f\n", rataRata);

    return 0;
}