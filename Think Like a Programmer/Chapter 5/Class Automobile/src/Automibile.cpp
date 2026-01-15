#include "Automibile.h"
#include <iostream>
#include <ctime>

Automibile::Automibile()
{
    //ctor
    _nombre = "";
    _modelo = "";
    _annio = 0;
}

Automibile::Automibile(std::string nombre, std::string modelo, int annio)
{
    setNombre(nombre);
    setModelo(modelo);
    setAnnio(annio);
}

void Automibile::setNombre(std::string nombre)
{
    _nombre = nombre;
}

void Automibile::setModelo(std::string modelo)
{
    _modelo = modelo;
}

void Automibile::setAnnio(int annio)
{
    _annio = annio;
}

std::string Automibile::getNombre()
{
    return _nombre;
}

std::string Automibile::getModelo()
{
    return _modelo;
}

int Automibile::getAnnio()
{
    return _annio;
}

void Automibile::descripcion()
{
    std::cout << _annio << " " << _nombre << " " << _modelo << "\n";
}

int Automibile::getEdad()
{
    //Devuelve los años en servicio del auto respecto al año actual
    std::time_t tiempo = time(NULL);
    std::tm *ahora = std::localtime(&tiempo);

    return (ahora->tm_year + 1900) - _annio;

}
