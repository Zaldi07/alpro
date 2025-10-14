#include <stdio.h>

int main()
{
    int i = 1;
    int batas = 10;
    while (i <= batas)
    {
        if (i % 2 == 0)
        {
            printf("%d adalah bilangan genap\n", i);
        }
        else
        {
            printf("%d adalah bilangan ganjil\n", i);
        }
        i++;
    }
}