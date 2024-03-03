#include <iostream>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

void input_date(date &d) {
    cout << "Masukkan tanggal: ";
    cin >> d.day; 
    cout << "Masukan Bulan: ";
    cin >> d.month;
    cout << "Masukan Tahun: ";
    cin >> d.year;
}

int main() {
    const int num_dates = 5;
    date dates[num_dates];

    for (int i = 0; i < num_dates; i++) {
        cout << "Masukkan tanggal ke-" << (i + 1) << ":" << endl;
        input_date(dates[i]);
    }

    cout << "Tanggal yang telah dimasukkan:" << endl;
    for (int i = 0; i < num_dates; i++) {
        cout << "Tanggal ke-" << (i + 1) << ": " << dates[i].day << " " << dates[i].month << " " << dates[i].year << endl;
    }

    return 0;
}