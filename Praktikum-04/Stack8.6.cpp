#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string InfixToPrefix(string expn);

void ReplaceParenthesis(char a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (a[i] == '(')
            a[i] = ')';
        else if (a[i] == ')')
            a[i] = '(';
    }
}

void ReverseString(char expn[], int length)
{
    int lower = 0;
    int upper = length - 1;
    char tempChar;
    while (lower < upper)
    {
        tempChar = expn[lower];
        expn[lower++] = expn[upper];
        expn[upper--] = tempChar;
    }
}

char* InfixToPostfix(char expn[])
{
    return expn;
}

string InfixToPrefix(string expn)
{
    char* arr = new char[expn.length() + 1];
    strcpy(arr, expn.c_str());
    ReverseString(arr, expn.length());
    ReplaceParenthesis(arr, expn.length());
    arr = InfixToPostfix(arr);
    ReverseString(arr, expn.length());
    string result(arr);
    delete[] arr;
    return result;
}

int main() {
    char x = 'y';  string expn;
    while(x == 'y') { 
        cout <<"\tMengubah infix menajdi Prefix\nMasukkan ekspresi matematika: ";
        cin >> expn ;
        string value = InfixToPrefix(expn);
        cout << "Infix Expn: " << expn << endl;
        cout << "Prefix Expn: " << value << endl;
        cout << "Apakah anda ingin mengulang program? (y/n) ";
        cin >> x;
        cin.ignore();
    }
    return 0;
}
