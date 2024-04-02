#include <iostream>
#include <queue>

using namespace std;

queue<int>que1;
queue<int>que2;

void add(int value) {
    que1.push(value);
}

void remove(){
  if(que1.empty()){ cout<<"Stack Kosong\n"; return;}  
  int v, pjg = que1.size();
  for (int i = 1; i < pjg ; i++){
    v = que1.front();
    que1.pop();
    que2.push(v);
  } v = que1.front();
  cout <<"Data yang di pop: " << v << endl;
  que1.pop();
  pjg = que2.size();
  for (int i = 0; i < pjg; i++){
    v = que2.front();
    que2.pop();
    que1.push(v);
  }
}
int main(){
  int x,v = 1; 
  while (v == 1){
      cout << "\t Menu Stack dengan Queue\n1.Push\n2.Pop\n3.Exit\ninput: ";
      cin >> x;
      switch (x){
        case 1: cout << "Masukan data: "; cin >> x; add(x); break;
        case 2: remove(); break;
        case 3: v = 2; break;
        default:
        cout << "Input salah! masukan 1 sampai 3\n";
      }
  }
  return 0;
}\
