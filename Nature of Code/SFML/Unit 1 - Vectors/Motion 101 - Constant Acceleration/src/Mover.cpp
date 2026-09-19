#include "Mover.h"
#include <SFML/Graphics.hpp>
#include <random>

int randNumber(int low, int high)
{
    static thread_local std::mt19937 randEngine(std::random_device{}());
    std::uniform_int_distribution<int> dist(low, high);
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
    int randWidth = randNumber(0, width);
    int randHeight = randNumber(0, height);
    _position = sf::Vector2f{randWidth, randHeight};
    _velocity = sf::Vector2f{0,0};
    _acceleration = sf::Vector2f{-0.001f, 0.01f};
    _topSpeed = 10;
}

void Mover::_limit()
{
    if(_velocity.length() > _topSpeed)
    {

    }
}

Mover::~Mover()
{
    //dtor
}

void Mover::update()
{
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
