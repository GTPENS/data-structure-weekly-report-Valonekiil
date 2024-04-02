#include <iostream>
#include <stack>

using namespace std;

void reverseStack(stack<int>& stk){
  stack<int> temp; int pjg = stk.size();
  for (int i = 0; i < pjg; i++){
    temp.push(stk.top());
    stk.pop();
  }
  stk = temp;
}
int main(){
  stack<int> stk,temp; int x,v=1;
  while (v == 1){
    cout << "\n\tMenu Stack & Reverse Stacm\n1.Push\n2.Pop\n3.Reverse Stack\n4.Exit\nInput: ";
    cin >> x;
    switch (x){
      case 1:
      cout << "Masukan data: ";	
      cin >> x;  stk.push(x);  break;
      case 2:if (stk.empty()){cout << "Stack Kosong";break;} 
      cout << "Data yang di pop: " << stk.top(); 
      stk.pop(); break;
      case 3:if (stk.empty()){cout << "Stack Kosong";break;}
      temp = stk; x = temp.size(); cout << "Stack awal: ";
      for (int i = 0; i < x; i++){
        cout << temp.top() << " ";
        temp.pop();
      }reverseStack(stk);
      cout << "\nStack setelah di reverse: "; temp = stk;
        for (int i = 0; i < x; i++){
          cout << temp.top() << " ";
          temp.pop();
        }
      break;
      case 4:  
      v = 2;  break;
      default:  cout << "Input salah! masukan 1 sampai 4";
      break;
    }
  }
}