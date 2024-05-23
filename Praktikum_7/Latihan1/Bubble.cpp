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

void BubbleSort()
{
    int i,j,k;
    for (i = 0; i < MAX - 1; i++)
    {
        for (j = i + 1; j < MAX; j++)
            if (Data[i] > Data[j])
                Tukar(&Data[i], &Data[j]);
        cout << "Iterasi ke: " << i + 1 << endl;
        for (k = 0; k < MAX; k++)
            cout << Data[k] << "\t";
        cout << endl;
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
        cout << Data[i] << "\t";
    }
    cout << endl;

    BubbleSort();

    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << Data[i] << "\t";
    }

    return 0;
}