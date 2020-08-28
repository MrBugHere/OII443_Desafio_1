// C++ program to find number of bins required using 
// First Fit algorithm. 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Lista.hpp"
#include "Estado.hpp"
using namespace std;



int main(){
    Lista lista;
    Estado estado;
    int dato;
    char rpt;
    do{ //Pedimos todos los elementos de la pila
		cout<<"Ingrese peso: ";
		cin>>dato;
		estado.ingresarObjetos(dato);
	
		cout<<"\nDesea agregar otro peso (s/n): ";
		cin>>rpt;
	}while((rpt == 's')||(rpt=='S'));
    estado.imprimirObjetos();
    
    return 0;
}


