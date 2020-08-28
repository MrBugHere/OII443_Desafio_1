#include <iostream>
#include <list>

class Container
{
public:
    std::list<float> contents; // peso en Kgrs. de cada item que se coloca
    int currentWeight;   // suma de todo los pesos contenidos
};

struct Action
{
    int noContainer;
    float item; 
};

class state
{
public:
    int rank; //Valor del estado segun heuristica
    std::list<float> itemQueue; //Pesos que faltan por colocar
    std::list<Container> containers; //lista de Containers
};