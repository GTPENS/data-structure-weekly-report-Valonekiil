#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];
// Fungsi pengurutan Selection sort
// Fungsi untuk menukar data
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void SelectionSort()
{
    int i, j, k;
    for (i = 0; i < MAX - 1; i++)
    {
        k = i;
        for (j = i + 1; j < MAX; j++)
            if (Data[k] > Data[j])
                k = j;
        Tukar(&Data[i], &Data[k]);
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
    SelectionSort();

    // Data setelah terurut
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
