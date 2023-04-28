#include "pila.hpp"

int MAXSIZE=10000;



tPila::tPila(){
    maxSize=MAXSIZE;
    top=0;
    stackArray=new tElemPila(maxSize);
}

tPila::~tPila(){
    delete[] stackArray;
}

int tPila::push (tElemPila item){
    if (top == maxSize) 
        return 0;
    stackArray[top++] = item;
    return 1; // inserción exitosa
}

void tPila::clear (){
    top=0;
}

void tPila::pop(){
    if (top==0)
        return;
    top--;
}

tElemPila tPila::topValue(){
    return stackArray[top-1];
}

int tPila::size(){
    return top-1;
}










void tPila::print(){
    for (int i=top-1;i>0;i--)
        cout<<"["<<stackArray[i]<<"] ";
    if (top==0)
        cout<<"la pila esta vacia";
    cout<<"\n";
}