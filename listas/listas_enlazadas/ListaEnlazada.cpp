#include "ListaEnlazada.hpp"
using namespace std;


tLista::tLista() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
}

tLista::~tLista(){}

void tLista::clear(){//                     ojo con esta
    tNodo *aux,*pointer;
    aux=head->sig;
    for (unsigned int i=0;i<listSize;i++){
        pointer=aux->sig;
        delete[] aux;
        aux=pointer;
    }
    head->sig=NULL;
    curr=tail=head;
}

int tLista::insert(tElemLista item) {
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if (curr == tail) tail = curr->sig;
    listSize++;
    return pos;
}

tElemLista tLista::erase(){//               ojo con esta
    tNodo *aux=curr->sig;
    tElemLista ret;
    ret=aux->info;
    curr->sig=aux->sig;
    delete[]aux;
    return ret;
}

void tLista::moveToStart(){ 
    curr = head->sig; pos = 0; 
}

void tLista::moveToEnd(){ 
    curr = tail; pos = listSize; 
}

void tLista::prev() {
    tNodo* temp;
    if (curr == head)  
        return;
    temp = head;
    while (temp->sig != curr) 
        temp = temp->sig;
    curr = temp;
    pos--;
}

void tLista::next(){ 
    if (curr != tail){ 
        curr = curr->sig; pos++; 
    } 
}

void tLista::moveToPos(unsigned int posicion) {
    unsigned int i;
    if (posicion < 0 || posicion > listSize) 
        return;
    curr = head;
    pos = 0;
    for (i = 0; i < posicion; i++) {
        curr = curr->sig;
        pos++;
    }
}

tElemLista tLista::getValue(){
    return curr->info;
}

int tLista::length(){
    return listSize;
}

////////        funciones hechas por mi         ////////

void tLista::print(){
    curr=head->sig;
    pos=0;
    while(curr->sig!=NULL){
        cout<<"["<<curr->info<<"] ";
        curr=curr->sig;
        pos++;
    }
    if (curr->sig==NULL && pos==0)
        cout<<"la lista esta vacia";
    cout<<"\n";
}