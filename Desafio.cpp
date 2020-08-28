#include <iostream>
#include <list>

class Container
{
public:
    std::list<float> contents; // peso en Kgrs. de cada item que se coloca
    float currentWeight;   // suma de todo los pesos contenidos

    void insertItem(float item);
};

void Container::insertItem(float item){ //Inserta el item dentro del container, no importa si hay limite
    currentWeight += item;
    contents.push_front(item);
}

struct Action
{
    int noContainer; //Numero de Container;
    float item; //Peso del obejto
};

class State
{
public:
    int rank; //Valor del estado segun heuristica
    std::list<float> itemQueue; //Pesos que faltan por colocar
    std::list<Container> containers; //lista de Containers
};

bool isValidState(State S, float max){
    std::list<Container>::iterator it;

    for(it = S.containers.begin(); it!=S.containers.end(); ++it){
        if( it.currentWeight > max){
            return false;
        }
    };
    return true;
};
