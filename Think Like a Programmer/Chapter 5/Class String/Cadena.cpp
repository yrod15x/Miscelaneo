#include "Cadena.h"
#include <iostream>
#include <string>


Cadena::Cadena()
{
    //ctor
    //_cadena;
}

Cadena::~Cadena()
{
    //dtor
    delete[] _cadena;
}

Cadena::Cadena(Cadena &otra)
{
    //copy ctor
    int tamano = otra.getTamano();
    _cadena = new char[tamano];
    for(int i = 0; i < tamano; i++)
    {
        _cadena[i] = otra._cadena[i];
    }
}

Cadena::Cadena(const std::string &otra)
{
    int tamano = otra.size();
    _cadena = new char[tamano];
    for(int i = 0; i < tamano; i++)
    {
        _cadena[i] = otra[i];
    }
}

void Cadena::_rellenar(Texto &temp, int tamano)
{
    for(int i = 0; i < tamano; i++)
    {
        temp[i] = _cadena[i];
    }
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

    _rellenar(temporal, tamano);
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

char Cadena::caracterEn(int index)
{
    int tamano = getTamano();
    if(index < 0 || index > tamano) return -1;
    return _cadena[index];
}

void Cadena::concadenar(Cadena &otra)
{
    int tamCadena1 = otra.getTamano();
    int tamCadena2 = getTamano();
    Texto temporal = new char[tamCadena1 + tamCadena2 + 1];
    _rellenar(temporal, tamCadena2);

    for(int i = 0; i < tamCadena1; i++)
    {
        temporal[i + tamCadena2] = otra._cadena[i];
    }

    temporal[tamCadena1 + tamCadena2] = 0;
    delete[] _cadena;
    _cadena = temporal;

}

void Cadena::borrar(int inicio = 0, int limFinal = 0)
{
    int tamCadena = getTamano();
    int tam = 0;
    int mayor, menor;
    if (inicio > limFinal)
    {
        mayor = inicio;
        menor = limFinal;
    }
    else
    {
        mayor = limFinal;
        menor = inicio;
    }
    int nuevoTam = tamCadena - (mayor - menor) + 1;

    if(mayor + menor > tamCadena)
    {
        std::cout << "Indices fuera de limites\n";
        exit(0);
    }
    Texto temporal = new char[nuevoTam];

    for(int i = 0; i < tamCadena; i++)
    {
        if(i < inicio || i > inicio + limFinal - 1)
        {
            temporal[tam] = _cadena[i];
            tam++;
        }
    }
    temporal[tam] = 0;
    delete[] _cadena;
    _cadena = temporal;
}

Cadena& Cadena::operator=(Cadena rhs)
{
    if(this != &rhs)
    {
        int tamano = rhs.getTamano();
        for(int i = 0; i < tamano; i++)
        {
            _cadena[i] = rhs._cadena[i];
        }
        _cadena[tamano] = 0;
    }
    return *this;
}

char& Cadena::operator[](int index)
{

    if(index < 0 || index >= getTamano())
    {
        std::cout << "Indice fuera de limites\n";
        exit(0);
    }
    return _cadena[index];
}
