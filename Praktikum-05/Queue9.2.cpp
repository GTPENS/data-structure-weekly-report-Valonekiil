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
