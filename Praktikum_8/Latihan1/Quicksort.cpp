#include <iostream>
#include <cstdlib>
#define MAX 10
#define MaxStack 10

using namespace std;

int Data[MAX]; 

void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSortNonRekursif()
{
    struct tump {
        int Kiri;
        int Kanan;
    } Tumpukan[MaxStack];

    int i, v = 1, j, L, R, x, ujung = 1;
    Tumpukan[1].Kiri = 0;
    Tumpukan[1].Kanan = MAX - 1;

    while (ujung != 0)
    {
        L = Tumpukan[ujung].Kiri;
        R = Tumpukan[ujung].Kanan;
        ujung--;

        while (R > L)
        {
            i = L;
            j = R;
            x = Data[(L + R) / 2];

            while (i <= j)
            {
                while (Data[i] < x)
                    i++;
                while (x < Data[j])
                    j--;
                if (i <= j)
                {
                    Tukar(&Data[i], &Data[j]);
                    i++;
                    j--;
                }

                cout << "\nData setelah iterasi ke " << v << endl;
                for (int k = 0; k < MAX; k++)
                {
                    cout << Data[k] << "\t";
                } v++;
            }

            if (L < i)
            {
                ujung++;
                Tumpukan[ujung].Kiri = i;
                Tumpukan[ujung].Kanan = R;
            }

            R = j;
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
        cout  << Data[i] << "\t";
    }

    QuickSortNonRekursif();

    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << Data[i] << "\t";
    }

    return 0;
}
