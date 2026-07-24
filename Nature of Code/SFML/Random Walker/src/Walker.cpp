#include "Walker.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

int stepRandom()
{
    return (rand() % + 3) - 1;
}

Walker::Walker()
{
    //ctor
    _x = 0.0;
    _y = 0.0;
}

Walker::Walker(int x, int y)
{
    //ctor
    _x = x;
    _y = y;
}

void Walker::show(sf::RenderWindow &window)
{
    sf::CircleShape circle(5.f);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(sf::Vector2f(_x, _y));

    window.draw(circle);
}

void Walker::walk()
{
    srand(time(NULL));

    int xstep = stepRandom();
    int ystep = stepRandom();

    _x += xstep / 1.0;
    _y += ystep / 1.0;

}
