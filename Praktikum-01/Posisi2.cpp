#include <iostream>
using namespace std;
struct koordinat
{
    int x;
    int y;
};
void tukar_xy(koordinat*);
int main()
{
    koordinat posisi;
    cout << "Masukkan koordinat posisi x: ";
    cin >> posisi.x;
    cout << "Masukkan koordinat posisi y: ";
    cin >> posisi.y;
    cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;
    tukar_xy(&posisi);
    cout << "x, y sekarang = " << posisi.x << ", " << posisi.y << endl;
    return 0;
}
void tukar_xy(koordinat*& pos_xy)
{
    int z;
    z = pos_xy->x;
    pos_xy->x = pos_xy->y;
    pos_xy->y = z;
}