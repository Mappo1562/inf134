#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef int tElemPila;

class tPila{
    private:
        unsigned int maxSize; //    tamaño maximo de la pila
        unsigned int top; //        tamaño actual de la pila
        tElemPila* stackArray; //   arreglo con los elementos de la pila
    
    public:
        tPila();
        ~tPila();

//  reinicializa una pila como vacía
        void clear ();

//  inserta un elemento en el tope de la pila
        int push (tElemPila item);

//  elimina el elemento que está en el tope de la pila
        void pop ();

//  retorna una copia del elemento que está en el tope de la pila     
        tElemPila topValue ();

//  retorna el tamaño de una pila        
        int size ();

////        ojo que aqui comienzan mis funciones (no se deverian usar)        ////

        void print();
};