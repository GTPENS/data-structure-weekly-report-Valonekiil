#include <iostream>
#include <string>
using namespace std;

void cetak_tanggal(int mm, int dd, int yy);

int main()
{
    struct date {
        int month;
        int day;
        int year;
    } today;
    cout << "Enter the current day (dd): ";
    cin >> today.day ;
    cout << "Enter the current month (mm): ";
    cin >> today.month;
    cout << "Enter the current year (yyyy): ";
    cin >> today.year;
    cetak_tanggal(today.month, today.day, today.year);
    return 0;
}

void cetak_tanggal(int mm, int dd, int yy)
{
    static const char *nama_bulan[] = {
        "Wrong month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    cout << "Todays date is " << nama_bulan[mm] << " " << dd << ", " << yy << endl << endl;
}