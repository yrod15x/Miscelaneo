#include "Walker.h"
#include <SFML/Graphics.hpp>
#include "PerlinNoise.hpp"
#include <ctime>
#include <iostream>

int stepRandom()
{
    return (rand() % + 10) + 1;
}

Walker::Walker()
{
    //ctor
    _dx = 0.0;
    _dy = 100.0;
    _x = 0.0;
    _y = 0.0;

}

Walker::Walker(float x, float y)
{
    //ctor
    _dx = 0;
    _dy = 10000;
    _x = x;
    _y = y;
    noise.reseed(123456u * stepRandom()/2) ;
}

Walker::~Walker()
{
    //dtor
}

void Walker::walk(float windowWidth, float windowHeight)
{
    //Semilla

    float noise1 = noise.noise1D(_dx);
    float noise2 = noise.noise1D(_dy);

    //std::cout << noise1 << " - " << noise2 << '\n';

    _x = noise1 * windowWidth;
    _y = noise2 * windowHeight;
    _dx += 0.01;
    _dy += 0.01;
}

void Walker::show(sf::RenderWindow &window)
{
    sf::CircleShape walker(5.0f);
    walker.setFillColor(sf::Color::Cyan);
    walker.setPosition(sf::Vector2f(_x + 600, _y + 400));

    window.draw(walker);
}
