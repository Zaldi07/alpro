#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 50
#define MAX_CODE 10
#define MAX_PRODUCTS 100
#define MAX_ORDER_ITEMS 20
#define MAX_TRANSACTIONS 1000

typedef struct
{
    char code[MAX_CODE];
    char name[MAX_NAME];
    int price; // dalam rupiah
    int stock; // jumlah stok
} Product;

typedef struct
{
    int productIndex; // index ke array products
    int qty;
    int subtotal; // price * qty
} OrderItem;

typedef struct
{
    int id;           // nomor struk
    char timeStr[20]; // "YYYY-MM-DD HH:MM"
    OrderItem items[MAX_ORDER_ITEMS];
    int itemCount;
    int total;
    int cash;
    int change;
} Transaction;

Product products[MAX_PRODUCTS];
int productCount = 0;

Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

void getNowString(char *buffer, size_t size)
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, size, "%Y-%m-%d %H:%M", tm_info);
}

void pauseEnter()
{
    printf("\nTekan ENTER untuk lanjut...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // buang buffer
    }
}

int findProductByCode(const char *code)
{
    for (int i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].code, code) == 0)
        {
            return i;
        }
    }
    return -1;
}

void saveProducts()
{
    FILE *f = fopen("products.txt", "w");
    if (!f)
    {
        printf("Gagal menyimpan products.txt\n");
        return;
    }

    for (int i = 0; i < productCount; i++)
    {
        fprintf(
            f,
            "%s;%s;%d;%d\n",
            products[i].code,
            products[i].name,
            products[i].price,
            products[i].stock);
    }

    fclose(f);
}

void loadProducts()
{
    FILE *f = fopen("products.txt", "r");
    if (!f)
    {
        // jika belum ada file, isi default menu kopi
        printf("products.txt tidak ditemukan, membuat menu default...\n");
        productCount = 0;

        strcpy(products[productCount].code, "C1");
        strcpy(products[productCount].name, "Espresso");
        products[productCount].price = 15000;
        products[productCount].stock = 50;
        productCount++;

        strcpy(products[productCount].code, "C2");
        strcpy(products[productCount].name, "Americano");
        products[productCount].price = 18000;
        products[productCount].stock = 40;
        productCount++;

        strcpy(products[productCount].code, "C3");
        strcpy(products[productCount].name, "Cappuccino");
        products[productCount].price = 22000;
        products[productCount].stock = 35;
        productCount++;

        strcpy(products[productCount].code, "C4");
        strcpy(products[productCount].name, "Latte");
        products[productCount].price = 23000;
        products[productCount].stock = 30;
        productCount++;

        strcpy(products[productCount].code, "C5");
        strcpy(products[productCount].name, "Kopi Susu Gula Aren");
        products[productCount].price = 20000;
        products[productCount].stock = 60;
        productCount++;

        saveProducts();
        return;
    }

    productCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), f))
    {
        if (productCount >= MAX_PRODUCTS)
        {
            break;
        }
        char *token;
        token = strtok(line, ";\n");
        if (!token)
            continue;
        strncpy(products[productCount].code, token, MAX_CODE);
        products[productCount].code[MAX_CODE - 1] = '\0';

        token = strtok(NULL, ";\n");
        if (!token)
            continue;
        strncpy(products[productCount].name, token, MAX_NAME);
        products[productCount].name[MAX_NAME - 1] = '\0';

        token = strtok(NULL, ";\n");
        if (!token)
            continue;
        products[productCount].price = atoi(token);

        token = strtok(NULL, ";\n");
        if (!token)
            continue;
        products[productCount].stock = atoi(token);

        productCount++;
    }

    fclose(f);
}

void appendTransactionToFile(const Transaction *tx)
{
    FILE *f = fopen("transactions.txt", "a");
    if (!f)
    {
        printf("Gagal membuka transactions.txt untuk menulis\n");
        return;
    }

    fprintf(
        f,
        "T;%d;%s;%d;%d;%d\n",
        tx->id,
        tx->timeStr,
        tx->total,
        tx->cash,
        tx->change);
    for (int i = 0; i < tx->itemCount; i++)
    {
        const Product *p = &products[tx->items[i].productIndex];
        fprintf(
            f,
            "I;%s;%d;%d\n",
            p->code,
            tx->items[i].qty,
            tx->items[i].subtotal);
    }
    fprintf(f, "END\n");

    fclose(f);
}

void printProducts()
{
    printf("\n==== DAFTAR MENU KOPI ====");
    printf("\n%-4s %-8s %-25s %-10s %-6s\n",
           "No", "Kode", "Nama", "Harga", "Stok");
    printf("===============================================================\n");
    for (int i = 0; i < productCount; i++)
    {
        printf("%-4d %-8s %-25s %10d %-6d\n",
               i + 1,
               products[i].code,
               products[i].name,
               products[i].price,
               products[i].stock);
    }
}

void addProduct()
{
    if (productCount >= MAX_PRODUCTS)
    {
        printf("Jumlah produk sudah maksimum.\n");
        return;
    }

    Product p;
    printf("\n=== Tambah Menu Kopi ===\n");
    printf("Kode (tanpa spasi): ");
    scanf("%9s", p.code);
    getchar(); // buang newline

    printf("Nama menu        : ");
    fgets(p.name, MAX_NAME, stdin);
    size_t len = strlen(p.name);
    if (len > 0 && p.name[len - 1] == '\n')
        p.name[len - 1] = '\0';

    printf("Harga (rupiah)   : ");
    scanf("%d", &p.price);
    printf("Stok awal        : ");
    scanf("%d", &p.stock);
    getchar();

    products[productCount++] = p;
    saveProducts();
    printf("Menu kopi berhasil ditambahkan.\n");
}

void updateStock()
{
    char code[MAX_CODE];
    printf("\n=== Update Stok ===\n");
    printProducts();
    printf("\nMasukkan kode menu yang akan di-update: ");
    scanf("%9s", code);
    getchar();

    int idx = findProductByCode(code);
    if (idx == -1)
    {
        printf("Produk dengan kode %s tidak ditemukan.\n", code);
        return;
    }

    int newStock;
    printf("Stok saat ini: %d\n", products[idx].stock);
    printf("Masukkan stok baru: ");
    scanf("%d", &newStock);
    getchar();

    products[idx].stock = newStock;
    saveProducts();
    printf("Stok berhasil di-update.\n");
}

void newSale()
{
    Transaction tx;
    tx.id = transactionCount + 1;
    getNowString(tx.timeStr, sizeof(tx.timeStr));
    tx.itemCount = 0;
    tx.total = 0;

    while (1)
    {
        printProducts();
        printf("\nTransaksi #%d - %s\n", tx.id, tx.timeStr);
        printf("Pilih nomor menu (0 untuk selesai): ");
        int choice;
        if (scanf("%d", &choice) != 1)
        {
            printf("Input tidak valid.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            continue;
        }

        if (choice == 0)
        {
            break;
        }
        if (choice < 1 || choice > productCount)
        {
            printf("Nomor menu tidak valid.\n");
            continue;
        }

        if (tx.itemCount >= MAX_ORDER_ITEMS)
        {
            printf("Jumlah item per transaksi sudah maksimum (%d).\n",
                   MAX_ORDER_ITEMS);
            break;
        }

        int idx = choice - 1;
        int qty;
        printf("Masukkan jumlah (%s): ", products[idx].name);
        scanf("%d", &qty);
        if (qty <= 0)
        {
            printf("Jumlah harus > 0.\n");
            continue;
        }
        if (qty > products[idx].stock)
        {
            printf("Stok tidak cukup. Stok tersedia: %d\n", products[idx].stock);
            continue;
        }

        OrderItem item;
        item.productIndex = idx;
        item.qty = qty;
        item.subtotal = products[idx].price * qty;

        products[idx].stock -= qty;
        tx.items[tx.itemCount++] = item;
        tx.total += item.subtotal;

        printf("Ditambahkan: %s x%d = %d\n",
               products[idx].name,
               qty,
               item.subtotal);
        saveProducts();
    }

    if (tx.itemCount == 0)
    {
        printf("Tidak ada item dalam transaksi. Dibatalkan.\n");
        return;
    }

    printf("\n===== RINGKASAN TRANSAKSI =====\n");
    for (int i = 0; i < tx.itemCount; i++)
    {
        Product *p = &products[tx.items[i].productIndex];
        printf("%s x%d = %d\n",
               p->name,
               tx.items[i].qty,
               tx.items[i].subtotal);
    }
    printf("Total: %d\n", tx.total);

    int cash;
    while (1)
    {
        printf("Tunai: ");
        scanf("%d", &cash);
        if (cash < tx.total)
        {
            printf("Uang kurang. Harus >= %d\n", tx.total);
        }
        else
        {
            break;
        }
    }

    tx.cash = cash;
    tx.change = cash - tx.total;

    printf("Kembalian: %d\n", tx.change);

    // simpan ke memori & file
    if (transactionCount < MAX_TRANSACTIONS)
    {
        transactions[transactionCount++] = tx;
    }
    appendTransactionToFile(&tx);

    // cetak struk sederhana
    printf("\n====== STRUK KOPI CORNER ======\n");
    printf("No: %d\n", tx.id);
    printf("Waktu: %s\n", tx.timeStr);
    printf("------------------------------\n");
    for (int i = 0; i < tx.itemCount; i++)
    {
        Product *p = &products[tx.items[i].productIndex];
        printf("%-20s x%-2d %8d\n",
               p->name,
               tx.items[i].qty,
               tx.items[i].subtotal);
    }
    printf("------------------------------\n");
    printf("Total     : %d\n", tx.total);
    printf("Tunai     : %d\n", tx.cash);
    printf("Kembalian : %d\n", tx.change);
    printf("Terima kasih!\n");
}

void printSessionReport()
{
    if (transactionCount == 0)
    {
        printf("\nBelum ada transaksi pada sesi ini.\n");
        return;
    }

    int grandTotal = 0;
    printf("\n===== LAPORAN PENJUALAN (SESI INI) =====\n");
    for (int i = 0; i < transactionCount; i++)
    {
        Transaction *tx = &transactions[i];
        printf("\nTransaksi #%d - %s\n", tx->id, tx->timeStr);
        for (int j = 0; j < tx->itemCount; j++)
        {
            Product *p = &products[tx->items[j].productIndex];
            printf("  %-20s x%-2d %8d\n",
                   p->name,
                   tx->items[j].qty,
                   tx->items[j].subtotal);
        }
        printf("  Total: %d\n", tx->total);
        grandTotal += tx->total;
    }
    printf("\nTotal pemasukan sesi ini: %d\n", grandTotal);
}

int main()
{
    loadProducts();

    while (1)
    {
        printf("\n==============================\n");
        printf("   SISTEM POS TOKO KOPI   \n");
        printf("==============================\n");
        printf("1. Lihat menu kopi\n");
        printf("2. Tambah menu kopi\n");
        printf("3. Update stok\n");
        printf("4. Transaksi penjualan (POS)\n");
        printf("5. Laporan penjualan sesi ini\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");

        int choice;
        if (scanf("%d", &choice) != 1)
        {
            printf("Input tidak valid.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            continue;
        }

        // buang newline setelah angka
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        switch (choice)
        {
        case 1:
            printProducts();
            pauseEnter();
            break;
        case 2:
            addProduct();
            pauseEnter();
            break;
        case 3:
            updateStock();
            pauseEnter();
            break;
        case 4:
            newSale();
            pauseEnter();
            break;
        case 5:
            printSessionReport();
            pauseEnter();
            break;
        case 0:
            printf("Keluar dari program...\n");
            return 0;
        default:
            printf("Menu tidak dikenal.\n");
        }
    }
}
