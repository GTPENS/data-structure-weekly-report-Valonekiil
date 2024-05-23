#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 10
using namespace std;

struct MSiswa {
    char Nama[50];
    int NIP;
};
int PB,PG;

void Tukar(MSiswa *a, MSiswa *b)
{
    MSiswa temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void BubbleSort(MSiswa Data[],bool sortByNama){
    int i,j,k;
    bool swapped;
    struct MSiswa temp;
    for (i = 0; i < MAX - 1; i++){
        swapped = false;
        for (j = 0; j < MAX - 1 - i; j++){
            if (sortByNama) {
                if (strcmp(Data[j].Nama, Data[j+1].Nama) > 0){
                    Tukar(&Data[j], &Data[j+1]);
                    swapped = true;
                }
            } else {
                if (Data[j].NIP > Data[j+1].NIP){
                    Tukar(&Data[j], &Data[j+1]);
                    swapped = true;
                }
            }
        }
        if (!swapped) break;
        cout << "Iterasi ke: " << i + 1 << endl;
        for (k = 0; k < MAX; k++){
            if (sortByNama) {
                cout << "Nama: " << Data[k].Nama << ", NIP: " << Data[k].NIP << "\n";
            } else {
                cout <<"NIP: " << Data[k].NIP << ", Nama: " << Data[k].Nama << endl ;
            }
        }
    }
};

void SShellSort(MSiswa Data[], bool sortByNama)
{
    int i,j,Jarak,t,v = 1,pb = 0,pg = 0;
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
                pb++;
                if (sortByNama)
                {
                    if (strcmp(Data[j].Nama, Data[i].Nama) > 0)
                    {
                        Tukar(&Data[j], &Data[i]);
                        pg++;
                        cout << "\nIterasi ke: " << v  <<"\tJarak: " << Jarak << endl;
                        for (t = 0; t < MAX; t++)
                            cout << "Nama: " << Data[t].Nama << ", NIP: " << Data[t].NIP << "\n";
                        v++;

                        sudah = false;
                    }
                }
                else
                {
                    if (Data[j].NIP > Data[i].NIP)
                    {
                        Tukar(&Data[j], &Data[i]);
                        pg++;
                        cout << "\nIterasi ke: " << v  <<"\tJarak: " << Jarak  << endl;
                        for (t = 0; t < MAX; t++)
                            cout << "NIP: " << Data[t].NIP << ", Nama: " << Data[t].Nama << "\n";
                        v++;
                        sudah = false;
                    }
                }
            }
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
        // Menyalin string nama
        string names[] = {"John Doe", "Jane Smith", "Michael Johnson", "Emily Brown", "David Lee", "Sarah Martinez", "Christopher Taylor", "Jessica Anderson", "Matthew Thomas", "Amanda Wilson"};
        strcpy(Data[i].Nama, names[i].c_str());
        // Membuat NIP acak
        Data[i].NIP = rand() % 5000 + 2000;
        cout << "Nama: " << Data[i].Nama << ", NIP: " << Data[i].NIP << endl;
    }

    // Memilih metode pengurutan
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Short Shell Sort\n";
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
        BubbleSort(Data, sortByNama);
        break;
    case 2:
        SShellSort(Data, sortByNama);
        break;
    default:
        cout << "Pilihan tidak valid. Menggunakan Bubble Sort secara default.\n";
        BubbleSort(Data, sortByNama);
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
