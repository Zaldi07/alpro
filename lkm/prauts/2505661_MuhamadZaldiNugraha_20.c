#include <stdio.h>
int main()
{
    int baris, kolom, s;
    printf("Masukan jumlah baris : ");
    scanf("%d", &baris);
    printf("Masukan jumlah kolom : ");
    scanf("%d", &kolom);
    int arr[baris][kolom];

    printf("Masukan element matriks %dx%d:\n", baris, kolom);
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < baris; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nMatriks\n");
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < baris; j++)
        {
            if (baris == kolom)
            {
                if (arr[i][j] != arr[j][i])
                {
                    s = 1;
                }
            }

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    if (s == 0)
    {
        printf("Hasil: Matriks ini SIMETRIS");
    }
    else
    {
        printf("Hasil: Matrikks ini TIDAK SIMETRIS");
    }
    return 0;
}