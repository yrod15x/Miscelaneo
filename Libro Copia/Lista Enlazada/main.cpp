#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo
{
    int numero;
    Nodo *next;
};

typedef Nodo *listAleatorios;

void agregar(listAleatorios &lista, int numero)
{
    Nodo *nuevo = new Nodo;
    nuevo->numero = numero;
    nuevo->next = lista;
    lista = nuevo;
}

void agregarAlFinal(listAleatorios &lista, int numero)
{
    Nodo *nuevo = new Nodo;
    Nodo *temp = new Nodo;
    nuevo->numero = numero;
    nuevo->next = nullptr;
    //Si la lista esta vacia agregarlo como cabeza
    if(lista == nullptr)
    {
        lista = nuevo;
    }

    temp = lista;
    //Buscar el ultimo nodo
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nuevo;
}

void mostrar(listAleatorios lista)
{
    if(lista == nullptr || lista->next == nullptr) return;
    mostrar(lista->next);
    std::cout << lista->numero << " ";
}

void borrarPorLimite(listAleatorios &lista, int limite)
{
    //Se necesitan dos nodos para ir trackeando el anterior al buscado
    Nodo *actual = lista;
    Nodo *anterior = actual;
    int cont = 1;

    //Si el nodo a borrar es la cabeza, el segundo debe quedar como ella
    if(actual->numero >= limite)
    {
        //Anterior almacena al segundo para borrar la cabeza
        anterior = actual->next;
        delete actual;
        lista = anterior;
        return;
    }
    //Recorrer la lista en busca de los números a borrar
    while(actual->next != nullptr)
    {
        //Si es el primer nodo no dejes avanzar a anterior. Solo actual
        if(cont == 1)
        {
            actual = actual->next;
        }
        else
        {
            //Trackea el previo mientras avanzas. Borra si encuentras el objetivo
            if(actual->numero >= limite)
            {
                /*Reorganiza los nodos.
                1. Se guarda el posterior al que se va borrar.
                2. Se borrar el objetivo
                3. El nodo actual es posterior al que ya se borró */
                anterior->next = actual->next;
                delete actual;
                actual = anterior->next;
            }
            else
            {
                //Avanza ambos nodos sabiendo el anterior se va guardando
                actual = actual->next;
                anterior = anterior->next;
            }
        }
        cont++;
    }
}

int generarNumeros(int minimo, int maximo)
{
    return (rand() % maximo) + minimo;
}

int main()
{
    srand(time(NULL));
    listAleatorios lista;

    for(int i = 0; i < 10; i++)
    {
        agregarAlFinal(lista, generarNumeros(1, 100));
    }

    mostrar(lista);

    borrarPorLimite(lista, 50);
    std::cout << '\n';

    mostrar(lista);

    return 0;
}
