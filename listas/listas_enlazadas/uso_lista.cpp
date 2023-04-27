#include "ListaEnlazada.hpp"
using namespace std;

int main(){
    tLista list;

    for (int i=0;i<10;i++){
        list.insert(i);//                       insert y next funciona
        list.next();
    }
    list.print();

    list.moveToStart();
     for(int i=0;i<10;i++){//                   get value funciona
        cout<<"["<<list.getValue()<<"] ";
        list.next();
    }
    cout<<"\n";

    list.clear();//                             clear creo que funciona bien, (por lo menos logra eliminar la lista)
    list.print();

    cout<<"\n";
    return 0;
}