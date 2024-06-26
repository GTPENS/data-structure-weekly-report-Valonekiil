#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];

// Fungsi pengurutan biner sort
void BinaryInsertSort()
{
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++)
    {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
    }
}

int main()
{
    int i;
    srand(0);

    // Menampilkan bilangan acak sebagai data
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = rand() % 100 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    BinaryInsertSort();

    // Data setelah terurut
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
