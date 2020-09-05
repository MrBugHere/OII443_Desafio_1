#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;



class Container
{
private:
    list<double> items; // peso en Kgrs. de cada item que se coloca
    double currentWeight;   // suma de todo los pesos contenidos
    double maxWeight;
public:
    void setMaxWeight(double n);
    void setCurrentWeight(double n);
    double getMaxWeight();
    double getCurrentWeight();
    void insertItem(double item);
    void printItems();
};

class State
{
private:
    int rank; //Valor del estado segun heuristica
    vector<double> items; //Pesos que faltan por colocar, arreglo dinamico.
    vector<Container> containers; //lista de Containers
    bool visited;
public:
    void pushItems(double n);
    void printItems();
    void ordenarItems();
    double getUltimoItem();
    //double getPrimerItem();
    void eliminarUltimoItem();
    void eliminarItem(int pos);
    void agregarNuevoContainer(double n);
    void agregarNuevoContainer(double n, double item);
    void agregarItem_container(double item, int pos);
    Container getUltimoContainer();
    vector<Container> getContainers();
    vector<double> getItems();

    void setRank(int n);
    int getRank();
    int getSizeItems();
    int getSizeContainers();
    bool getvisited();
    void setVisited(bool in);
    void printState();
};

class Action
{
private:
    bool crearContainer; // no es necesario, colocar el nro al final
    int noContainer; // ubicacion en la lista.
    Container container;
    double item; //Peso del objeto
public:
    void setItem(double nuevoItem);
    void setContainer(Container nuevoContainer);
    void setCrearContainer(bool r);
    double getItem();
    Container getContainer();
    bool getCrearContainer();
    bool esValido(double item, Container container);
    void setnoContainer(int n);
    int getNoContainer();
};

bool estadofinal(State estado);
//--------------------------- Funciones Container --------------------------------------------------//

void Container::setMaxWeight(double n) {
    maxWeight = n;
}
void Container::setCurrentWeight(double n) {
    currentWeight = n;
}
double Container::getMaxWeight() {
    return maxWeight;
}
double Container::getCurrentWeight() {
    return currentWeight;
}

void Container::insertItem(double item) { //Inserta el item dentro del container, no importa si hay limite
    currentWeight = currentWeight + item;
    items.push_back(item);
}

void Container::printItems() {
    for (auto v : items) {
        cout << v << "; ";
    }
}
//--------------------------- Funciones State ----------------------------------------------------//

void State::pushItems(double n) { //Dimensionar cantidad de items
    items.push_back(n);
}

void State::printItems() {
    for (int i = 0; i < items.size(); i++)
    {
        cout << items[i] << ", ";
    }
}

void State::ordenarItems() {
    sort(items.begin(), items.end(), greater<double>());
}

double State::getUltimoItem() {
    double num;
    num = items[items.size() - 1];
    items.pop_back();

    return num;
}

/*double State::getPrimerItem(){
    double num;
    num = items.front();
    items.pop
    return items.front();
}*/

Container State::getUltimoContainer() {
    return containers[containers.size()];
}

void State::agregarNuevoContainer(double n) {
    Container nuevo;
    nuevo.setMaxWeight(n);
    nuevo.setCurrentWeight(0);
    //nuevo.insertItem(item);
    containers.push_back(nuevo);
}
void State::agregarNuevoContainer(double n, double item){
    Container nuevo;
    nuevo.setMaxWeight(n);
    nuevo.setCurrentWeight(0);
    nuevo.insertItem(item);
    containers.push_back(nuevo);
}
vector<Container> State::getContainers() {
    return containers;
}

void State::agregarItem_container(double item, int pos) {
    containers[pos].insertItem(item);
    
}
void State::eliminarUltimoItem() {
    items.pop_back();
}

void State::eliminarItem(int pos){
    items.erase(items.begin() + pos);
}
vector<double> State::getItems() {
    return items;
}

void State::setRank(int n) {
    rank = n;
}

int State::getRank() {
    return rank;
}

int State::getSizeItems() {
    return items.size();
}
int State::getSizeContainers() {
    return containers.size();
}
bool State::getvisited() {
    return visited;
}
void State::setVisited(bool in) {
    visited = in;
}

void State::printState() {
    cout << "\nEstado"
        << "\n \tItems por Colocar: ";

    for (int i = 0; i < items.size(); i++) {
        cout << items.at(i) << ", ";
    }

    cout << "\nContainers: ";

    for (int i = 0; i < containers.size(); i++)
    {
        cout << "\n\tNo " << i + 1 << "- ";
        containers.at(i).printItems();
    }

    cout << "\nRank: "
        << getRank();
    cout<<"\n\n";
}

//--------------------------- Funciones Action ----------------------------------------------------//

void Action::setnoContainer(int n) {
    noContainer = n;
}
int Action::getNoContainer() {
    return noContainer;
}
void Action::setItem(double nuevoItem) {
    item = nuevoItem;
}
void Action::setContainer(Container nuevoContainer) {
    container = nuevoContainer;
}
double Action::getItem() {
    return item;
}
Container Action::getContainer() {
    return container;
}
bool Action::esValido(double nuevoItem, Container nuevoContainer) {
    if (nuevoItem + nuevoContainer.getCurrentWeight() > nuevoContainer.getMaxWeight())
    {
        return false;
    }
    return true;
}

void Action::setCrearContainer(bool r) {
    crearContainer = r;
}

bool Action::getCrearContainer() {
    return crearContainer;
}

list<Action> get_actions(State& estado) {
    list<Action> actions;
    Action action;
    int j = 0;

    for (auto itemAux : estado.getItems())
    {
        j = 0;
        for (auto containerAux : estado.getContainers())
        {
            if (action.esValido(itemAux, containerAux)) {
                action.setItem(itemAux);
                action.setContainer(containerAux);
                action.setnoContainer(j);
                action.setCrearContainer(false);
                actions.push_back(action);
            }
            else
            {

                action.setItem(itemAux);
                
                action.setCrearContainer(true);
                actions.push_back(action);
            }
            j++;
        }
    }
    /*cout << "\npeso de cada item en accion";
    for (list<Action>::iterator i = actions.begin(); i != actions.end(); ++i)
    {
        action = *i;
        cout << action.getItem() << "; ";
        cout << action.getContainer().getCurrentWeight() << "; ";
    }
    */
    return actions;

}

State transition(State& nuevoEstado, Action& action) {
    State retorno;
    retorno = nuevoEstado;
    int j =0;
    if (action.getCrearContainer())
    {
        Container nuevoContainer;
        retorno.agregarNuevoContainer(action.getContainer().getMaxWeight(),action.getItem());
        //retorno.agregarItem_container(action.getItem(), action.getNoContainer());
        for (auto i : nuevoEstado.getItems())
        {
            if(i == action.getItem()){
                retorno.eliminarItem(j);
            }
            j++;
        }
        
        //cout << "nuevo estado creado.";
        //retorno.printState();
        
        //cout <<"\nse elimino item correctamente";
        return retorno;

    }
    else
    {
        retorno.agregarItem_container(action.getItem(), action.getNoContainer());
        for (auto i : nuevoEstado.getItems())
        {
            if(i == action.getItem()){
                retorno.eliminarItem(j);
            }
            j++;
        }
        //cout << "\nnuevo estado creado.";
        //retorno.printState();
       
        return retorno;
    }
    

}

//-------------------------------------------------------------------------------------------//

bool waitForResponse() {
    int response;
    cout << "\n1.- Sgte. iteracion"
        << "\n2.- Detener"
        << "\nRespuesta: ";
    cin >> response;
    switch (response)
    {
    case 1:
        return true;
        break;
    case 2:
        return false;
        break;
    default:
        return true;
        break;
    }
}

void ClearScreen() {
    cout << string(100, '\n');
}

bool estadofinal(State estado){
    if (estado.getItems().empty())
    {
        return true;
    }
    return false;
}


void dfs(State& initial) {
    std::cout << "\n DFS";
    stack<State> S;
    S.push(initial);
    vector<State> estadosfinales;
    while (!S.empty()) {
        //cout << "\n while";
        State s = S.top(); S.pop();
        if (s.getvisited()) continue;
        //cout << "\n visit";
        s.setVisited(true);
        list<Action> actions = get_actions(s);
        for (Action a : actions) {
            //cout << "\n actions";
            State t = transition(s, a);
            t.setVisited(false);
            if(estadofinal(t)){
                //cout<<"\nEstado final:";
                //t.printState();
                estadosfinales.push_back(t);
            }
            
            //cout << "\n transitioned";
            S.push(t);
        }
    }
    State mejor;
    mejor = estadosfinales[0];
    for (auto i : estadosfinales)
    {
        if(mejor.getSizeContainers() > i.getSizeContainers()){
            mejor = i;
        }

    }
    cout <<"\nEl mas mejor de todos los mejores:\n";
    mejor.printState();
   
}

void bfs(State& initial) {
    cout << "\n BFS";
}



void ranking(State& S) {
    // funcion que setea el rank del State dado
    // es el valor entero de la cantidad de Contenedores mas los items que falta por ordenar
    // menor numero es mejor (Menos contenedors y menos items que ordenar)
    S.setRank(S.getSizeContainers()  + S.getSizeItems() );
}

struct lessthanbyRank
{
    bool operator()(State& leftS, State& rigthS) {
        return leftS.getRank() < rigthS.getRank();
    };
};


void bestFirst(State& initial) {
    priority_queue < State, vector<State>, lessthanbyRank > qp;
    ranking(initial);
    vector<State> estadosfinales;
    qp.push(initial);
    while (!qp.empty()) {
        State s = qp.top(); qp.pop();
        if (s.getvisited()) continue;
        s.setVisited(true);
        list<Action> actions = get_actions(s);
        for (Action a : actions) {
            State ss = transition(s, a);
            ss.setVisited(false);
            ranking(ss);
            //ss.printState();
            if(estadofinal(ss)){
                //cout<<"\nEstado final:";
                //ss.printState();
                estadosfinales.push_back(ss);
            }
            qp.push(ss);
            
        }
    }
    State mejor;
    mejor.setRank(1000000);
    for (auto i : estadosfinales)
    {
        if(mejor.getRank() > i.getRank()){
            mejor = i;
        }

    }
    cout <<"\nEl mas mejor de todos los mejores:\n";
    mejor.printState();
}

void menu() {
    State initial;
    double data;
    char res;
    int res2;

    cout << "Ingresar peso Maximo de Cada Contenedor: ";
    cin >> data;
    initial.agregarNuevoContainer(data);
    initial.setVisited(false);
    //ClearScreen();
    do { //Pedimos el peso de todos los elementos que se ingresaran.
        cout << "Ingrese peso: ";
        cin >> data;
        initial.pushItems(data);

        cout << "Desea agregar otro peso (s/n): ";
        cin >> res;
        //ClearScreen();
    } while ((res == 's') || (res == 'S'));
    initial.ordenarItems();
    ranking(initial);
    //ClearScreen();
    do
    {
        cout << "\n1.- DFS"
            //<< "\n2.- BFS"
            << "\n2.- BestFirst"
            << "\n3.- imprimir estado inicial"
            << "\n4.- Salir"
            << "\nRespuesta: ";
        cin >> res2;
        switch (res2)
        {
        case 1:
            ClearScreen();
            dfs(initial);
            break;
        /*case 2:
            ClearScreen();
            bfs(initial);
            break;*/
        case 2:
            ClearScreen();
            bestFirst(initial);
            break;
        case 3:
            ClearScreen();
            initial.printState();
            break;
        case 4:
            ClearScreen();
            cout << "Terminando programa...";
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
        }
    } while (true);

};

//---------------------------- SECCION MAIN  ------------------------------------------------//

int main() {
    menu();
    return 0;
}

