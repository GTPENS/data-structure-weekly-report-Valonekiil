#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int postfixEvaluate(string expn) {
    stack<int> stk;
    stringstream ss(expn);
    string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop();
            switch (token[0]) {
                case '+':
                    stk.push(num1 + num2);
                    break;
                case '-':
                    stk.push(num1 - num2);
                    break;
                case '*':
                    stk.push(num1 * num2);
                    break;
                case '/':
                    stk.push(num1 / num2);
                    break;
            }
        } else {
            stk.push(stoi(token));
        }
    }
    return stk.top();
}

int main() {
    string expn = "6 5 2 3 + 8 * + 3 + *";
    int value = postfixEvaluate(expn);
    cout << "Given Postfix Expn: " << expn << endl;
    cout << "Result after Evaluation: " << value << endl;
    return 0;
}
