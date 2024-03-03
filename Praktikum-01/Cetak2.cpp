#include <iostream>
using namespace std;

struct date {
    int month;
    int day;
    int year;
};

void cetak_tanggal(const date&);

int main()
{
    date today;
    cout << "Enter the current day (dd): ";
    cin >> today.day ;
    cout << "Enter the current month (mm): ";
    cin >> today.month;
    cout << "Enter the current year (yyyy): ";
    cin >> today.year;
    cetak_tanggal(today);
    return 0;
}

void cetak_tanggal(const date& now)
{
    const char* nama_bulan[] = {
        "Wrong month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    cout << "Todays date is " << nama_bulan[now.month] << " " << now.day << ", " << now.year << endl << endl;
}