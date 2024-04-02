#include <iostream>
#include <stack>

using namespace std;

stack<int> stk1;
stack<int> stk2;

void add(int value) {
    stk1.push(value);
}

int remove() {
    int value;
    if (!stk2.empty()) {
        value = stk2.top();
        stk2.pop();
        return value;
    }
    while (!stk1.empty()) {
        value = stk1.top();
        stk1.pop();
        stk2.push(value);
    }
    value = stk2.top();
    stk2.pop();
    return value;
}

int main() {
    add(1);
    add(2);
    add(3);
    cout << remove() << endl;
    add(4);
    cout << remove() << endl;
}
