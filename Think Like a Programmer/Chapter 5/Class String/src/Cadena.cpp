#include "Cadena.h"
#include <iostream>

Cadena::Cadena()
{
    //ctor
    //_cadena;
}

Cadena::~Cadena()
{
    //dtor
}

Cadena::Cadena(const Cadena& other)
{
    //copy ctor
}

int Cadena::getTamano()
{

    int tamano = 0;
    while(_cadena[tamano] != 0)
    {

        tamano++;
    }
    return tamano;
}

void Cadena::agregar(char car)
{
    //1. Se debe crear un temporal. Copiar la cadena antigua.
    //2. Agregar el nuevo caracter y el 0. Borrar el antiguo.
    //3. Asignar el temporal al antiguo.

    int tamano = getTamano();
    //1.

    Texto temporal = new char[tamano + 2];

    for(int i = 0; i < tamano; i++)
    {
        temporal[i] = _cadena[i];
    }
    //2.
    temporal[tamano] = car;
    temporal[tamano + 1] = 0;
    delete[] _cadena;
    //3.
    _cadena = temporal;
}

void Cadena::mostrar()
{
    for(int i = 0; i <= getTamano(); i++)
    {
        std::cout << _cadena[i];
    }
}
