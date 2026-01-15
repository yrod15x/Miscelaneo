/* Imagine a linked list where instead of the node storing a character, the node
stores a digit: an int in the range 0–9. We could represent positive numbers
of any size using such a linked list; the number 149, for example, would be a
linked list in which the first node stores a 1, the second a 4, and the third and
last a 9. Write a function intToList that takes an integer value and produces a
linked list of this sort.

For the digit list of the previous exercise, write a function that takes two such
lists and produces a new list representing their sum.*/

#include <iostream>

//Crear el nodo que esla unidad de la lista.
struct Digito
{
    int num;
    Digito *siguiente;
};
//Crear el tipo colección que hará las veces de contenedor de los nodos.
typedef Digito *Numero;

int getTamano(Numero numero)
{
    Digito *actual = new Digito;
    actual = numero;
    int tam = 0;

    while(actual != nullptr)
    {
        tam++;
        actual = actual->siguiente;
    }
    return tam;
}

void quitarDigito(int &num, int &digi)
{
    digi = num % 10;
    num /= 10;
}

void agregarDelante(Numero &numero, int dato)
{
    //Crear el nodo nuevoTemporal
    Digito *nuevoTemp = new Digito;
    //Asigno los datos
    nuevoTemp->num = dato;
    //Apunta al que era cabeza antes- La colección es representada por su primer nodo
    nuevoTemp->siguiente = numero;
    //Temporal queda a la cabeza de la coleccion
    numero =  nuevoTemp;
}

void agregarCompuesto(Numero &numero, int cantidad)
{
    int digi;
    while(cantidad > 0)
    {
        quitarDigito(cantidad, digi);
        agregarDelante(numero, digi);
    }

}

void mostrar(Numero numero)
{
    Digito *actual = new Digito;
    actual = numero;

    while (actual != nullptr)
    {
        std::cout << actual->num;
        actual = actual->siguiente;
    }
    std::cout << '\n';
}

int digitToNum(Numero numero, int tamano)
{
    int resultado = 0;
    Digito *actual = new Digito;
    actual = numero;
    int ceros = 1;

    for(int i = 0; i < tamano - 1; i++)
    {
        ceros *= 10;
    }

    while(actual != nullptr)
    {
        resultado += actual->num * ceros;
        ceros /= 10;
        actual = actual->siguiente;
    }

    return resultado;
}

int sumar(Numero num1, Numero num2)
{
    int tamNum1 = getTamano(num1);
    int tamNum2  = getTamano(num2);

    return digitToNum(num1, tamNum1) + digitToNum(num2, tamNum2);
}

int main()
{
    //Crear la colección contenedora
    Numero numero;
    Digito *nodo = nullptr;

    Numero numero2;
    Digito *nodo2 = nullptr;

    numero = nodo;
    agregarCompuesto(numero, 36);
    numero2 = nodo2;
    agregarCompuesto(numero2, 40);

    std::cout << sumar(numero, numero2);
    //mostrar(numero);

    return 0;
}
