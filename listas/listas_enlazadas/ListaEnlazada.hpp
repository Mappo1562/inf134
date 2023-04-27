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

        void clear();
        int insert(tElemLista item);
        tElemLista erase();
        void moveToStart();
        void moveToEnd();
        void prev();
        void next();
        void moveToPos(unsigned int posicion);

        tElemLista getValue();
        void print();
};
