#include <stdio.h>
#include <stdlib.h>
int main()
{
    int massa, v1, v2, t;
    float f, a;
    printf("massa: ");
    scanf("%d", &massa);
    printf("v1: ");
    scanf("%d", &v1);
    printf("v2: ");
    scanf("%d", &v2);
    printf("t: ");
    scanf("%d", &t);
    a = v2 - v1 / t;
    f = massa * a;
    printf("F = %.2f N", f);
}