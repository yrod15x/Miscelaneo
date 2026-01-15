#include "Bolita.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

Bolita::Bolita()
{
    //ctor
    _posicion.x = 0;
    _posicion.y = 0;
    setCirculo(10.0, _posicion, sf::Color::Yellow);
}

Bolita::Bolita(float radio, sf::Vector2f posicion, sf::Color color)
{
    setCirculo(radio, posicion, color);
}

Bolita::~Bolita()
{
    //dtor
}

void Bolita::setCirculo(float radio, sf::Vector2f posicion, sf::Color color)
{
    //Debo iniciar las velocidades en el constructor para que tengan efecto
    //al rebotar en los limites
    _radio = radio;
    _posicion = posicion;
    _color = color;
    _velocidad.x = std::rand() % 3 + 1;
    _velocidad.y = std::rand() % 3 + 1;
    _circulo.setRadius(_radio);
    _circulo.setPosition(_posicion);
    _circulo.setFillColor(_color);
}

void Bolita::setTexto(std::string texto)
{
    _texto = texto;
}

void Bolita::setTamtexto(int tamano)
{
    _tamTexto = tamano;
}

void Bolita::setOffSetTexto(int offsetAlt, int offSetAnc)
{
    _offSetTextAlt = offsetAlt;
    _offSetTextAnc = offSetAnc;
}

void Bolita::mostrar(sf::RenderWindow &ventana)
{
    sf::CircleShape circulo(_radio);
    circulo.setOrigin(_radio, _radio);
    circulo.setPosition(_posicion);
    circulo.setFillColor(_color);
    _circulo = circulo;

    sf::Font font;
    if(!font.loadFromFile("sprite.otf"))
    {
        std::cerr << "Error\n";
        std::exit(-1);
    }
    sf::Text numero;
    numero.setFont(font);
    numero.setString(_texto);
    numero.setCharacterSize(_tamTexto);
    numero.setColor(sf::Color::White);
    numero.setOrigin(_radio - _tamTexto + _tamTexto / _offSetTextAnc, _radio / _offSetTextAlt);
    numero.setPosition(_posicion);
    _numero = numero;

    ventana.draw(circulo);
    ventana.draw(_numero);

}

sf::CircleShape Bolita::getBolita()
{
    return _circulo;
}

bool Bolita::seChoca(Bolita &circulo)
{
    return _circulo.getGlobalBounds().intersects(circulo.getBolita().getGlobalBounds());
}

void Bolita::chocarPantalla(int limWidth, int limHeight)
{
    if(_posicion.x > limWidth - _radio || _posicion.x < _radio)
    {
        _velocidad.x *= -1;
    }
    if(_posicion.y >= limHeight - _radio || _posicion.y <= _radio)
    {
        _velocidad.y *= -1;
    }
}

void Bolita::mover(int limWidth, int limHeight)
{
    srand(time(NULL));
    _posicion.x += _velocidad.x;
    _posicion.y += _velocidad.y;
    chocarPantalla(limWidth, limHeight);
}

bool Bolita::colision(Bolita &otra)
{
    float posX = std::pow(otra.getBolita().getPosition().x - _circulo.getPosition().x , 2);
    float posY = std::pow(otra.getBolita().getPosition().y - _circulo.getPosition().y , 2);

    return (std::sqrt(posX + posY) < _circulo.getRadius() * 2) &&
            otra._tamTexto == _tamTexto;

}

std::string Bolita::getTexto()
{
    return _texto;
}
