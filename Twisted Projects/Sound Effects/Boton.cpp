#include "Boton.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cmath>

Boton::Boton()
{
    //ctor
    _posicion = sf::Vector2f(0.0f, 0.0f);
    _tamano = sf::Vector2f(50.0f, 50.0f);
    _boton.setSize(_tamano);
    _boton.setPosition(_posicion);
    _boton.setFillColor(sf::Color::White);
    _nombre = "";
}

Boton::Boton(sf::Vector2f tamano, sf::Vector2f posicion, sf::Color colorFondo,
             std::string nombre)
{
    _posicion = posicion;
    _tamano = tamano;
    _nombre = nombre;
    _boton.setSize(_tamano);
    _boton.setPosition(_posicion);
    _boton.setFillColor(colorFondo);
}

Boton::~Boton()
{
    //dtor
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
    _texto.setString(_nombre);
    _texto.setCharacterSize(_tamCaracter);
    _texto.setColor(sf::Color::Black);

    /*Centrar el texto. getLocalBounds nos da las dimension y posiciones
     del objeto. left -> cord.x,top-> cord. Width y height tamano  */
    sf::FloatRect rectBounds = _boton.getGlobalBounds();
    sf::FloatRect textBounds = _texto.getLocalBounds();
    /*La diferencia entre el ancho del texto y el objeto. Da el offset que se
    divide entre dos para el texto tenga el espacio a derecha e izquierda */
    _texto.setPosition(rectBounds.left + (rectBounds.width - textBounds.width) / 2,
                       rectBounds.top + (rectBounds.height - textBounds.height) / 2);

    ventana.draw(_boton);
    ventana.draw(_texto);
}

bool Boton::hayClick(sf::Vector2i mousePos)
{
    return (_boton.getGlobalBounds().contains(static_cast<float>(mousePos.x),
    static_cast<float>(mousePos.y)));
}

std::string Boton::getNombre()
{
    return _nombre;
}


