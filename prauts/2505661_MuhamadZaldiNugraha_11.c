#include <stdio.h>
int main()
{

    int i, n = 9;

    // disini akan mengulangan sebanyak 9 pengulangan karena i yang memenuhi kondisi adalah (0,1,2,3,4,5,6,7,8)
    for (int i = 0; i < n; i++)
    {
        // akan dicek  jika i % 2 != 0 maka akan menampilkan angkanya(Angka ganjil)
        if (i % 2 != 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}