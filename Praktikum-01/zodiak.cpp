#include <iostream>
using namespace std;

struct zodiak {
    string nama;
    int tgl_awal;
    int bln_awal;
    int tgl_akhir;
    int bln_akhir;
};

int main()
{
    zodiak bintang = {"Sagitarius", 22, 11, 21, 12};
    int tgl_lhr, bln_lhr, thn_lhr;
    cout << "Masukkan tgl lahir Anda (XX-XX-XXXX): ";
    cin >> tgl_lhr >> bln_lhr >> thn_lhr;
    if((tgl_lhr >= bintang.tgl_awal && bln_lhr == bintang.bln_awal) || (tgl_lhr <= bintang.tgl_akhir && bln_lhr == bintang.bln_akhir))
        cout << "Bintang Anda adalah " << bintang.nama << endl;
    else
        cout << "Bintang Anda bukan " << bintang.nama << endl;
    return 0;
}