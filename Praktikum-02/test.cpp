#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head = NULL, *tail = NULL;
void addHead(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
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
void addNodeAfter(Node* prevNode, int data){ if (prevNode == nullptr){
  return;
}
    Node* newNode = new Node();
    newNode->data = data;
    if(prevNode->next == nullptr){
      prevNode->next = newNode;
      newNode->next = nullptr;
      tail = newNode;
    } else {
      prevNode->next = newNode;
    }
  }
void addNodeBefore(Node* NexNode, int data) {
  if (NexNode == nullptr) {
    return;
  }
  Node* newNode = new Node();
  newNode->data = data;
  if (NexNode == head) {
    newNode->next = head;
    head = newNode;
    return;
  }
  Node* current = head;
  while (current != nullptr && current->next != NexNode) {
    current = current->next;
  }
  if (current == nullptr) {
    return;
  }
  newNode->next = NexNode;
  current->next = newNode;
}
void printList() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void deleteNode(int data) {
  Node *current = head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->data == data) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      delete current;
      return;
    }
    previous = current;
    current = current->next;
  }
  cout << "Node not found" << endl;
}
void deleteFirstNode() {
  if (head != NULL) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}
void deleteLastNode() {
  if (head == NULL) {
    return;
  }
  if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }

  Node *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  delete current->next;
  current->next = NULL;
}
Node* searchNode(int data) {
  Node* current = head;
  while (current != NULL && current->data != data) {
    current = current->next;
  }
  return current;
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
int main() {
  addNode(10);
  addNode(20);
  addNode(30);
  addNode(40);

  cout << "Linked list: ";
  printList();

  deleteNode(10);
  cout << "After deleting 10: ";
  printList();

  deleteLastNode();
  cout << "After deleting the last node: ";
  printList();
   //Template for addNodeBefore 
  Node* B = searchNode(30);
  if (B != NULL) {
    addNodeAfter(B, 25);
  } else { cout << "Error TIdak bisa menemukan node";}
    Node* A = searchNode(25);
    if (A != NULL) {
      addNodeBefore(A, 11);
    } else { cout << "Error TIdak bisa menemukan node";}
  printList();
  return 0;
}