#include <stdio.h>
int main()
{
    int inovasi, stabilitas, presentasi;
    printf("Masukkan skor inovasi: ");
    scanf("%d", &inovasi);
    printf("Masukkan skor stabilitas: ");
    scanf("%d", &stabilitas);
    printf("Masukkan skor presentasi: ");
    scanf("%d", &presentasi);

    if (inovasi > 100 || stabilitas > 100 || presentasi > 100)
    {
        printf("Input tidak valid");
        return 0;
    }

    if (inovasi >= 85)
    {
        if (stabilitas >= 70 && presentasi >= 60)
        {
            printf("LOLOS FINAL");
        }
        else
        {
            printf("CADANGAN FINAL");
        }
    }
    else
    {
        printf("CADANGAN FINAL");
    }

    return 0;
}