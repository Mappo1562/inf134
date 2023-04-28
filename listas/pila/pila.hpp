#include <iostream>
#include <fstream>
#include <cstring>

typedef tElemPila;

class tPila{
    private:
        unsigned int maxSize; //    tamaño maximo de la pila
        unsigned int top; //        tamaño actual de la pila
        tElemPila* stackArray; //   arreglo con los elementos de la pila
    
    public:
        tPila();
        ~tPila();

        void clear ();//                reinicializa una pila como vacía
        
        int push (tElemPila item);//    inserta un elemento en el tope de la pila
        
        void pop ();//                  elimina el elemento que está en el tope de la pila
        
        tElemPila topValue ();//        retorna una copia del elemento que está en el tope de la pila
        
        int size ();//                  retorna el tamaño de una pila
};