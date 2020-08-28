
class Nodo{
private:
    int dato;
    Nodo *prev;
    Nodo *next;

    friend class Lista;
};


class Lista{
public:
    Lista();
    ~Lista();
    int getFront();
    int getBack();
    void addFront(int dato);
    void addBack(int dato);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();

private:
    Nodo *primero;
    Nodo *ultimo;

};



//Prototipos de Funci�n


