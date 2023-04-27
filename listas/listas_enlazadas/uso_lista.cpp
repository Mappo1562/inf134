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
     for(int i=0;i<10;i++){
        cout<<list.getValue();
        list.next();
    }

    list.clear();
    list.print();

    cout<<"\n";
    return 0;
}