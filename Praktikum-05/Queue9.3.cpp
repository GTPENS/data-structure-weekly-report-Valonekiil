#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v, Node* n) : value(v), next(n) {}
};

Node* head = nullptr;
Node* tail = nullptr;
int count = 0;

void add(int value) {
    Node* temp = new Node(value, nullptr);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}
int size() {
    return count;
}

bool isEmpty() {
    return count == 0;
}

void print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int peek() {
    if (isEmpty()) {
        throw "QueueEmptyException";
    }
    return head->value;
}
int main(){
  char x = 'y'; int v;
  while (x == 'y'){
    cout << "\tMenambahkan data ke dalam antrian\ninput: ";
    cin >> v;
    add(v);
    cout << "Antrian saat ini: " << endl; print();
    cout << "\nApakah anda ingin mengulang program? (y/n) ";
    cin >> x;
    cin.ignore();
  }
}