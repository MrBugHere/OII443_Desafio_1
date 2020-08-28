// C++ program to find number of bins required using 
// First Fit algorithm. 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Lista.hpp"
using namespace std;



int main(){
    Lista lista;
    lista.addFront(20);
    lista.addFront(5);
    lista.addFront(30);
    lista.addFront(15);
    lista.printForward();
    
    return 0;
}


