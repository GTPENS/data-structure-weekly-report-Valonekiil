#include <iostream>
#include <cstdlib>
#define MAX 10

using namespace std;

int Data[MAX];
int temp[MAX];
int v = 1;
// Prosedur merge
void merge(int Data[], int temp[], int kiri, int tengah, int kanan)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = tengah - 1;
    tmp_pos = kiri;
    num_elements = kanan - kiri + 1;

    while ((kiri <= left_end) && (tengah <= kanan))
    {
        if (Data[kiri] <= Data[tengah])
        {
            temp[tmp_pos] = Data[kiri];
            tmp_pos = tmp_pos + 1;
            kiri = kiri + 1;
        }
        else
        {
            temp[tmp_pos] = Data[tengah];
            tmp_pos = tmp_pos + 1;
            tengah = tengah + 1;
        }
    }

    while (kiri <= left_end)
    {
        temp[tmp_pos] = Data[kiri];
        kiri = kiri + 1;
        tmp_pos = tmp_pos + 1;
    }

    while (tengah <= kanan)
    {
        temp[tmp_pos] = Data[tengah];
        tengah = tengah + 1;
        tmp_pos = tmp_pos + 1;
    }

    for (i = 0; i < num_elements; i++)
    {
        Data[kanan] = temp[kanan];
        kanan = kanan - 1;
    }

    // Tampilkan data setiap kali terjadi merge
    cout << "\nData setelah iterasi ke: "<< v <<endl;
    for (i = 0; i < MAX; i++)
    {
         cout << Data[i] << "\t";
    }v++;
}

// Prosedur membuat kumpulan data
void m_sort(int Data[], int temp[], int kiri, int kanan)
{
    int tengah;
    if (kanan > kiri)
    {
        tengah = (kanan + kiri) / 2;
        m_sort(Data, temp, kiri, tengah);
        m_sort(Data, temp, tengah + 1, kanan);
        merge(Data, temp, kiri, tengah + 1, kanan);
    }
}

void mergeSort(int Data[], int temp[], int array_size)
{
    m_sort(Data, temp, 0, array_size - 1);
}

int main()
{
    int i;
    //pembangkit bilangan random
    srand(0);
    //membangkitkan bilangan integer random
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = rand() % 100 + 1;
        cout << Data[i] << "\t";
    }

    mergeSort(Data, temp, MAX);
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
        cout << Data[i] << "\t";

    return 0;
}
