#include "pila.hpp"


int tPila::push (tElemPila item){
    if (top == maxSize) 
        return 0;
    stackArray[top++] = item;
    return 1; // inserción exitosa
}