/* Write a function that is passed a linked list of integers and a “target” number
and that returns the number of occurrences of the target in the linked list.*/

#include <iostream>

struct Nodo
{
    int numero;
    Nodo *next;
};

typedef Nodo *listaNumeros;

void agregar(listaNumeros &numeros, int numero)
{
    Nodo *nuevo = new Nodo;

    nuevo->numero = numero;
    nuevo->next = numeros;
    numeros = nuevo;
}

void imprimir(listaNumeros numeros)
{
    if(numeros->next == nullptr) return;
    imprimir(numeros->next);
    std::cout << numeros->numero << " ";
}

int recurrencias(listaNumeros numeros, int objetivo)
{
    if(numeros == nullptr) return 0;
    int suma = recurrencias(numeros->next, objetivo);
    if(numeros->numero == objetivo) suma++;
    return suma;
}

int main()
{
    listaNumeros numeros;

    agregar(numeros, 5);
    agregar(numeros, 1);
    agregar(numeros, 3);
    agregar(numeros, 5);
    agregar(numeros, 5);

    std::cout << recurrencias(numeros, 5);

    return 0;
}
