#include "cola.hpp"

int MAXSIZE=10;

tCola::tCola(){
    array=new int [MAXSIZE];
    frente=final=0;
}

tCola::~tCola(){
    delete[] array;
}

void tCola::clear(){
    frente=final=0;
}

int tCola::enqueue(tElemCola item){
    array[final%MAXSIZE]=item;
    final++;
    return item;
}

void tCola::dequeue(){
    frente++;
    if (frente == MAXSIZE)
        frente=0;
}

tElemCola tCola::frontValue(){
    if(final!=frente)
        return array[frente];
    return 0;
}

int tCola::size(){
    return final-frente;
}


void tCola::print(){
    for (int i=0;i<MAXSIZE;i++)
        cout<<"["<<array[i]<<"] ";
    cout<<"\n";
}

void tCola::print2(){
    for (int i=frente;i<final;i++)
        cout<<"["<<array[i%MAXSIZE]<<"] ";
    cout<<"\n";
}