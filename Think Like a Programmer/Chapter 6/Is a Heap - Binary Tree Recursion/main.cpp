/* Some words in programming have more than one common meaning. In
Chapter 4, we learned about the heap, from which we get memory allocated
with new. The term heap also describes a binary tree in which each node value
is higher than any in the left or right subtree. Write a recursive function to
determine whether a binary tree is a heap. */

#include <iostream>

struct arbol
{
    int numero;
    arbol *derecha;
    arbol *izquierda;

    arbol(int val) : numero(val), derecha(nullptr), izquierda(nullptr) {};
};

typedef arbol *colNumeros;

void imprimir(colNumeros numeros)
{
    if(numeros == nullptr) return;

    imprimir(numeros->izquierda);
    imprimir(numeros->derecha);
    std::cout << numeros->numero << " ";
}

bool esHeap(colNumeros numeros)
{
    if(numeros == nullptr) return false;
    if(numeros->derecha == nullptr && numeros->izquierda == nullptr)
    {
        return true;
    }
    bool izquierdo = esHeap(numeros->izquierda);
    bool derecho = esHeap(numeros->derecha);
    if(numeros->izquierda != nullptr && numeros->numero < numeros->izquierda->numero)
    {
        return false;
    }
    if(numeros->derecha != nullptr && numeros->numero < numeros->derecha->numero)
    {
        return false;
    }
    return (izquierdo && derecho);
}

int main()
{
    colNumeros numeros = new arbol(1);

    numeros->derecha = new arbol(6);
    numeros->izquierda = new arbol(5);
    numeros->derecha->derecha = new arbol(4);
    numeros->derecha->izquierda = new arbol(3);
    numeros->izquierda->derecha = new arbol(2);
    numeros->izquierda->izquierda = new arbol(1);

    std::cout << esHeap(numeros) << '\n';

    return 0;
}
