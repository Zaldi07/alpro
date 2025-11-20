#include <stdio.h>
int main()
{
    int hariKerja;
    float gajipokok = 6000000;
    float tunjunganTransport, tunjunganMakan, pajak, totalPendapatan, gajiBersih;
    printf("Masukan jumlah hari kerja: ");
    scanf("%d", &hariKerja);

    tunjunganTransport = gajipokok * 0.1;
    tunjunganMakan = 25000 * hariKerja;
    totalPendapatan = gajipokok + tunjunganTransport + tunjunganMakan;
    pajak = totalPendapatan * 0.05;
    gajiBersih = totalPendapatan - pajak;

    printf("Gaji Pokok: Rp%.0f\n", gajipokok);
    printf("Tunjangan Transport : Rp%.0f\n", tunjunganTransport);
    printf("Tunjangan Makan : Rp%.0f\n", tunjunganMakan);
    printf("Pajak Penghasilan : Rp%.0f\n", pajak);
    printf("Gaji Bersih : Rp%.0f\n", gajiBersih);
    return 0;
}