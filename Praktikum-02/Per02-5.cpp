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
void addHead(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
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
      cout << "Data ditemukan: " << "\n" << cari->data << endl;
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
  int x,pilihan;
  addNode(10);
  addNode(15);
  addNode(20);
  cout << "Data: "; printList();
do {
        cout << "\nMenu Operasi Linked List:\n";
        cout << "1. Memasukan Data sebagai Head\n";
        cout << "2. Memasukan Data sebagai Tail\n";
        cout << "3. Mencari Data Tertentu\n";
        cout << "4. Menampilkan Linked List\n";
        cout << "5. Mengakhiri Program\n";
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
            addNode(x);
            cin.ignore();
            break;
        case 3:
            cout << "Masukkan Data yang ingin dicari: ";
            cin >> x;
            cariData(x);
            break;
        case 4:cout<<"Data:";
            printList();
            break;
        case 5:
            cout << "Program Berakhir\n"; 
            break;
        default: 
            if (pilihan > 5) {
                cout << "Pilihan tidak valid! Masukkan angka 1-5\n";
            }
            else {
                cout << "Pilihan tidak valid!\n";
            }
            break;
        } 

    } while (pilihan != 5);
}