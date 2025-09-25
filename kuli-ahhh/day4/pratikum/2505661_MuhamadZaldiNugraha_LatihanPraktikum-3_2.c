#include <stdio.h>
#include <string.h>

int main()
{
    char username[20], password[20], role[10];

    printf("Masukkan username: ");
    scanf("%s", username);

    if (strcmp(username, "grace") == 0)
    {
        printf("Masukkan password: ");
        scanf("%s", password);

        if (strcmp(password, "12345") == 0)
        {
            printf("Masukkan role (admin/user): ");
            scanf("%s", role);

            if (strcmp(role, "admin") == 0)
            {
                printf("Selamat datang Admin\n");
            }
            else if (strcmp(role, "user") == 0)
            {
                printf("Selamat datang User\n");
            }
            else
            {
                printf("Role tidak dikenali\n");
            }
        }
        else
        {
            printf("Password salah\n");
        }
    }
    else
    {
        printf("Username tidak ditemukan\n");
    }

    return 0;
}