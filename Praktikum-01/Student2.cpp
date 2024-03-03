#include <iostream>
#include <string>
using namespace std;

#define MAKS 20

struct date {
    int month;
    int day;
    int year;
};

struct student {
    string name;
    date birthday;
};

int main()
{
    student data_mhs[MAKS];
    int i = 0, sudah_benar, jml;
    char lagi;
    do
    {
        cout << "Name : ";
        getline(cin, data_mhs[i].name);
        cout << "Birthday (mm-dd-yyyy): ";
        cin >> data_mhs[i].birthday.month >> data_mhs[i].birthday.day >> data_mhs[i].birthday.year;
        cout << "\n";
        i++;
        cout << "Mau memasukkan data lagi [Y/T] ? ";
        do
        {
            lagi = getchar(); 
            sudah_benar = (lagi == 'Y') || (lagi == 'y') || (lagi == 'T') || (lagi == 't');
        } while (!sudah_benar);
        cin.ignore();
        cout << "\n";
    } while (lagi == 'Y' || lagi == 'y');
    jml = i;
    cout << "DATA SISWA\n";
    for (i = 0; i < jml; i++)
    {
        cout << i + 1 << ". Name : " << data_mhs[i].name << endl;
        cout << " Birthday : " << data_mhs[i].birthday.month << "-" << data_mhs[i].birthday.day << "-" << data_mhs[i].birthday.year << endl;
    }
    return 0;
}