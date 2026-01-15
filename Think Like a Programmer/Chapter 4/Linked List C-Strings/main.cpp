#include <iostream>

/* Let’s create an implementation for strings that uses a linked list of characters
instead of dynamically allocated arrays. So we’ll have a linked list where the
data payload is a single char; this will allow strings to grow without having to re-
create the entire string. We’ll start by implementing the append and characterAt
functions.
Add a function to the linked-list string implementation called removeChars */

struct Cadena
{
    char caracter;
    Cadena *next;
};

typedef Cadena *texto;

void mostrar(texto lista)
{
    Cadena *actual = lista;
    while(actual != nullptr)
    {
        std::cout << actual->caracter;
        actual = actual->next;
    }
}

void agregar(texto& lista, char nuevoCar)
{
    //Agrega un caracter a la palabra
    Cadena *actual = lista;
    Cadena *temp = new Cadena;

    temp->caracter = nuevoCar;
    //Si la palabra esta vacia toma el argumento como cabeza y 1er item
    if(actual == nullptr)
    {
        lista = temp;
        return;
    }

    while(actual->next != nullptr)
    {
        actual = actual->next;
    }
    //Si encontró el final reasigna los punteros al final
    actual->next = temp;
}

void borrar(texto &lista, char caracter)
{
    Cadena *actual = lista;
    Cadena *anterior = actual;
    int cont = 0;

    if(actual->caracter == caracter)
    {
        anterior = actual->next;
        delete actual;
        lista = anterior;
        return;
    }

    while(actual->caracter != caracter)
    {
        if(cont == 0)
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

    if(actual)
    {
        //Se queda con su valor pero su va a puntar al nodo siguiente del que se
        //va a borrar. Ambos apuntan hacia al mismo nodo.
        anterior->next = actual->next;
        delete actual;
    }
}

char caracterEn(texto lista, int index)
{
    Cadena *actual = lista;
    int cont = 0;

    if(actual == nullptr)
    {
        std::cout << "La lista es vacia\n";
        return '\0';
    }

    while(actual->next != nullptr)
    {
        if(cont == index) return actual->caracter;
        actual = actual->next;
        cont++;
    }
    std::cout << "\nIndice fuera de la lista.\n";
    return '\0';
}

int main()
{
    texto palabra;
    Cadena *car = nullptr;
    //Iniacializar la cabeza - En este caso una lista vacia
    palabra = car;
    int cont  = 0;

    agregar(palabra, 'g');
    agregar(palabra, 'a');
    agregar(palabra, 't');
    agregar(palabra, 'u');
    agregar(palabra, 'n');
    agregar(palabra, 'o');

    //std::cout << caracterEn(palabra, 0) << '\n';
    //borrar(palabra, 'a');

    borrarCaracters(palabra, 1, 1);

    mostrar(palabra);

    return 0;
}
