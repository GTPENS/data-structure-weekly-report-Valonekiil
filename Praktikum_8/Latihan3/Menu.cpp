#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 10
#define MaxStack 10

using namespace std;

struct MSiswa {
    char Nama[50];
    int NIP;
};

void Tukar(MSiswa *a, MSiswa *b)
{
    MSiswa temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSortNonRekursif(MSiswa Data[], bool sortByNama)
{
    struct tump {
        int Kiri;
        int Kanan;
    } Tumpukan[MaxStack];

    int i, j, L, R, ujung = 1;
    MSiswa pivot;
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
            pivot = Data[(L + R) / 2];

            while (i <= j)
            {
                if (sortByNama) {
                    while (strcmp(Data[i].Nama, pivot.Nama) < 0)
                        i++;
                    while (strcmp(Data[j].Nama, pivot.Nama) > 0)
                        j--;
                } else {
                    while (Data[i].NIP < pivot.NIP)
                        i++;
                    while (Data[j].NIP > pivot.NIP)
                        j--;
                }

                if (i <= j)
                {
                    Tukar(&Data[i], &Data[j]);
                    i++;
                    j--;
                }
            }

            if (L < i)
            {
                ujung++;
                Tumpukan[ujung].Kiri = i;
                Tumpukan[ujung].Kanan = R;
            }

            R = j;
        }

        // Menampilkan data setelah setiap perubahan
        cout << "Perubahan pada data:" << endl;
        for (int v = 0; v < MAX; v++)
        {
            if (sortByNama)
                cout << "Nama: " << Data[v].Nama << ", NIP: " << Data[v].NIP << "\n";
            else
                cout << "NIP: " << Data[v].NIP << ", Nama: " << Data[v].Nama << "\n";
        }
        cout << endl;
    }
}

void QuickSortRekursif(MSiswa Data[], int L, int R, bool sortByNama)
{
    int i, j;
    MSiswa pivot;
    pivot = Data[(L + R) / 2];
    i = L;
    j = R;

    while (i <= j)
    {
        if (sortByNama) {
            while (strcmp(Data[i].Nama, pivot.Nama) < 0)
                i++;
            while (strcmp(Data[j].Nama, pivot.Nama) > 0)
                j--;
        } else {
            while (Data[i].NIP < pivot.NIP)
                i++;
            while (Data[j].NIP > pivot.NIP)
                j--;
        }

        if (i <= j)
        {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }

    if (L < j)
        QuickSortRekursif(Data, L, j, sortByNama);
    if (i < R)
        QuickSortRekursif(Data, i, R, sortByNama);

    // Menampilkan data setelah setiap perubahan
    cout << "Perubahan pada data:" << endl;
    for (int v = 0; v < MAX; v++)
    {
        if (sortByNama)
            cout << "Nama: " << Data[v].Nama << ", NIP: " << Data[v].NIP << "\n";
        else
            cout << "NIP: " << Data[v].NIP << ", Nama: " << Data[v].Nama << "\n";
    }
    cout << endl;
}

void merge(MSiswa Data[], MSiswa temp[], int kiri, int tengah, int kanan, bool sortByNama)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = tengah - 1;
    tmp_pos = kiri;
    num_elements = kanan - kiri + 1;

    while ((kiri <= left_end) && (tengah <= kanan))
    {
        if (sortByNama ? (strcmp(Data[kiri].Nama, Data[tengah].Nama) <= 0) : (Data[kiri].NIP <= Data[tengah].NIP))
        {
            temp[tmp_pos] = Data[kiri];
            tmp_pos++;
            kiri++;
        }
        else
        {
            temp[tmp_pos] = Data[tengah];
            tmp_pos++;
            tengah++;
        }
    }

    while (kiri <= left_end)
    {
        temp[tmp_pos] = Data[kiri];
        kiri++;
        tmp_pos++;
    }

    while (tengah <= kanan)
    {
        temp[tmp_pos] = Data[tengah];
        tengah++;
        tmp_pos++;
    }

    for (i = 0; i < num_elements; i++)
    {
        Data[kanan] = temp[kanan];
        kanan--;
    }

    // Menampilkan data setelah setiap perubahan
    cout << "Perubahan pada data:" << endl;
    for (int v = 0; v < MAX; v++)
    {
        if (sortByNama)
            cout << "Nama: " << Data[v].Nama << ", NIP: " << Data[v].NIP << "\n";
        else
            cout << "NIP: " << Data[v].NIP << ", Nama: " << Data[v].Nama << "\n";
    }
    cout << endl;
}

void m_sort(MSiswa Data[], MSiswa temp[], int kiri, int kanan, bool sortByNama)
{
    int tengah;
    if (kanan > kiri)
    {
        tengah = (kanan + kiri) / 2;
        m_sort(Data, temp, kiri, tengah, sortByNama);
        m_sort(Data, temp, tengah + 1, kanan, sortByNama);
        merge(Data, temp, kiri, tengah + 1, kanan, sortByNama);
    }
}

void mergeSort(MSiswa Data[], MSiswa temp[], int array_size, bool sortByNama)
{
    m_sort(Data, temp, 0, array_size - 1, sortByNama);
}

int main()
{
    int i;
    srand(0);
    MSiswa Data[MAX];
    MSiswa temp[MAX];

    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        string names[] = {"John Doe", "Jane Smith", "Michael Johnson", "Emily Brown", "David Lee", "Sarah Martinez", "Christopher Taylor", "Jessica Anderson", "Matthew Thomas", "Amanda Wilson"};
        strcpy(Data[i].Nama, names[i].c_str());
        // Membuat NIP acak
        Data[i].NIP = rand() % 5000 + 2000;
        cout << "Nama: " << Data[i].Nama << ", NIP: " << Data[i].NIP << endl;
    }

    cout << "Pilih metode pengurutan:\n";
    cout << "1. Quick Sort Non-Rekursif\n";
    cout << "2. Quick Sort Rekursif\n";
    cout << "3. Merge Sort\n";
    int choice;
    cin >> choice;

    cout << "Pilih kriteria pengurutan:\n";
    cout << "1. Nama\n";
    cout << "2. NIP\n";
    int sortCriteria;
    cin >> sortCriteria;
    bool sortByNama = (sortCriteria == 1);

    cout << "Pilih Tipe pengurutan:\n";
    cout << "1. Ascendent\n";
    cout << "2. Descendent\n";
    int sortOrder;
    cin >> sortOrder;
    bool sortDescend = (sortOrder == 2);

    switch (choice)
    {
    case 1:
        QuickSortNonRekursif(Data, sortByNama);
        break;
    case 2:
        QuickSortRekursif(Data, 0, MAX - 1, sortByNama);
        break;
    case 3:
        mergeSort(Data, temp, MAX, sortByNama);
        break;
    default:
        cout << "Pilihan tidak valid. Menggunakan Quick Rekursif secara default.\n";
        QuickSortRekursif(Data, 0, MAX - 1, sortByNama);
    }
    if (sortDescend){
        for (i = 0; i < MAX/2; i++)
            Tukar(&Data[i], &Data[MAX - i - 1]);}
    // Menampilkan data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        if (sortByNama)
            cout << "Nama: " << Data[i].Nama << ", NIP: " << Data[i].NIP << endl;
        else
            cout << "NIP: " << Data[i].NIP << ", Nama: " << Data[i].Nama << endl;
    }

    return 0;
}
