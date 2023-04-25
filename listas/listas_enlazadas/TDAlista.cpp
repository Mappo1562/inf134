typedef int tElemLista;


class tLista {
    private:
        unsigned int maxSize; //            tamaño máximo de la lista
        unsigned int listSize; //           tamaño actual de la lista
        unsigned int curr; //               posición actual de la lista
        tElemLista* listArray; //           arreglo con los elementos de la lista
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

        void moveToPos(int pos);//          mueve la posición actual a una especificada

        tElemLista getValue();//            obtiene el valor del elemento actual de la lista
};

