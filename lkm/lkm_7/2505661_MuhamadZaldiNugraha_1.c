#include <stdio.h>

struct Vip_ticket
{
    char name[50];
    int no_ticket;
};

struct Regular_ticket
{
    char name[50];
    int no_ticket;
};

void swapVip(struct Vip_ticket *a, struct Vip_ticket *b)
{
    struct Vip_ticket temp = *a;
    *a = *b;
    *b = temp;
}

void swapRegular(struct Regular_ticket *a, struct Regular_ticket *b)
{
    struct Regular_ticket temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortVip(struct Vip_ticket arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1].no_ticket < arr[j].no_ticket)
            {
                swapVip(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortRegular(struct Regular_ticket arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1].no_ticket < arr[j].no_ticket)
            {
                swapRegular(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void handleInput(
    struct Vip_ticket vip[],
    struct Regular_ticket regular[],
    int max_vip,
    int max_regular,
    int *jumlahVip,
    int *jumlahRegular)
{
    int indexVip = 0;
    int indexReg = 0;
    printf("=== Input data tiket ===\n");
    while (1)
    {

        if (indexVip >= max_vip && indexReg >= max_regular)
        {
            printf("\nKapasitas tiket VIP dan Reguler sudah penuh.\n");
            break;
        }

        int tempCategory;

        while (1)
        {
            printf("Pilih kategori tiket (Regular = 0, VIP = 1): ");
            scanf("%d", &tempCategory);

            if (tempCategory == 0 || tempCategory == 1)
            {
                break;
            }
            else
            {
                printf("Input kategori tidak valid, coba lagi aja.\n");
            }
        }

        if (tempCategory == 0)
        {
            // REGULER
            if (indexReg >= max_regular)
            {
                printf("Kapasitas tiket Reguler sudah penuh.\n");
                continue;
            }

            printf("Masukan nama (Reguler): ");
            scanf(" %[^\n]", regular[indexReg].name);
            printf("Nomor tiket          : ");
            scanf("%d", &regular[indexReg].no_ticket);
            indexReg++;
        }
        else
        {

            if (indexVip >= max_vip)
            {
                printf("Kapasitas tiket vip sudha penuh.\n");
                continue;
            }

            printf("Masukan nama (VIP)   : ");
            scanf(" %[^\n]s", vip[indexVip].name);
            printf("Nomor tiket          : ");
            scanf("%d", &vip[indexVip].no_ticket);
            indexVip++;
        }

        int lanjut;
        printf("\nmau tambah tiket lagi gak ? (1 = ya, 0 = tidak): ");
        scanf("%d", &lanjut);

        if (lanjut == 0)
        {

            break;
        }
    }

    *jumlahVip = indexVip;
    *jumlahRegular = indexReg;
}

void printTickets(struct Vip_ticket vip[], struct Regular_ticket regular[],
                  int jumlahVip, int jumlahRegular)
{

    printf("\nUrutan Nomor Tiket - Kategori VIP\n");
    if (jumlahVip == 0)
    {
        printf("(Tidak ada tiket VIP)\n");
    }
    else
    {
        for (int i = 0; i < jumlahVip; i++)
        {
            printf("Tiket %d - %s\n", vip[i].no_ticket, vip[i].name);
        }
    }

    printf("\nUrutan Nomor Tiket - Kategori Reguler\n");
    if (jumlahRegular == 0)
    {
        printf("(Tidak ada tiket Reguler)\n");
    }
    else
    {
        for (int i = 0; i < jumlahRegular; i++)
        {
            printf("Tiket %d - %s\n", regular[i].no_ticket, regular[i].name);
        }
    }
}

int main()
{
    int maxRegular = 150;
    int maxVip = 50;

    struct Vip_ticket vipTickets[maxVip];
    struct Regular_ticket RegularTickets[maxRegular];

    int jumlahVip = 0;
    int jumlahRegular = 0;

    handleInput(vipTickets, RegularTickets,
                maxVip, maxRegular,
                &jumlahVip, &jumlahRegular);

    bubbleSortVip(vipTickets, jumlahVip);
    bubbleSortRegular(RegularTickets, jumlahRegular);

    printTickets(vipTickets, RegularTickets, jumlahVip, jumlahRegular);

    return 0;
}
