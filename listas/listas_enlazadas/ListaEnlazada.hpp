#include <iostream>
#include <fstream>
#include <cstring>

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

        void clear();//                     borra todos los elementos de la lista, reinicializándola vacía

        int insert(tElemLista item);//      inserta un elemento en la posición actual de la lista

        int append(tElemLista item);//      agrega un elemento al final de la lista

        tElemLista erase();//               borra el elemento actual y retorna su valor

        void moveToStart();//               mueve la posición actual al comienzo de la lista

        void moveToEnd();//                 mueve la posición actual al final de la lista

        void next();//                      mueve la posición actual al siguiente elemento de la lista, no produce cambios si está en la cola de la lista

        void prev();//                      mueve la posición actual al elemento anterior de la lista, no produce cambios si está en la cabeza de la lista

        int length();//                     retorna el número de elementos en la lista

        int currPos();//                    retorna la posición del elemento actual

        void moveToPos(unsigned int pos);//          mueve la posición actual a una especificada

        tElemLista getValue();//            obtiene el valor del elemento actual de la lista


        void print();
        
};

/*

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

*/