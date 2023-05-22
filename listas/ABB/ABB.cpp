#include "ABB.hpp"


void procesar(tipoElem nodo){
    return;
}


tABB::tAAB(){
    raiz = NULL;
    nElems = 0;
}

void clearHelp(tNodoArbolBin *nodo) {
    if (nodo == NULL) return; //    árbol vacío, se detiene
    clearHelp(nodo->izq); //        visita subárbol izquierdo recursivamente
    clearHelp(nodo->der); //        visita subárbol derecho recursivamente
    delete nodo; //                 después de borrar subárboles, se borra a sí mismo
}

void tAAB::clear() {
 clearHelp(raiz); // función auxiliar para eliminar los nodos
 raiz = NULL;
 nElems = 0;
}

void procesar(tNodoArbolBin* nodo){
    return;
}

void tAAB::inOrden () {
    inOrdenHelp (raiz);
}

void inOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == NULL) return;
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en in-orden
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
    inOrdenHelp (nodo->der); //     visita hijo derecho en in-orden
}

void tABB::preOrden(){
    preOrdenHelp(raiz);
}

void preOrdenHelp(tNodoArbolBin *nodo){
    if (nodo == NULL) return;
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en pre-orden
    inOrdenHelp (nodo->der); //     visita hijo derecho en pre-orden
}