#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef int tElemLista;
int MAXSIZE=500;

class tLista {
    private:
        unsigned int maxSize; // tamaño máximo de la lista
        unsigned int listSize; // tamaño actual de la lista
        unsigned int curr; // posición actual de la lista
        tElemLista* listArray; // arreglo con los elementos de la lista
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

        void print();
};


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


// mueve la posición actual al final de la lista
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
int tLista::length(){       //  desde aqui son inventos mios, probable error
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
    for (unsigned int i=0 ; i<=listSize ; i++)
        cout<<"["<<listArray[i]<<"] ";      
}


int main(){
    cout<<"\n";
    tLista list;
    for (int i=1;i<50;i*=2)
        list.append(i);

    list.moveToEnd();
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