#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string expn) {
    stack<char> stk;
    string output = "";
    char temp;
    for (char ch : expn) {
        if (ch >= '0' && ch <= '9') {
            output += ch;
        } else {
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                        temp = stk.top();
                        stk.pop();
                        output += " ";
                        output += temp;
                    }
                    stk.push(ch);
                    output += " ";
                    break;
                case '(':
                    stk.push(ch);
                    break;
                case ')':
                    while (!stk.empty() && (temp = stk.top()) != '(') {
                        stk.pop();
                        output += " ";
                        output += temp;
                        output += " ";
                    }
                    stk.pop();
                    break;
            }
        }
    }
    while (!stk.empty()) {
        temp = stk.top();
        stk.pop();
        output += " ";
        output += temp;
    }
    return output;
}

int main() {
  char x = 'y';  string expn;
  while(x == 'y') {
    cout << "\tMerubah infix menjadi postfix \nMasukkan ekspresi matematika: ";
    cin >> expn;
    string value = infixToPostfix(expn);
    cout << "Infix Expn: " << expn << endl;
    cout << "Postfix Expn: " << value << endl;
    cout << "Apakah anda ingin mengulang program? (y/n) ";
    cin >> x;
    cin.ignore();
  }
}
