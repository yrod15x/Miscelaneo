#include "Boton.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Boton::Boton()
{
    //ctor
    _posicion = sf::Vector2f(0.0f, 0.0f);
    _tamano = sf::Vector2f(50.0f, 50.0f);
    _boton.setSize(_tamano);
    _boton.setPosition(_posicion);
    _boton.setFillColor(sf::Color::White);

}

Boton::Boton(sf::Vector2f tamano, sf::Vector2f posicion, sf::Color colorFondo)
{
    _posicion = posicion;
    _tamano = tamano;
    _boton.setSize(_tamano);
    _boton.setPosition(_posicion);
    _boton.setFillColor(colorFondo);
}

Boton::~Boton()
{
    //dtor
}

void Boton::_ponerTexto()
{

}

void Boton::mostrar(sf::RenderWindow &ventana)
{
    //Cargar el tipo de fuente
    sf::Font font;
    if(!font.loadFromFile("sprite.otf"))
    {

        std::cerr << "Error\n";
        std::exit(-1);
    }
    _tamCaracter = _tamano.y / 4;
    _texto.setFont(font);
    _texto.setString("Drums");
    _texto.setCharacterSize(_tamCaracter);
    _texto.setColor(sf::Color::Black);
    _texto.setPosition((_posicion.x + _tamano.x / 6),
                       _posicion.y + _tamano.y / 4);

    ventana.draw(_boton);
    ventana.draw(_texto);
}
