#include <stdio.h>
int main()
{
    char hiasanbatang[1];
    int width, tinggiBatang;
    printf("lebar pohon :");
    scanf("%d", &width);
    printf("tinggi b pohon :");
    scanf("%d", &tinggiBatang);
    printf("input batangggg :");
    scanf("%s", &hiasanbatang);

    if (width % 2 == 0)
    {
        width++; // Membuat lebar ganjil jika inputan genap
    }
    int tinggi = (width / 2) + 1;
    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            for (int k = width / 2 + 1 - i; k >= 1; k--)
            {
                printf(" ");
            }
            for (int k = 1; k <= (2 * i - 1); k++)
            {
                printf("*");
            }
            break;
        }
        printf("\n");
    }

    int batang = (width / 3);
    if (batang < 1)
    {
        batang = 1;
    }

    for (int i = 1; i <= tinggiBatang; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            for (int k = 1; k <= (width - batang) / 2; k++)
            {
                printf(" ");
            }
            for (int k = 1; k <= batang; k++)
            {
                printf("%s", hiasanbatang);
            }
            break;
        }
        printf("\n");
    }

    for (int tanah = 0; tanah < width; tanah++)
    {
        printf("=");
    }

    return 0;
}