#include <stdio.h>
int main()
{
    int tugas;
    printf("Total tugas yang dikerjakan :");
    scanf("%d", &tugas);
    if (tugas >= 9)
    {
        printf("Lulus.\n");
    }
    else if (tugas > 6 && tugas < 9)
    {
        printf("Perlu mengerjakan tugas tambahan.\n");
    }
    else
    {
        printf("Perlu mengerjakan proyek tambahan.\n");
    }
    return 0;
}
