/* Programa que crea una lista enlazada para construir un texto.
Permite agregar y borrar una palabra*/

#include <iostream>
#include <string>

struct Nodo
{
    std::string palabra;
    Nodo *next;
};

typedef Nodo *Lista;

void agregar(Lista &texto, std::string palabra)
{
    Nodo *nuevo = new Nodo;
    Nodo *temp = new Nodo;
    nuevo->palabra = palabra;
    nuevo->next = nullptr;

    //Si lista vacia se hace cabeza
    if(texto == nullptr)
    {
        texto = nuevo;
        return;
    }
    //Buscar el último nodo
    temp = texto;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nuevo;
}

void imprimir(Lista texto)
{
    Nodo *temp = texto;
    while(temp != nullptr)
    {
        std::cout << temp->palabra;
        temp = temp->next;
    }
}

void borrar(Lista &texto, std::string palabra)
{
    Nodo *actual = texto;
    Nodo *anterior = actual;
    int cont = 1;

    //Si es el primero nodo a borrar, el 2do se vuelve la cabeza
    if(actual->palabra == palabra)
    {
        anterior = actual->next;
        delete actual;
        texto = anterior;
        return;
    }
    //Mira si puedes encontrar el nodo a borrar
    while(actual != nullptr && actual->palabra != palabra)
    {
        //Solo avanza el anterior si no es el primero nodo
        if(cont == 1)
        {
            actual = actual->next;
        }
        else
        {
            actual = actual->next;
            anterior = anterior->next;
        }
        cont++;
    }
    //Si encontró el nodo a borrar. Anterior apunta al nodo posterior a actual
    if(actual)
    {
        anterior->next = actual->next;
        delete actual;
    }
}

int main()
{
    Lista texto = nullptr;

    agregar(texto, "hola");
    agregar(texto, " pola");
    imprimir(texto);
    borrar(texto, "hola");
    imprimir(texto);

    return 0;
}
