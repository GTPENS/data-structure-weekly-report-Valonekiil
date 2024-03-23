#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};

Node *head = NULL, *tail = NULL;

void addHead(int data){
    Node* newNode = new Node();
    if (head == NULL && tail == NULL){ 
        head = newNode; 
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
    } else if (head == NULL && tail != NULL){
        head = newNode;
        newNode->data = data;
        newNode->next = tail;
        newNode->prev = NULL;
        tail->prev = newNode;
    } else if (head != NULL && tail == NULL){
      newNode->data = data;
      newNode->next = head;
      head->prev = newNode;
      tail = head;
      head = newNode;
    } else {
      newNode->data = data;
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
}
void addTail(int data) {
   Node *newNode = new Node();
  if (head == NULL && tail == NULL){
    tail = newNode;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
  } else if ( head != NULL && tail == NULL){
    tail = newNode;
    newNode->data = data;
    newNode->prev = head;
    newNode->next = NULL;
    head->next = newNode;
  } else if (head == NULL && tail != NULL){
    newNode->data = data;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    head = tail;
    tail = newNode;
  } else{
    newNode->data = data;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}
void addNodeAfter(Node* prevNode, int data){
    Node* newNode = new Node();
    newNode->data = data;
    if(prevNode == tail){
      prevNode->next = newNode;
      newNode->prev = prevNode;
      newNode->next = NULL;
      tail = newNode;
    } else {
      Node *Temp = prevNode->next;
      prevNode->next = newNode;
      newNode->prev = prevNode;
      newNode->next = Temp;
      Temp->prev = newNode;
    }
  }
void addNodeBefore(Node* NextNode, int data){
  Node* newNode = new Node();
  newNode->data = data;
  if(NextNode == head) {
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
  } else {
    Node* Temp = NextNode->prev;
    Temp->next = newNode;
    newNode->prev = Temp;
    newNode->next = NextNode;
    NextNode->prev = newNode;
  }
}
void FiFo() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  } cout << endl;
}
void LiFo(){
  Node *temp = tail;
  while (temp != NULL){
    cout << temp->data << " ";
    temp = temp->prev;
  } cout << endl;
}
void deleteNode(int data) {
  Node *current = head;

  while (current != NULL) {
    if (current->data == data) {
      if (current == head) {
        head = current->next;
        if (head != NULL)
          head->prev = NULL;
        delete current;
        return;
      } else if (current == tail) {
        tail = current->prev;
        if (tail != NULL)
          tail->next = NULL;
        delete current;
        return;
      } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        return;
      }
    }
    current = current->next;
  }
  cout << "Node not found" << endl;
}
void deleteHead() {
  if (head != NULL) {
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
  } else {
    cout << "Head not found" << endl;
  }
}
void deleteTail() {
  if (tail != NULL) {
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
  } else {
    cout << "Tail not found" << endl;
  }
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
  int x, pilihan;
do {
  cout << "\nMenu Operasi Linked List:\n";
  cout << "1.  Memasukan Data sebagai Head\n";
  cout << "2.  Memasukan Data sebagai Tail\n";
  cout << "3.  Mencari Node Tertentu\n";
  cout << "4.  Menampilkan Linked List dengan metode FiFo\n";
  cout << "5.  Menampilkan Linked List dengan metode LiFo\n";
  cout << "6.  Menghapus Node Tertentu\n";
  cout << "7.  Menghapus Head\n";
  cout << "8.  Menghapus Tail\n";
  cout << "9.  Menambahkan Data setelah Node tertentu\n";
  cout << "10. Menambahkan Data sebelum Node tertentu\n";
  cout << "11. Mengakhiri Program\n";
  cout << "Masukkan pilihan: ";
      cin >> pilihan;
        switch (pilihan) {
            case 1:
            cout <<"Masukan Data yang ingin dimasukan: ";
            cin >> x;
            addHead(x);
            cin.ignore();
            break;
        case 2: cout<<"Masukan Data yang ingin dimasukan:";
            cin >> x;
            addTail(x);
            cin.ignore();
            break;
        case 3:
            cout << "Masukkan Data yang ingin dicari: ";
            cin >> x;
            cariData(x);
            break;
        case 4:cout<<"Data:";
            FiFo();
            break;
        case 5:cout<<"Data:";
            LiFo();
            break;
        case 6:cout<< "Masukan Data yang ingin dihapus: ";
            cin >> x;
            deleteNode(x);
            break;
        case 7:
            deleteHead();
            break;
        case 8:
            deleteTail();
            break;
        case 9:cout<<"Masukan Node yang berada di list: ";
            cin >> x;
          if (searchNode(x) != NULL){
            Node *target = searchNode(x);
            cout << "Masukan Node yang akan di tambahkan setelah node "<< x <<": ";
            cin >> x;
            addNodeAfter(target, x);
            break;}
          else {
            cout << "Node tidak ditemukan." << endl;
            break;
          }
          case 10:cout<<"Masukan Node yang berada di list: ";
            cin >> x;
          if (searchNode(x) != NULL){
              Node *target = searchNode(x);
            cout << "Masukan Node yang akan di tambahkan Sebelum node "<< x <<": ";
            cin >> x;
            addNodeBefore(target, x);
            break;}
          else {
            cout << "Node tidak ditemukan." << endl;
            break;
          }
        case 11:
            cout << "Terima kasih telah menggunakan program ini.\n"; 
            break;
        default: 
            if (pilihan > 11) {
                cout << "Pilihan tidak valid! Masukkan angka 1-11.\n";
            }
            else {
                cout << "Pilihan tidak valid!\n";
            }
            break;
        } 

    } while (pilihan != 11);
  return 0;
}