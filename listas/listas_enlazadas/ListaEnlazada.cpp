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
        void clear();
        int insert(tElemLista item);
        int append(tElemLista item);
        tElemLista erase();
        void moveToStart();
        void moveToEnd();
        void next();
        void prev();
        int length();
        int currPos();
        void moveToPos(int pos);
        tElemLista getValue();
};


tLista::tLista() {
 head = tail = curr = new tNodo;
 listSize = 0;
 pos = 0;
}


void tLista::clear(){

}
