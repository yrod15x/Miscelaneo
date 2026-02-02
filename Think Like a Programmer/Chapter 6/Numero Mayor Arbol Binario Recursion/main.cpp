#include <iostream>

/* 1. Caso base: No hay más bifurcaciones(siguiente nodo de cada rama es nulo).
      o el nodo raiz esta vacio (null)
   2. Hacer siempre dos llamadas recursivas; una parel siguente nodo de cada rama.
   3. Procesar el nodo raíz de acuerdo al problema.
   4. Devolver lo que se ha pedido.*/

struct nodoArbol
{
    int numero;
    nodoArbol *derecha;
    nodoArbol *izquierda;
};

typedef nodoArbol *arbol;

int valorMaximo(arbol raiz)
{
    //1. Caso Base
    if(raiz == nullptr) return 0;
    if(raiz->derecha == nullptr && raiz->izquierda == nullptr)
    {
        return raiz->numero;
    }
    //2. Llamadas recursivas
    int maxIzquierda = valorMaximo(raiz->izquierda);
    int maxDerecha = valorMaximo(raiz->derecha);
    //3. Procesar raíz
    int maximo = raiz->numero;
    if(maxIzquierda > maximo) maximo = maxIzquierda;
    if(maxDerecha > maximo) maximo = maxDerecha;
    //4. Devolver
    return maximo;
}

int main()
{

    return 0;
}
