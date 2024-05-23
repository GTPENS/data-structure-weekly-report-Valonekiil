#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

int Data[MAX];
int pg = 0, pb = 0, PG, PB;
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(){
    int i,j,k;
    for (i = 0; i < MAX - 1; i++){
        for (j = i + 1; j < MAX; j++){
            pb++;
            if (Data[i] > Data[j]){
                Tukar(&Data[i], &Data[j]);
                pg++;
                }
            }
        cout << "Iterasi ke: " << i + 1 << "\tPerbandingan:"<< pb << "\tPergeseran:" << pg << endl;
        for (k = 0; k < MAX; k++){
            cout << Data[k] << "\t";}
        cout << endl;
        PB+=pb; PG+=pg; pg = 0; pb = 0;
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

    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << Data[i] << "\t";
    }
    cout <<"\nTotal Perbandingan: "<<PB<<"\nTotal Pergeseran  : "<< PG ;
    return 0;
}