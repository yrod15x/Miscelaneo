#include "Tecla.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Tecla::Tecla()
{
    //ctor
    setTecla(sf::Vector2f(100.0f, 100.0f),sf::Vector2f(0, 0),
             sf::Color::White, "-1", sf::Color::Red);
}

Tecla::~Tecla()
{
    //dtor
}

void Tecla::setTecla(sf::Vector2f tamano, sf::Vector2f posicion,
                     sf::Color bgcolor, std::string caracter = "-1",
                     sf::Color colCaracter = sf::Color::Red)
{
    _tamano = tamano;
    _posicion = posicion;
    _bgcolor = bgcolor;
    _caracter = caracter;
    _colCaracter = colCaracter;
}

Tecla::Tecla(const Tecla& other)
{
    //copy ctor
}

void Tecla::setPosicion(sf::Vector2f posicion)
{
    _posicion = posicion;
}

void Tecla::setCaracter(char caracter)
{
    std::string carStr = " ";
    carStr[0] = caracter;
    _caracter = carStr;
}

bool Tecla::hayClick(sf::RenderWindow &ventana)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(ventana);

    return(_tecla.getGlobalBounds().contains(static_cast<float>(mousePos.x),
                                             static_cast<float>(mousePos.y)));
}

std::string Tecla::getCaracter()
{
    return _caracter;
}

void Tecla::mostrar(sf::RenderWindow &ventana)
{
    _tecla.setPosition(_posicion);
    _tecla.setFillColor(_bgcolor);
    _tecla.setSize(_tamano);

    //Poner letra
    sf::Font fuente;
    if(!fuente.loadFromFile("fuente.ttf"))
    {
        std::cerr << "Fuente no cargada\n";
        std::exit(-1);
    }
    sf::Text caracter;
    caracter.setFont(fuente);
    caracter.setString(_caracter);
    caracter.setCharacterSize(_tamano.y - _tamano.y / 4);
    caracter.setColor(_colCaracter);
    //caracter.setOrigin(_tamano.x / 2, _tamano.y /2);

    //Centrar texto
    sf::FloatRect figuraProp = _tecla.getGlobalBounds();
    sf::FloatRect caractProp = caracter.getLocalBounds();
    caracter.setPosition(figuraProp.left +
                         (figuraProp.width - caractProp.width) / 2.5,
                          figuraProp.top + (figuraProp.height -
                          caractProp.height) / (_tamano.y / 2));
    ventana.draw(_tecla);
    ventana.draw(caracter);
}
