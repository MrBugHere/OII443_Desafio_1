#ifndef STATE_H
#define STATE_H

#include "Lista.hpp"

struct Paquete
{
    int pesoTotal;
    int pesoActual;
    Lista objetos;
};


class Estado
{
private:
    Lista objetos;
    Paquete paquetes[10];
public:
    Estado();
    void ingresarObjetos(int dato);
    //void agregarListaObjetos(Lista nueva);
    void ordenarObjetos();
    void imprimirObjetos();
    ~Estado();
};





#endif