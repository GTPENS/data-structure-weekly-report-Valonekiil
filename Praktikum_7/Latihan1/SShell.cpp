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

void SShellSort()
{
    int i,j,Jarak,t,v = 1;
    bool sudah;
    Jarak = MAX;
    while (Jarak > 1)
    {
        Jarak = Jarak / 2;
        sudah = false;
        while (!sudah)
        {
            sudah = true;
            for (j = 0; j < MAX - Jarak; j++)
            {
                i = j + Jarak;
                if (Data[j] > Data[i])
                {
                    Tukar(&Data[j], &Data[i]);
                    cout << "\nIterasi ke " << v  <<"\tJarak: " << Jarak << endl;;
                    for (t = 0; t < MAX; t++)
                        cout << Data[t] << "\t";
                    v++;
                    sudah = false;
                }
            }
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
        cout << Data[i] << "\t";
    }
    cout << endl;

    SShellSort();

    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << Data[i] << "\t";
    }

    return 0;
}