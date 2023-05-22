#include "ABB.hpp"


void procesar(tipoElem nodo){
    return;
}


tabb::tabb(){
    raiz = NULL;
    nElems = 0;
}



void clearHelp(tNodoArbolBin *nodo) {
    if (nodo == NULL) return; //    árbol vacío, se detiene
    clearHelp(nodo->izq); //        visita subárbol izquierdo recursivamente
    clearHelp(nodo->der); //        visita subárbol derecho recursivamente
    delete nodo; //                 después de borrar subárboles, se borra a sí mismo
}

void tabb::clear() {
 clearHelp(raiz); // función auxiliar para eliminar los nodos
 raiz = NULL;
 nElems = 0;
}



void preOrdenHelp(tNodoArbolBin *nodo){
    if (nodo == NULL) return;
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en pre-orden
    inOrdenHelp (nodo->der); //     visita hijo derecho en pre-orden
}

void tabb::preOrden(){
    preOrdenHelp(raiz);
}



void inOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == NULL) return;
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en in-orden
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
    inOrdenHelp (nodo->der); //     visita hijo derecho en in-orden
}

void tabb::inOrden () {
    inOrdenHelp (raiz);
}



void postOrdenHelp(tNodoArbolBin *nodo){
    if (nodo == NULL) return;
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en post-orden
    inOrdenHelp (nodo->der); //     visita hijo derecho en post-orden
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
}

void tabb::postOrden(){
    postOrdenHelp(raiz);
}



int findHelp(tNodoArbolBin *nodo, tipoElem item) {
    if (nodo == NULL) return 0; // item no está en el ABB
    if (nodo->info == item) return 1; // item encontrado
    if (item < nodo->info)
        return findHelp(nodo->izq, item);
    else
        return findHelp(nodo->der, item);
}

int tabb::find(tipoElem item) {
 return findHelp(raiz, item);
}



//      Mis Funciones



tabb::~tabb(){

}



bool removeHelp(tNodoArbolBin *nodo, tipoElem item){

}

void tabb::remove(tipoElem item){
    if (!findHelp(raiz,item)){
        cout<<"****    ERROR    ****\nel dato "<<item<<" no existe, pot lo tanto no se puede eliminar";
    }
    
    removeHelp(raiz,item);
}



int tabb::size(){
    return nElems;
}



bool insertHelp(tNodoArbolBin *nodo, tipoElem item){
    if (nodo==NULL){
        nodo=new tNodoArbolBin;
        nodo->info=item;
        return 1;
    }
    if (item<nodo->info) return insertHelp(nodo->izq,item);
    if (item==nodo->info){
        cout<<"****    ERROR    ****\nel dato "<<nodo->info<<" ya fue ingresado";
        return 0;
    }
    if (item>nodo->info) return insertHelp(nodo->der,item);
}

void tabb::insert(tipoElem item){
    bool flag=insertHelp(raiz,item);
    if (flag)
        nElems++;
}