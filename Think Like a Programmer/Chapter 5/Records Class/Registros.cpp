#include "Registros.h"
#include <iostream>

Registros::Registros()
{
    //ctor
    _cabeza = nullptr;
}

Registros::~Registros()
{
    //dtor
    elimiarLista(_cabeza);
}

Registros::Registros(const Registros &otro)
{
    //copy ctor
    _cabeza = copiarLista(otro._cabeza);
}

Registros& Registros::operator=(const Registros& rhs)
{
    if (this != &rhs)
    {
        elimiarLista(_cabeza);
        _cabeza = copiarLista(rhs._cabeza);
    }// handle self assignment
    //assignment operator

    return *this;
}

void Registros::agregar(int id, int nota)
{
    nodo *nuevo = new nodo;
    nuevo->id = id;
    nuevo->nota = nota;
    nuevo->next = _cabeza;
    _cabeza = nuevo;
}

double Registros::promediar()
{
   nodo *actual = _cabeza;
   int cont = 0, suma = 0;
   while(actual != nullptr)
   {
        suma += actual->nota;
        cont++;
        actual = actual->next;
   }
   return suma / cont;
}

void Registros::eliminar(int id)
{
    nodo *temporal = _cabeza;
    nodo *anterior = nullptr;

    while(temporal != nullptr && temporal->id != id)
    {
        anterior = temporal;
        temporal = temporal->next;
    }
    if(temporal == nullptr) return;
    //Si es el primero a borrar
    if(anterior == nullptr)
    {
        _cabeza = _cabeza->next;
    }
    else
    {
        anterior->next = temporal->next;
    }
    delete temporal;
}

void Registros::mostrar()
{
    nodo *actual = _cabeza;
    while(actual != nullptr)
    {

        std::cout << actual->id << " : " << actual->nota << '\n';
        actual = actual->next;
    }
}

Registros Registros::registroEnRango(int notaMin, int notaMax)
{
    Registros nuevaColeccion;

    nodo *actual = _cabeza;
    while(actual != nullptr)
    {
        if(actual->nota >= notaMin && actual->nota <= notaMax)
        {
            nuevaColeccion.agregar(actual->id, actual->nota);
        }
        actual = actual->next;
    }

    return nuevaColeccion;
}

Registros::lista Registros::copiarLista(const lista otra)
{
    //Si la lista esta vacia devuela igual
    if(otra == nullptr) return nullptr;
    //nueva lista que será devuelta
    lista nuevaLista = new nodo;
    //Copiar la cabeza de lista nueva
    nuevaLista->id = otra->id;
    nuevaLista->nota = otra->nota;
    //Nodo temporal que recorrerá desde el 2ndo item la lista a copiar
    nodo *otra_temporal = otra->next;
    //nodo temporal que irá siendo los elementos nuevos ya copiados
    nodo *nuevo_temporal = nuevaLista;

    while(otra_temporal != nullptr)
    {
        //como ya el 1er nodo esta copiado, el ste debe estar vacio
        //para realizar la copia que viene. Se llena y se repite el proceso
        nuevo_temporal->next = new nodo;
        nuevo_temporal = nuevo_temporal->next;
        nuevo_temporal->id = otra->id;
        nuevo_temporal->nota = otra->nota;
        //avanza al siguente nodo a copiar
        otra_temporal = otra_temporal->next;
    }
    //poner la cola
    nuevo_temporal->next = nullptr;
    return nuevaLista;
}

void Registros::elimiarLista(lista &listaPuntero)
{
    while(listaPuntero != nullptr)
    {
        nodo *temporal = listaPuntero;
        listaPuntero = listaPuntero->next;
        delete temporal;
    }
}

