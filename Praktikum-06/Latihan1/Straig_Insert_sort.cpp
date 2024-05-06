#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];

void StraightInsertSort() {
    int i, j, x,v;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
        //Untuk menampilkan data setelah setiap iterasi terpanggil
        cout << "\nPerubahan pada data dalam iterasi ke "<< i << "\n";
        for (v = 0; v < MAX; v++){
            cout << Data[v] << " \t";
    }
    }
}

int main() {
    int i;
    srand(0);

    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() %100 + 1;
        cout << Data[i] << "\t";
    }

    StraightInsertSort();

    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << Data[i] << "\t";
    }

    return 0;
}
