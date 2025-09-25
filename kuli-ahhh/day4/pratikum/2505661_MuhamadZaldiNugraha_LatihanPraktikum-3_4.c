#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    char op;
    int hasil = 1;

    printf("Masukkan angka pertama: ");
    scanf("%d", &a);

    printf("Masukkan angka kedua: ");
    scanf("%d", &b);

    printf("Masukkan operator (+ - * / %% ^): ");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        printf("Hasil: %d\n", a + b);
        break;
    case '-':
        printf("Hasil: %d\n", a - b);
        break;
    case '*':
        printf("Hasil: %d\n", a * b);
        break;
    case '/':
        if (b == 0)
        {
            printf("Error: pembagi nol tidak diperbolehkan.\n");
        }
        else
        {
            float hasil2 = (float)a / b;
            printf("Hasil: %.2f\n", hasil2);
        }
        break;
    case '%':
        if (b == 0)
        {
            printf("Error: pembagi nol tidak diperbolehkan.\n");
        }
        else
        {
            printf("Hasil: %d\n", a % b);
        }
        break;
    case '^':
    {
        int hasil = pow(a, b); // hati-hati overflow kalau pangkat besar
        printf("Hasil: %d\n", hasil);
        break;
    }
    default:
        printf("Operator tidak dikenali\n");
        break;
    }

    return 0;
}
