#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];
int b,B; // Untuk menghitung perbandingan
int g,G; // Untuk menghitung penggeseran

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
            b++;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--){
            Data[j + 1] = Data[j];
            g++;
        }
        Data[l] = x;
        g++;
        cout << "\nPada Iterasi ke " << i << " Terdapat " << g << " Penggeseran dan " << b << " Perbandingan"<< endl;
        for (int v = 0; v < MAX; v++)
            {
                cout << Data[v] << "\t";
            }
        G += g; B += b; b = 0; g = 0;
        if (i + 1 == MAX){
            cout << "\nTotal pergeseran : " << G << "\nTotal perbandingan : " << B << endl;
        }
    }
}

int main()
{
    int i;
    srand(0);

    
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = rand() % 100 + 1;
         cout << Data[i] << " \t";
    }
    BinaryInsertSort();

    
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << Data[i] << " \t";
    }

    return 0;
}
