#include <iostream>
#include "ListaArreglos.hpp"
int MAXSIZE=10000;


// inicializa una lista como vacía
tLista::tLista() {
    maxSize = MAXSIZE; // tamaño máximo de la lista
    listSize = 0; // lista vacía
    curr = 0;
    listArray = new tElemLista[maxSize];
}


// borra todos los elementos de la lista, reinicializándola vacía
void tLista::clear() {
    listSize = curr = 0;
}


// inserta un elemento en la posición actual de la lista
int tLista::insert(tElemLista item) {
    unsigned int i;
    if (listSize >= maxSize)
        return -1; //lista llena, no se inserta
    for (i = listSize; i > curr; i--)
        listArray[i] = listArray[i-1];
    listArray[i] = item;
    listSize++;
    return i; // retorna posición de inserción
}


// agrega un elemento al final de la lista
int tLista::append(tElemLista item) {
    if (listSize >= maxSize)
        return 0; //lista llena, no se inserta
    listArray[listSize++] = item;
    return 1; // inserción exitosa
}


// borra el elemento actual y retorna su valor
tElemLista tLista::erase() {
    tElemLista item;
    unsigned int i;
    if (curr < 0 || curr >= listSize)
        return -1;
    item = listArray[curr];
    for (i = curr; i < listSize-1; i++)
        listArray[i] = listArray[i+1];
    listSize--;
    return item;
}


// mueve la posición actual al comienzo de la lista
void tLista::moveToStart() {
    curr = 0; 
}


// mueve la posición actual al final de la lista deja una posicion adelante del ultimo elemento
void tLista::moveToEnd() {
    curr = listSize; 
}


// mueve la posición actual al elemento anterior de la lista
void tLista::prev() { 
    if (curr != 0) 
        curr--; 
}


// mueve la posición actual al elemento siguiente de la lista
void tLista::next() { 
    if (curr < listSize) 
        curr++; 
}


// destructor, libera la memoria asociada
tLista::~tLista() { 
    delete[] listArray; 
}


// retorna el número de elementos en la lista
int tLista::length(){
    return listSize;
}


// retorna la posición del elemento actual
int tLista::currPos(){
    return curr;
}


// mueve la posición actual a una especificada
void tLista::moveToPos(int pos){
    if (pos<=(int)maxSize)
        curr=pos;
}


// obtiene el valor del elemento actual de la lista
tElemLista tLista::getValue(){
    return listArray[curr];
}


// **   *      Zona De Pruebas      *   ** //


void tLista::print(){
    for (unsigned int i=0 ; i<listSize ; i++)
        cout<<"["<<listArray[i]<<"] ";      
}
