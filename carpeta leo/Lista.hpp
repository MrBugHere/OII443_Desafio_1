#ifndef LISTA_H
#define LISTA_H

template<class Objeto>

class Nodo{
private:
    Objeto dato;
    Nodo *prev;
    Nodo *next;

    friend class Lista;
public:
    Objeto getDato();

};

template <class Objeto>
class Lista{
public:
    Lista<objeto>();
    ~Lista();
    <Objeto> getFront();
    int getBack();
    void addFront(<Objeto>dato);
    void addBack(int dato);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();
    void ordenarLista();

private:
    Nodo<objeto> *primero;
    Nodo<objeto> *ultimo;

};

#endif