#include <iostream>
using namespace std;

void tukar_xy(int *, int *);

int main()
{
    struct koordinat {
        int x;
        int y;
    } posisi;
    cout << "Masukkan koordinat posisi (x) : ";
    cin >> posisi.x;
    cout << "Masukkan koordinat posisi (y) : ";
    cin >> posisi.y;
    cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;
    tukar_xy(&posisi.x, &posisi.y);
    cout << "x, y sekarang = " << posisi.x << ", " << posisi.y << endl;
    return 0;
}

void tukar_xy(int *a, int *b)
{
    int z;
    z = *a;
    *a = *b;
    *b = z;
}