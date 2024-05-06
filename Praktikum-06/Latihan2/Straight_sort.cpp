#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];
int g,G;//Untuk menghitung penggeseran
int b,B;//Untuk menghitung perbandingan

void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            b++;
            Data[j + 1] = Data[j];
            j--;
            g++;
        }
        
        Data[j + 1] = x;
        cout << "\nPada Iterasi ke " << i << " Terdapat " << g << " Penggeseran dan " << b << " Perbandingan"<< endl;
        for (int v = 0; v < MAX; v++)
            {
                cout << Data[v] << "\t";
            }
        G += g; B += b; b = 0; g = 0;
        if (i + 1 == MAX){
            cout << "\nTotal pergeseran : " << G << "\nTotal perbandingan : " << B << endl;
        }
    }
}

int main() {
    int i;
    srand(0);

    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
        cout << Data[i] << "\t";
    }

    StraightInsertSort();

    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
       cout << Data[i] << "\t";
    }

    return 0;
}
