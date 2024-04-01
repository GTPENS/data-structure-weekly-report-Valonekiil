#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int v, node *x): data(v), next(x) {}
};
node *top = NULL; int ukr = 0;
void push(int v){
    top = new node(v, top);
    ukr++;
}
int pop(){
    if(top == NULL){
      throw runtime_error("Stack kosong");
    } else{
      int r = top->data;
      node *temp = top;
      top = top->next;
      delete temp;
      ukr--;
      return r;
    }
}
void print(){
  node *temp = top; cout <<"isi stack:";
  while(temp != NULL){
    cout << "<-" << temp->data;
    temp = temp->next;
  }
}
int checkSize(){
  return ukr;
}
bool kosong(){
  return ukr == 0;
}
int cekHead(){
  if(top == NULL){
    throw runtime_error("Stack kosong");
  } return top->data;
}
void pushtail(int v){
  if(kosong()){
    push(v);
  }else{
    int temp = pop();
    pushtail(v);
    push(temp);
  }
}
int main(){
  int pilihan, x;
  do{print(); if(kosong()){} else {int s = checkSize(); cout << "\tJumlah data: " << s << endl;}
    cout << "\nMenu Operasi Stack:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. PushAtBottom\n";
    cout << "5. Exit\n";
    cin >> pilihan;
    cin.ignore();
     switch (pilihan){
       case 1: cout << "Masukkan data yang ingin dimasukan: ";
       cin >> x;
       push(x);
       break;
       case 2: cout << "Data yang di pop: " << pop() << endl; break;
       case 3: cout << "Data yang di peek: " << cekHead() << endl; break;
       case 4: cout << "Masukkan data yang ingin dimasukan: ";
       cin >> x;
       pushtail(x);
       break;
       default:
       if(pilihan>5){
         cout<<"Masukan pilihan yang benar\n";
       }break;
     }
  } while (pilihan != 5); return 0;
};