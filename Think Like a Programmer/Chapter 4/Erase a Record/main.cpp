#include <iostream>
#include <string>

struct Pelicula
{
    std::string nombre;
    int annio;
    Pelicula *next;
};

//Movies un array para meter los nodos
typedef Pelicula *movies;

void agregarPelicula(movies& lista, std::string nombre, int annio)
{
    //crear el nodo temporal
    Pelicula *nuevoNodo = new Pelicula;
    //Asignar los datos a cada nodo
    nuevoNodo->nombre = nombre;
    nuevoNodo->annio = annio;
    //Remplazar la cabeza antigua apuntadola con este nodo temporal
    nuevoNodo->next = lista;
    //El temporal quede en la cabeza
    lista = nuevoNodo;
}

void imprimirRegistros(movies lista)
{
    Pelicula *actual = lista;
    while(actual != nullptr)
    {
        std::cout << actual->nombre << " : " << actual->annio << '\n';
        actual = actual->next;
    }
}

void borrarRegistro(movies &lista, std::string nombre)
{
    /*La idea es llevar registro del nodo actual y del previo. El previo se necesita
    para reasignar el nodo al cual apuntaba el que va a ser borrado*/
    Pelicula *actual = lista;
    Pelicula *anterior = actual;
    int cont = 1;
    //Si el nodo a borrar es la cabeza. Poner el segundo a apuntar a la cabeza
    if(actual->nombre == nombre)
    {
        anterior = actual->next;
        delete actual;
        lista = anterior;
        return;
    } 
    //El ciclo sólo llega hasta hasta encontrar el nodo a borrar
    while (actual != nullptr && actual->nombre != nombre)
    {
        //Mirar si encuentra el nodo a borrar. Previo no se mueve y quedar como anterior
        if(cont == 1)
        {
            actual = actual->next;
        } 
        else
        {
            //Después del segundo nodo se avanza el previo y el actual
            actual = actual->next;
            anterior = anterior->next;
        }
        cont++;
    }
    //Si se encontró el nodo. El previo apunta al que esta después del borrado
    if(actual)
    {
        anterior->next = actual->next;
        delete actual;
    }    
}

int main()
{
    
    movies listaPeliculas = nullptr;

    agregarPelicula(listaPeliculas, "It", 2021);
    agregarPelicula(listaPeliculas, "Terminator", 1989);
    agregarPelicula(listaPeliculas, "Blade Runner", 1986);

    borrarRegistro(listaPeliculas, "Terminator");
    imprimirRegistros(listaPeliculas);

    return 0;
}