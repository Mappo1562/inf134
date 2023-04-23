#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class Auto {
    private:
        int velAct;
        float cantGas;
        bool motEnc;
        int cambAct;
    public:
        Auto() {motEnc=false; velAct=20; cantGas=0.0; cambAct=0;};   //  constructor
        ~Auto(){}                                                   //  destructor
        void arrancar();
        void acelerar();
        void frenar();
        bool tieneGas();
        void cargarGas(float cant);
        void subirCambio();
        void bajarCambio();
        void neutro();
        int get_vel();
};



/*
los datos privados solo pueden accederse a partir de las operaciones que aparecen en public
las operaciones del public pueden invocarse fuera del tda
*/

void Auto::arrancar() {motEnc = true; velAct = 0;}
void Auto::acelerar() {velAct++;}
void Auto::frenar() {velAct--;}
bool Auto::tieneGas() {return cantGas > 0.0;}
void Auto::cargarGas(float cant) {cantGas += cant;}
void Auto::subirCambio() {cambAct++;}
void Auto::bajarCambio() {cambAct--;}
void Auto::neutro() {cambAct=0;}

int Auto::get_vel(){return velAct;}
/*
estas son las funciones relacionadas con la clase auto
*/

/*
Auto::Auto(){
    motEnc=true;
    velAct=5;
    cantGas=100;
    cambAct=3;
}
*/
int main(){
    Auto nissanv16;
    cout<<nissanv16.get_vel()<<"\n";
    return 0;
}

/*
este es un constructor de un auto
*/