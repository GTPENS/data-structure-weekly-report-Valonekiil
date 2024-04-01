#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalancedParenthesis(string expn) {
    stack<char> stk;
    for (char ch : expn) {
        switch (ch) {
            case '{':
            case '[':
            case '(':
                stk.push(ch);
                break;
            case '}':
                if (stk.empty() || stk.top() != '{') {
                    return false;
                }
                stk.pop();
                break;
            case ']':
                if (stk.empty() || stk.top() != '[') {
                    return false;
                }
                stk.pop();
                break;
            case ')':
                if (stk.empty() || stk.top() != '(') {
                    return false;
                }
                stk.pop();
                break;
        }
    }
    return stk.empty();
}

int main() {
  char x = 'y';
  while(x == 'y') {
    string expn;
    cout << "\tpengecek keseimbangan kurung\nMasukan tanda kurung: ";
    cin >> expn;
    bool value = isBalancedParenthesis(expn);
    cout << "Input: " << expn << endl;
    cout << "Hasil setelah pengecekan: " << (value ? "Seimbang" : "Tidak seimbang") << endl;
    cout << "Apakah anda ingin mengulang program? (y/n) ";
    cin >> x;
    cin.ignore();
  }
}
