#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head = NULL, *tail = NULL;

void addNode(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}
void printList() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void cariData(int data) {
  Node* cari = head;
  bool ditemukan = false;
  while (cari != nullptr) {
    if (cari->data == data) {
      cout << "Data ditemukan: " << "\n:" << cari->data << endl;
      ditemukan = true;
      break;
    }
    cari = cari->next;
  }
  if (!ditemukan) {
    cout << "Data tidak ditemukan." << endl;
  }
}
int main()  {
  addNode(10);
  addNode(15);
  addNode(20);
  cout << "Data: "; printList();
  cout << "Masukan angka yang ingin dicari: ";
  int x;
  cin >> x;
  cariData(x);
}