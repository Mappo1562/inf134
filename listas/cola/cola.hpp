#include <iostream>
#include <fstream>
#include <cstring>

typedef tElemCola;

////        cola circular       ////

class tCola{
    private:
        int* frente;
        int* final;
        tElemCola* array;
    
    public:
        
        void clear ();//                reinicializa una cola como vacía

        int enqueue (tElemCola item);// inserta un elemento al final de la cola
       
        void dequeue (); //             elimina el elemento que está en el frente cola

        tElemCola frontValue ();//      retorna una copia del elemento que está en el frente de la cola
        
        int size ();//                  retorna el tamaño de una cola
};