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

class Action
{
public:
    int noContainer; //Numero de Container -1 => nuevo container
    float item; //Peso del objeto
};

class State
{
public:
    int rank; //Valor del estado segun heuristica
    std::list<float> itemQueue; //Pesos que faltan por colocar
    std::list<Container> containers; //lista de Containers
};

bool isValidState(State &S, float max){

    std::list<Container>::iterator it;

    for(it = S.containers.begin(); it!=S.containers.end(); ++it){
        if( it.currentWeight > max){
            return false;
        }
    };
    return true;
};

std::list<Action> getActions(State &S, float max)
{ 
    std::list<Action> retList;
    std::list<Container>::iterator it;
    int i = 0;
    if(isValidState(S, max)){
        Action ret;
        for(it = S.containers.begin(); it!=S.containers.end(); ++it){
            std::cout<< *it.currentWeight + S.itemQueue.front();
            if(*it.currentWeight + S.itemQueue.front() < max){
                ret.item = S.itemQueue.front();
                ret.noContainer = i;
                retList.push_front(ret);       
            }
            i++;
        };
        ret.item = S.itemQueue.front();
        ret.noContainer = -1;
        retList.push_front(ret);
        return retList;
    }else{
        std::list<Action> retList;
        return retList;
    };
};

State transition(State &S, Action &a){
    State retAux = S;
    if(a.noContainer == -1){
        Container newContainer;
        newContainer.insertItem(a.item);
        retAux.itemQueue.pop_front();
        retAux.containers.push_front(newContainer);
        return retAux;
    }else{
        int i=0;
        std::list<Container>::iterator it;
        for(it = retAux.containers.begin(); it!=retAux.containers.end(); ++it){
            if(i == a.noContainer){
                *it.insertItem(a.item);
                retAux.itemQueue.pop_front();
                break;
            }
            i++;
        };
        return retAux;
    }
}

bool isFinalState(State &S, float max){
    if(isValidState(S, max)){
        return S.itemQueue.empty();
    }else{
        return false;
    }
}

