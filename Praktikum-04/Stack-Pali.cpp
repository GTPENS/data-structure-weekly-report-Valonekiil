#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Palindrome(string str) {
    stack<char> charStack;
    int length = str.length();
    for (int i = 0; i < length / 2; ++i) {
        charStack.push(str[i]);
    }   
    int i = (length % 2 == 0) ? length / 2 : length / 2 + 1;
    while (i < length) {
        if (charStack.empty() || charStack.top() != str[i]) {
            return false;
        }
        charStack.pop();
        ++i;
    } return true;
}

int main() {
    string v; char x = 'y'; bool y;
    while (x == 'y'){
      cout << "Masukan kata: ";
      getline(cin, v);
      y = Palindrome(v);
      cout << "Kata " << v << " Adalah " << (y ? "Palindrom" : "Bukan Palindrom") << endl;
      cout << "Apakah anda ingin mengulang program? (y/n) ";
      cin >> x;
      cin.ignore();
    }
    return 0;
}