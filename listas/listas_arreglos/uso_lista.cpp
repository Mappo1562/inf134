#include <iostream>
#include "ListaArreglos.hpp"
using namespace std;



int main(){
    cout<<"\n";
    tLista list;
    for (int i=1;i<50;i*=2)
        list.append(i);

    list.moveToEnd();
    list.prev();
    cout<<"el ultimo valor es: "<<list.getValue();
    cout<<"\n";

    cout<<"la lista tiene "<<list.length()<<" datos, el 3er dato es ";
    list.moveToPos(3);
    cout<<list.getValue();

    cout<<", los valores actuales de la lista son = ";
    list.print();

    cout<< "\ningresaremos un valor 7 en la posicion 5\n";
    list.moveToPos(5);
    list.insert(7);
    cout<<"ahora el valor en la posicion 5 es "<<list.getValue()<<" y la lista completa quedaria= ";
    list.print();

    cout<<" con tamaño= "<<list.length()<<"\n\n";
    return 0;
}

// g++ uso_lista.cpp -o out -Wall