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
    clear();
}



tNodoArbolBin* find_predecesor(tNodoArbolBin* raiz){
    if (raiz->der==NULL)
        return raiz;
    find_predecesor(raiz->der);
}

void removeHelp(tNodoArbolBin *nodo, tipoElem item){
    if (nodo->info==item){
        if (nodo->izq==NULL && nodo->der==NULL){
            delete[] nodo;
            nodo=NULL;
        }
        else if (nodo->izq!=NULL && nodo->der==NULL){
            tNodoArbolBin *aux=nodo->izq;
            delete[] nodo;
            nodo=aux;
        }
        else if (nodo->der!=NULL && nodo->izq==NULL){
            tNodoArbolBin *aux=nodo->der;
            delete[] nodo;
            nodo=aux;
        }
        else{
            tNodoArbolBin* aux=find_predecesor(nodo->izq);
            nodo->info=aux->info;
            if (aux->izq==NULL)
                delete[] aux;
            else{
                tNodoArbolBin* alo=nodo->izq;
                delete[] aux;
                aux=alo;
            }
        }
    }
    if (nodo == NULL) return;
    if (item < nodo->info)
        removeHelp(nodo->izq, item);
    else
        removeHelp(nodo->der, item);
}

void tabb::remove(tipoElem item){
    if (find(item)){
        removeHelp(raiz,item);
        nElems--;
    }
    else{
        cout<<"****    ERROR    ****\nel dato "<<item<<" no existe, por lo tanto no se puede eliminar";
    }
}



int tabb::size(){
    return nElems;
}



void insertHelp(tNodoArbolBin *&nodo, tipoElem item,bool &flag){
    if (nodo==NULL){
        nodo=new tNodoArbolBin;
        nodo->info=item;
        nodo->izq=NULL;
        nodo->der=NULL;
        flag= 1;
    }
    else if (item<nodo->info)
        insertHelp(nodo->izq,item,flag);

    else if (item>nodo->info)
        insertHelp(nodo->der,item,flag);

    else if (item==nodo->info){
        cout<<"****    ERROR    ****\nel dato "<<nodo->info<<" ya fue ingresado\nerror en ABB.cpp linea 167\n";
        flag= 0;
    }
}

void tabb::insert(tipoElem item){
    bool flag;
    insertHelp(raiz,item,flag);
    if (flag)
        nElems++;
}
