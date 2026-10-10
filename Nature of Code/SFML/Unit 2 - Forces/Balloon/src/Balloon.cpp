/* Simula un objeto que sube con aceleración a un tope superior y rebota
 con una fuerza inversa. Su movimiento horizontal puede ser afectado
 por otra fuerza.*/

#include "Balloon.h"
#include <random>

float randFloatNumber(float low, float high)
{
    static thread_local std::mt19937 randEngine(std::random_device{}());
    static thread_local std::uniform_real_distribution<float> dist(low, high);
    return dist(randEngine);
}

Balloon::Balloon(int width, int height, int radio)
{
    //ctor
    _radio = radio;
    _position = sf::Vector2f{randFloatNumber(_radio, width - _radio),
                             static_cast<float>(height - _radio * 2)};
    _velocity = sf::Vector2f{0.0f, 0.0f};
    _acceleration = sf::Vector2f{0.0f, 0.0f};
    _topSpeed = 2.0;
}

Balloon::~Balloon()
{
    //dtor
}

void Balloon::show(sf::RenderWindow &window)
{
    sf::CircleShape balloon(_radio);
    balloon.setPosition(_position);
    balloon.setFillColor(sf::Color(255, 192, 203));
    window.draw(balloon);
}

void Balloon::update()
{
    capSpeed();
    _acceleration.y = -0.01;
    _velocity += _acceleration;
    _position += _velocity;
    //Se necesita reiniciar la aceleración para que puedan actuar varias
    //fuerzas en el objeto
    _acceleration *= 0.0f;
}

void Balloon::capSpeed()
{
    /*Permite que la velocidad no supere un valor demasiado grande al
    ir agregando la acceleración */
    if(_velocity.length() > _topSpeed)
    {
        _velocity = _velocity.normalized() * _topSpeed;
    }
}

void Balloon::checkBorders(int width)
{
    if(_position.y < 0)
    {
        //Hace rebotar con una fuerza inversa
        _acceleration.y = 1;
        _velocity += _acceleration;
    }
    if(_position.x > width)
    {
        _position.x = 0;
    }
    else if(_position.x < 0)
    {
        _position.x = width;
    }
}

void Balloon::applyForce(sf::Vector2f force)
{
    _acceleration += force;
}
