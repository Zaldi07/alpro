#include <stdio.h>
int main()
{
    int jumlahMahasiswa;
    int kuotaKelas = 50;
    printf("Masukkan jumlah mahasiswa yang mengontrak mata kuliah animasi: ");
    scanf("%d", &jumlahMahasiswa);
    if (jumlahMahasiswa <= 30)
    {
        kuotaKelas = kuotaKelas - jumlahMahasiswa;
        printf("Kuota kelas masih tersedia untuk %d orang\n", kuotaKelas);
    }
    else if (jumlahMahasiswa > 30 && jumlahMahasiswa <= 50)
    {
        kuotaKelas = kuotaKelas - jumlahMahasiswa;
        printf("Kuota kelas hampir penuh\n");
        printf("Tersedia untuk %d orang\n", kuotaKelas);
    }
    else
    {
        printf("Kuota kelas sudah penuh\n");
    }

    return 0;
}
