// C++ program to find number of bins required using 
// First Fit algorithm. 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "main.h"
using namespace std;



int main(){
	Stack *pila = NULL;	//Inicializamos pila
	int dato;
	char rpt;
	
	do{ //Pedimos todos los elementos de la pila
		cout<<"Agregar peso: ";
		cin>>dato;
		agregarPila(pila,dato);
	
		cout<<"\nDesea agregar otro peso a pila(s/n): ";
		cin>>rpt;
	}while((rpt == 's')||(rpt=='S'));
	
	
	cout<<"\nMostrando los pesos de la pila: ";
	while(pila != NULL){
		sacarPila(pila,dato);
		
		if(pila != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}


