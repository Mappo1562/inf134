#include "pila.hpp"



int main(){
    tPila pila;
    for (int i=1;i<50;i*=3)
        pila.push(i);
    
    pila.print();
    cout<<pila.topValue()<<" es el ultimo valor y la pila tienen un tamaño de "<<pila.size()<<"\n";

    pila.pop();
    pila.print();
    cout<<pila.topValue()<<" es el ultimo valor y la pila tienen un tamaño de "<<pila.size()<<"\n";
    
    pila.clear();
    pila.print();
}






















































/*
void revisador(tPila pila, int n){
    char i;
    for (int j=0;j<n;j++){
        cin>>i;
        if (i=='(')
            pila.push(i);
        else if(i==')'&&pila.size()!=0)
            pila.pop();
        else {
            cout<<"no esta bien\n";
            return;
        }
    }
    if (pila.size()==0)
        cout<<"esta bien\n";
    else
        cout<<"esta pesimo\n";
}

int main(){
    cout<<"*****    revisión parentesis    *****\n\n";
    tPila pila;
    int n;
    cout<<"ingresa el tamaño del string que deseas consultar: ";
    cin>>n;
    cout<<"ingresa el string de "<<n<<" caracteres que deseas consultar: ";
    revisador(pila,n);
    return 0;
}
*/