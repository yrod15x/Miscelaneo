/* Programa que cuenta mediante una función recursiva cuantos
 postivos hay en unalista enlazada */

#include <iostream>

struct Nodo
{
    int numero;
    Nodo *next;
};

typedef Nodo *listaNums;

void agregar(listaNums &numeros, int numero)
{
    Nodo *nuevo = new Nodo;
    nuevo->numero = numero;
    nuevo->next = numeros;
    numeros = nuevo;
}

void imprimir(listaNums numeros)
{
    if(numeros == nullptr || numeros->next == nullptr) return;
    imprimir(numeros->next);
    std::cout << numeros->numero << " ";
}

int contarPositivos(listaNums numeros)
{
    if(numeros == nullptr) return 0;
    int positivos = contarPositivos(numeros->next);
    if(numeros->numero > 0) positivos++;
    return positivos;
}

int main()
{
    listaNums numeros;

    agregar(numeros, 34);
    agregar(numeros, 6);

    std::cout << contarPositivos(numeros) << '\n';

    return 0;
}
