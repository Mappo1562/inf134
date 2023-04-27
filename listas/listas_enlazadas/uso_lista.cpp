#include "ListaEnlazada.hpp"
using namespace std;

int main(){
    tLista list;
    int a;
    for (int i=0;i<10;i++){
        list.insert(i);
        list.next();
    }
    list.print();
    list.moveToStart();

    for (int i=0;i<list.length();i++){// este for sirve para recorrer la lista
        list.next();
        a=list.getValue();
        cout<<"["<<a<<"] ";
    }
    cout<<"\n";
    list.clear();
    list.print();

    cout<<"\n";
    return 0;
}