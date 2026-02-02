#include <iostream>

struct Nodo
{
    int numero;
    Nodo *next;
};

typedef Nodo *lista;

void agregar(lista &coleccion, int numero)
{
    Nodo *temporal = new Nodo;
    temporal->numero = numero;
    temporal->next = coleccion;
    coleccion = temporal;
}

void imprimir(lista cabeza)
{
    //Caso base en LL es cuando se llega al último elemento o esta vacia
    if(cabeza == nullptr) return;
    //llamada recursiva al siguiente nodo
    imprimir(cabeza->next);
    //procesamiento de los nodos
    std::cout << cabeza->numero << " ";
}

/* lista = [2, -4, 6].
1er->next vacio ? No
2do-> next vacio ? No
3ro->next vacio ? Si => cont = 0
3ro->Num < 0 ? No => cont = 0
2nd->Num < 0 ? Si => cont = 1
1ro->Num < 0 ? No => cont = 1
*/

int contarNegativos(lista cabeza)
{
    //Caso base: Cuando no hay mas nodos, no hay nigún número (+ o -)
    if(cabeza == nullptr) return 0;
    //llamada recursiva: se hace con los nodos que van quedando en la lista
    std::cout << cabeza->numero << '\n';
    int contador = contarNegativos(cabeza->next);
    //Procesar los datos de los nodos. Cada nodo arrojará 0 o 1 si es negativo
    if(cabeza->numero < 0) contador++;
    //Devolver la acción requierida
    return contador;
}

int main()
{
    lista coleccion = nullptr;
    agregar(coleccion, 8);
    agregar(coleccion, 1);
    agregar(coleccion, -2);
    agregar(coleccion, 7);
    agregar(coleccion, -5);

    imprimir(coleccion);

    std::cout << '\n' << contarNegativos(coleccion) << '\n';

    return 0;
}
