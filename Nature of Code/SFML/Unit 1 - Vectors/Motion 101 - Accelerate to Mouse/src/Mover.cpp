/* Clase que genera una plantilla para que un objeto se mueva por pantalla
usando vectores con una velocidad influida por una aceleración aleatoria.*/

#include "Mover.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <ctime>

int randNumber(int low, int high)
{
    static thread_local std::mt19937 randEngine(std::random_device{}());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(randEngine);
}

float randFloatNumber(float low, float high)
{
    static thread_local std::mt19937 randEngine(std::random_device{}());
    static thread_local std::uniform_real_distribution<float> dist(low, high);
    return dist(randEngine);
}

Mover::Mover()
{
    //ctor
    _position = sf::Vector2f{0.0f, 0.0f};
    _velocity = sf::Vector2f{0.0f, 0.0f};
}

Mover::Mover(unsigned int width,unsigned int height)
{
    //srand(NULL);
    int randWidth = randNumber(0, width);
    int randHeight = randNumber(0, height);
    _position = sf::Vector2f{randWidth, randHeight};
    _velocity = sf::Vector2f{0.0f, 0.0f};
    _acceleration = sf::Vector2f{0.0f, 0.0f};
    //Variable que permite virar y acelear hacia al mouse
    _direction = sf::Vector2f{0.0f, 0.0f};
    _topSpeed = 10;
    _scale = randFloatNumber(0.1, 1.0);
    std::cout << _scale << '\n';
}
/*Permite que la velocidad no supere un valor demasiado grande al ir
agregando la acceleración */
void Mover::_limit()
{
    if(_velocity.length() > _topSpeed)
    {
        //Multiplica la velocidad normalizada (1) por el tope
        _velocity = _velocity.normalized() * _topSpeed;
    }
}

Mover::~Mover()
{
    //dtor
}

void Mover::update(sf::RenderWindow &window)
{
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    //Calcular la dirección para que se mueva hacia el mouse
    _direction = sf::Vector2f{mouse} - _position;
    //Normalizar y escalar
    _direction = _direction.normalized() * _scale;
    _acceleration = _direction;
    _velocity += _acceleration;
    _limit();
    _position += _velocity;
}

void Mover::show(sf::RenderWindow &window)
{
    sf::CircleShape mover(40);
    mover.setPosition(_position);
    mover.setFillColor(sf::Color{0, 200, 0});
    window.draw(mover);
}

void Mover::checkEdeges(unsigned int width, unsigned int height)
{
    if(_position.x > width)
    {
        _position.x = 0;
    }
    else if(_position.x < 0)
    {
        _position.x = width;
    }
    if(_position.y > height)
    {
        _position.y = 0;
    }
    else if(_position.y < 0)
    {
        _position.y = height;
    }
}
