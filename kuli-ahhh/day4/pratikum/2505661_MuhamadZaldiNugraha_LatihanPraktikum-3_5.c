#include <stdio.h>
#include <string.h>

int main()
{
    char status[10];
    char jenis[10];
    int jumlah;

    printf("Masukkan status anggota (aktif/tidak): ");
    scanf("%s", status);

    if (strcmp(status, "aktif") != 0)
    {
        printf("Akun Anda tidak aktif, tidak bisa meminjam.\n");
        return 0;
    }

    printf("Masukkan jumlah buku yang sedang dipinjam: ");
    scanf("%d", &jumlah);

    if (jumlah >= 3)
    {
        printf("Pinjaman buku sudah maksimal.\n");
        return 0;
    }

    printf("Masukkan jenis keanggotaan (reguler/premium): ");
    scanf("%s", jenis);

    printf("Anggota boleh meminjam buku baru\n");

    if (strcmp(jenis, "reguler") == 0)
    {
        printf("Jenis buku: Cetak\n");
        printf("Lama peminjaman maksimal: 7 hari\n");
    }
    else if (strcmp(jenis, "premium") == 0)
    {
        printf("Jenis buku: Cetak atau E-book\n");
        printf("Lama peminjaman maksimal: 14 hari\n");
    }
    else
    {
        printf("Jenis keanggotaan tidak dikenal.\n");
    }

    return 0;
}
