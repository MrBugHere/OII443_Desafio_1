#include "Estado.hpp"
#include "Lista.hpp"

#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <stddef.h>
using namespace std;


Estado::Estado(){
    
}

void Estado::ingresarObjetos(int dato){
    objetos.addBack(dato);
}

/*void Estado::agregarListaObjetos(Lista nueva){
    objetos = nueva.getLista();
    
}
*/
void Estado::imprimirObjetos(){
    objetos.printForward();
}

Estado::~Estado(){
    
    objetos.~Lista();
}