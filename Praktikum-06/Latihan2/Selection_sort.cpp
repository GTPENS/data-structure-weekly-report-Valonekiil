#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];
int b,B; // Untuk menghitung perbandingan
int g,G; // Untuk menghitung penggeseran

void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort()
{
    int i, j, k,v,c;
    c = 1;
    for (i = 0; i < MAX - 1; i++)
    {
        c = 1 + i;
        k = i;
        for (j = i + 1; j < MAX; j++)
        {
            b++;
            if (Data[k] > Data[j])
                k = j;
        }
        Tukar(&Data[i], &Data[k]);
        g++;
        cout << "\nPada Iterasi ke " << i + 1 << " Terdapat " << g << " Penggeseran dan " << b << " Perbandingan"<< endl;
        for (int v = 0; v < MAX; v++)
            {
                cout << Data[v] << "\t";
            }
        G += g; B += b; b = 0; g = 0;
        if (i + 2 == MAX){
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
        Data[i] = rand() % 100 +1 ;
        cout << Data[i] << "\t";
    }
    SelectionSort();

    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
       cout << Data[i] << "\t";
    }

    return 0;
}
