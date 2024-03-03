#include <iostream>
using namespace std;

struct User
{
    int ID;
    string name;
    string clas;
    float level;
};
int x = 0;
int main(int argc, char const *argv[])
{
    x+=1;
    User V[x];
    V[x-1].ID = x;
    V[x-1].name = "Sidus";
    V[x-1].clas = "Tanker";
    V[x-1].level = 17.5;
    cout << "User count: " << x;
    for (int i = 0; i < x; i++)
    {
    cout << "\nUser:" << V[i].name
    << "\nClass:" << V[i].clas
    << "\nLevel:" << V[i].level << " ID:" << V[1].ID;
    }
}

