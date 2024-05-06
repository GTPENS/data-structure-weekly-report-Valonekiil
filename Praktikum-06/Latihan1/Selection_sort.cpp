#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];


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
            if (Data[k] > Data[j])
                k = j;
        Tukar(&Data[i], &Data[k]);
        //Untuk menampilkan data setelah setiap iterasi terpanggil
        cout << "\nPerubahan pada data setelah iterasi ke " << c << endl;
        for (v = 0; v < MAX; v++)
        {
            cout << Data[v] << "\t";
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

    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
       cout << Data[i] << "\t";
    }

    return 0;
}
