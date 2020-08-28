// C++ program to find number of bins required using 
// First Fit algorithm. 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Lista.hpp"
using namespace std;



int main(){
    Lista lista;
    int dato;
    char rpt;
    do{ //Pedimos todos los elementos de la pila
		cout<<"Ingrese peso: ";
		cin>>dato;
		lista.addFront(dato);
	
		cout<<"\nDesea agregar otro peso (s/n): ";
		cin>>rpt;
	}while((rpt == 's')||(rpt=='S'));
    
    lista.printForward();
    return 0;
}


