#include "Boton.h"
#include <SFML/Graphics.hpp>

Boton::Boton()
{
    //ctor
    _boton.setSize(sf::Vector2f(50.0f, 50.f));
    _boton.setPosition(0, 0);
    _boton.setFillColor(sf::Color::White);

}

Boton::Boton(sf::Vector2f tamano, float x, float y, sf::Color colorFondo)
{
    _boton.setSize(tamano);
    _boton.setPosition(sf::Vector2f(650.0f, 150.f));
    _boton.setFillColor(colorFondo);
}

Boton::~Boton()
{
    //dtor
}

void Boton::_ponerTexto()
{
    //Cargar el tipo de fuente
    sf::Font font;
    if(!font.loadFromFile("sprite.otf"))
    {
        std::cerr << "Error\n";
        std::exit(-1);
    }
    _texto.setFont(font);
    _texto.setString("Btn");
    _texto.setCharacterSize(_tamTexto);
    _texto.setColor(sf::Color::Red);
    _texto.setPosition();
}

void Boton::mostrar(sf::RenderWindow &ventana)
{
    ventana.draw(_boton);
}
