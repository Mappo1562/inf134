#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


typedef int tElemLista;

struct tNodo{
 tElemLista info;
 tNodo* sig;
};



class tLista {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;
        unsigned int listSize;
        unsigned int pos; // posicion actual en la lista
    public:
        tLista();
        ~tLista();
        void clear();//                         borra todos los elementos de la lista reiniciandola vacia
        int insert(tElemLista item);//          inserta un elemento en la posicion actual de la lista          
        int append(tElemLista item);
        tElemLista erase();//                   borra el siguiente elemento (en base al curr) en la lista
        void moveToStart();//                   curr se mueve al inicio
        void moveToEnd();//                     curr se mueve al final
        void next();//                          curr se mueve al siguiente
        void prev();//                          curr se mueve al anterior
        int length();
        int currPos();
        void moveToPos(unsigned int pos);
        tElemLista getValue();
};


tLista::tLista() {
    head = tail = curr = new tNodo;
    listSize = 0;
    pos = 0;
}


void tLista::clear(){//                     ojo con esta
    tNodo *aux,*pointer;
    aux=head->sig;
    for (int i=0;i<listSize;i++){
        pointer=aux->sig;
        delete[] aux;
        aux=pointer;
    }
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
    curr = head; pos = 0; 
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