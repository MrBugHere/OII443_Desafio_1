// C++ program to find number of bins required using 
// First Fit algorithm. 
#include<iostream>
#include<stdlib.h>
#include "Lista.hpp"
using namespace std;



/*int main(){
   Lista lista;
    lista.addFront(20);
    lista.addFront(5);
    lista.addFront(30);
    lista.addFront(15);
    lista.printForward();
    return 0;
	
}*/

Lista::Lista()
{
   primero = new Nodo;
   ultimo = new Nodo;
   primero->next = ultimo;
   ultimo->prev = primero;
   primero->prev = NULL;
   ultimo->next = NULL;
}
int Lista::getFront()
{
   return primero->next->dato;
}
int Lista::getBack()
{
   return ultimo->prev->dato;
}
void Lista::addFront(int dato)
{
   Nodo *nuevo = new Nodo;
   nuevo->dato = dato;
   nuevo->prev = primero;
   nuevo->next = primero->next;

   primero->next->prev = nuevo;
   primero->next = nuevo;
}
void Lista::addBack(int dato)
{
   Nodo *nuevo = new Nodo;
   nuevo->dato = dato;
   nuevo->prev = ultimo->prev;
   nuevo->next = ultimo;

   ultimo->prev->next = nuevo;
   ultimo->prev = nuevo;
}
void Lista::removeFront()
{

   Nodo * nodo = primero->next->next;
   delete primero->next;

   primero->next = nodo;
   nodo->prev = primero;
}
void Lista::removeBack()
{
   Nodo *nodo = ultimo->prev->prev;
   delete ultimo->prev;
   ultimo->prev = nodo;
   nodo->next = ultimo;
}

void Lista::printReverse()
{
   Nodo *nodo = ultimo->prev;
   while (nodo != primero)
   {
      cout << nodo->dato << " ";
      nodo = nodo->prev;
   }
   
}
void Lista::printForward()
{
   Nodo *nodo = primero->next;
   while (nodo != ultimo)
   {
      cout << nodo->dato << " ";
      nodo = nodo->next;
   }
}

Lista::~Lista()
{
   while(primero->next != ultimo){
      removeFront();
   }

   delete primero;
   delete ultimo;
}