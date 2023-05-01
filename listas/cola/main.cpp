
#include "cola.hpp"

int main(){
    tCola list;
    for (int i=1;i<10;i+=i)
        list.enqueue(i);
    
    //  [1] [2] [4] [8] [0] [0] [0] [0] [0] [0]

    list.print();
    cout<<"el tamaño es de "<<list.size()<<"\n";
    cout<<"el primer valor es "<<list.frontValue()<<"\n";

    //  ¬[1] [2] [4] [8] [0] [0] [0] [0] [0] [0]
    list.dequeue();
    cout<<"el tamaño es de "<<list.size()<<"\n";
    cout<<"el primer valor es "<<list.frontValue()<<"\n";

    //  ¬[1] [2] [4] [8] [20] [0] [0] [0] [0] [0]
    list.enqueue(20);
    cout<<"el tamaño es de "<<list.size()<<"\n";
    cout<<"el primer valor es "<<list.frontValue()<<"\n";

    //  ¬[1] ¬[2] [4] [8] [20] [5] [5] [5] [5] [0]
    for (int i=0;i<4;i++)
        list.enqueue(5);
    list.dequeue();
    list.print();
    cout<<"el tamaño es de "<<list.size()<<"\n";
    cout<<"el primer valor es "<<list.frontValue()<<"\n";

    //  [3] ¬[2] [4] [8] [20] [5] [5] [5] [5] [3]
    for (int i=0;i<2;i++)
        list.enqueue(3);
    list.print();
    cout<<"el tamaño es de "<<list.size()<<"\n";
    cout<<"el primer valor es "<<list.frontValue()<<"\n";

    //  ¬[3] ¬[2] ¬[4] ¬[8] ¬[20] ¬[5] ¬[5] ¬[5] ¬[5] ¬[3]
    list.clear();
    list.print();
    cout<<"el tamaño es de "<<list.size()<<"\n";
    cout<<"el primer valor es "<<list.frontValue()<<"\n";
}