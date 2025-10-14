#include <stdio.h>
#include <string.h>

int main()
{
    char CorrectPassword[20] = "helloWorld123";
    char password[20];
    int MaxAttemps = 3;

    while (MaxAttemps > 0)
    {
        printf("Masukan password:");
        scanf("%s", &password);
        if (strcmp(CorrectPassword, password) == 0)
        {
            printf("Login berhasil\n");
            return 0;
        }
        else
        {
            MaxAttemps--;
            printf("Password salah! Sisa percobaan : %d \n", MaxAttemps);

            if (MaxAttemps <= 0)
            {
                printf("Akun terkunci");
            }
        }
    }

    return 0;
}
