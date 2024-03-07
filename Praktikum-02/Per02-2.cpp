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
int main()  {
  addNode(10);
  addNode(15);
  addNode(20);
  addNode(25);
  addNode(30);
  cout << "Data: "; printList();
}