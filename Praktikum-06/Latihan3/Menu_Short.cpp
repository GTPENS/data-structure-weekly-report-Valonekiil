#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 10
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

void InsertionSort(MSiswa Data[], bool sortByNama)
{
    int i, j, v;
    MSiswa x;
    for (i = 1; i < MAX; i++)
    {
        x = Data[i];
        j = i - 1;
        if (sortByNama) {
            while (j >= 0 && strcmp(x.Nama, Data[j].Nama) < 0)
            {
                Data[j + 1] = Data[j];
                j--;
            }
        } else {
            while (j >= 0 && x.NIP < Data[j].NIP)
            {
                Data[j + 1] = Data[j];
                j--;
            }
        }
        Data[j + 1] = x;
        // Untuk menampilkan data setelah setiap iterasi terpanggil
        cout << "\nPerubahan pada data dalam iterasi ke " << i << "\n";
        for (v = 0; v < MAX; v++)
        {
            if (sortByNama)
                cout << "Nama: " << Data[v].Nama << ", NIP: " << Data[v].NIP << "\t";
            else
                cout << "NIP: " << Data[v].NIP << ", Nama: " << Data[v].Nama << "\t";
        }
    }
}

void SelectionSort(MSiswa Data[], bool sortByNama)
{
    int i, j, k, v, c;
    c = 1;
    for (i = 0; i < MAX - 1; i++)
    {
        c = 1 + i;
        k = i;
        for (j = i + 1; j < MAX; j++)
            if (sortByNama ? (strcmp(Data[k].Nama, Data[j].Nama) > 0) : (Data[k].NIP > Data[j].NIP))
                k = j;
        Tukar(&Data[i], &Data[k]);
        // Untuk menampilkan data setelah setiap iterasi terpanggil
        cout << "\nPerubahan pada data setelah iterasi ke " << c << endl;
        for (v = 0; v < MAX; v++)
        {
            if (sortByNama)
                cout << "Nama: " << Data[v].Nama << ", NIP: " << Data[v].NIP << "\t";
            else
                cout << "NIP: " << Data[v].NIP << ", Nama: " << Data[v].Nama << "\t";
        }
    }
}

void BinaryInsertSort(MSiswa Data[], bool sortByNama)
{
    int i, j, l, r, m, v;
    MSiswa x;
    for (i = 1; i < MAX; i++)
    {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (sortByNama ? (strcmp(x.Nama, Data[m].Nama) < 0) : (x.NIP < Data[m].NIP))
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
        // Untuk menampilkan data setelah setiap iterasi terpanggil
        cout << "\nIterasi ke " << i << endl;
        for (v = 0; v < MAX; v++)
        {
            if (sortByNama)
                cout << "Nama: " << Data[v].Nama << ", NIP: " << Data[v].NIP << "\t";
            else
                cout << "NIP: " << Data[v].NIP << ", Nama: " << Data[v].Nama << "\t";
        }
    }
}

int main()
{
    int i;
    srand(0);
    MSiswa Data[MAX];

    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        // Menyalin string nama secara acak
        string names[] = {"John Doe", "Jane Smith", "Michael Johnson", "Emily Brown", "David Lee", "Sarah Martinez", "Christopher Taylor", "Jessica Anderson", "Matthew Thomas", "Amanda Wilson"};
        strcpy(Data[i].Nama, names[i].c_str());
        // Membuat NIP acak
        Data[i].NIP = rand() % 5000 + 2000;
        cout << "Nama: " << Data[i].Nama << ", NIP: " << Data[i].NIP << endl;
    }

    // Memilih metode pengurutan
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Binary Insert Sort\n";
    int choice;
    cin >> choice;

    // Memilih kriteria pengurutan
    cout << "Pilih kriteria pengurutan:\n";
    cout << "1. Nama\n";
    cout << "2. NIP\n";
    int sortCriteria;
    cin >> sortCriteria;
    bool sortByNama = (sortCriteria == 1);
    // Menampilkan secara Ascendent atau Descendent
    cout << "Pilih Tipe pengurutan:\n";
    cout << "1. Ascendent\n";
    cout << "2. Descendent\n";
    int sortOrder;
    cin >> sortOrder;
    bool sortDescend = (sortOrder == 2);

    if (sortOrder > 2 || sortOrder< 1)
        cout << "Pilihan tidak valid. Menggunakan Ascendent secara default.\n";
    if (sortCriteria > 2 || sortCriteria< 1)
        cout << "Pilihan tidak valid. Menggunakan NIP secara default.\n";
    
    // Melakukan pengurutan sesuai pilihan pengguna
    switch (choice)
    {
    case 1:
        InsertionSort(Data, sortByNama);
        break;
    case 2:
        SelectionSort(Data, sortByNama);
        break;
    case 3:
        BinaryInsertSort(Data, sortByNama);
        break;
    default:
        cout << "Pilihan tidak valid. Menggunakan Insertion Sort secara default.\n";
        InsertionSort(Data, sortByNama);
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
