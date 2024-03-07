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
void addHead(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
int main()  {
  addNode(10);
  addNode(15);
  addNode(20);
  cout << "Data: "; printList();
  cout << "Masukan angka yang ingin dimasukan sebagai terakhir: ";
  int x;
  cin >> x;
  addNode(x);    
  cout << "Data: "; printList();
}