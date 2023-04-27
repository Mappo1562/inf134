#include "ListaEnlazada.hpp"
using namespace std;

int main(){
    tLista list;
    for (int i=0;i<10;i++){
        list.insert(i);
        list.next();
    }
    list.print();
    list.moveToStart();

    list.clear();
    cout<<"volvi al main\n";
    list.print();

    cout<<"\n";
    return 0;
}