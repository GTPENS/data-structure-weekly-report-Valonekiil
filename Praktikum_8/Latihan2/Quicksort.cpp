#include <iostream>
#include <cstdlib>
#define MAX 10

using namespace std;

int Data[MAX];
int pg= 0,pb= 0;
// Prosedur menukar data
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    pg++;
}

// Prosedur pengurutan metode Quick Sort
void QuickSortRekursif(int L, int R)
{
    int i, j, x;
    x = Data[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j)
    {
        while (Data[i] < x){
            i++;
            pb++;}
        while (Data[j] > x){
            j--;
            pb++;}
        if (i <= j)
        {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        QuickSortRekursif(L, j);
    if (i < R)
        QuickSortRekursif(i, R);
}

int main()
{
    int i;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = rand() % 100 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    QuickSortRekursif(0, MAX - 1);

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    cout <<"Total Perbandingan: "<< pb <<"\nTotal Pergeseran:"<< pg;

    return 0;
}
