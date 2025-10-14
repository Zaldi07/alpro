#include <stdio.h>

int main()
{
    int i = 0;
    int totalRow = 5;
    int totalCol = 5;
    int col;
    int day = 1;
    while (i < totalRow)
    {
        col = 0;
        while (col <= totalCol)
        {
         
                printf(" %d ", day);
            

            col++;
            day++;
        }
        printf("\n");
        i++;
    }
}