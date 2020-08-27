
#define MAIN_H

struct Stack{
	int dato;
	Stack *siguiente;
};

//Prototipos de Funci�n
void agregarPila(Stack *&,int); 
void sacarPila(Stack *&,int &);

void agregarPila(Stack *&pila,int n){
	Stack *nuevo_nodo = new Stack();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPila(Stack *&pila,int &n){
	Stack *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

class Packing
{
private:
    int pesoTotal;
    int pesoLimite;
    Stack *pila;

public:
    int setPesoTotal(int x);
    int setPesoLimite(int limite);
};

/*
class Objeto
{
private:
    int peso;
public:
 Objeto*/
