#include <stdio.h>
#include <stdbool.h>

int main()
{
    int akademik, wawancara, psikotes;

    printf("Masukkan nilai Tes Akademik: ");
    scanf("%d", &akademik);
    printf("Masukkan nilai Tes Wawancara: ");
    scanf("%d", &wawancara);
    printf("Masukkan nilai Tes Psikotes: ");
    scanf("%d", &psikotes);

    // (Opsional) validasi rentang 0–100
    if (akademik < 0 || akademik > 100 ||
        wawancara < 0 || wawancara > 100 ||
        psikotes < 0 || psikotes > 100)
    {
        printf("Input tidak valid (harus 0..100)\n");
        return 0;
    }

    // A. LULUS SEMPURNA
    if (akademik >= 85 && wawancara >= 80 && psikotes >= 75)
    {
        printf("Status: LULUS SEMPURNA\n");
    }
    // B. LULUS
    else if (akademik >= 70 && wawancara >= 65 && psikotes >= 60)
    {
        printf("Status: LULUS\n");
    }
    // C. CADANGAN (Akademik >= 90 tapi salah satu tes lain tak memenuhi syarat minimal)
    else if (akademik >= 90 && (wawancara < 65 || psikotes < 60))
    {
        printf("Status: CADANGAN\n");
    }
    // Selain itu: TIDAK LULUS
    else
    {
        printf("Status: TIDAK LULUS\n");
    }

    return 0;
}
