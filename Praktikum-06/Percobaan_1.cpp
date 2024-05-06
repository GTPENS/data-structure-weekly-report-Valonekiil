#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];

// Fungsi pengurutan straight sort
void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main() {
    int i;
    srand(0);

    // Menampilkan data dengan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    StraightInsertSort();

    // Data setelah terurut
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
