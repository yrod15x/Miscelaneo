/*Consider a linked list representing a binary string, where every element’s data
value is 0 or 1. Write a bool function to determine whether the binary string
has odd parity (an odd number of 1 bits). Hint: Remember that the recursive
function is going to return true (odd) or false (even), not the count of 1 bits.
Solve the problem first using iteration, then recursion */

#include <iostream>

struct Nodo
{
    char numero;
    Nodo *next;
};

typedef Nodo *listaNums;

void agregar(listaNums &numeros, char numero)
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

bool tieneParidadRec(listaNums numeros)
{
    if(numeros == nullptr) return 0;
    bool resto = tieneParidadRec(numeros->next);
    int unos = 0;
    unos += (numeros->numero == '1') ? 1 : 0;
    bool esPar = (unos - 1 == 0);
    return (esPar == resto);
}


int main()
{
    listaNums numeros;

    agregar(numeros, '1');
    agregar(numeros, '1');
    agregar(numeros, '1');
    agregar(numeros, '1');
    agregar(numeros, '1');

    std::cout << tieneParidadRec(numeros);

    return 0;
}
