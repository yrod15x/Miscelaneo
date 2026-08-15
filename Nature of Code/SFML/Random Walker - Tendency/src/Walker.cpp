#include "Walker.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

int stepRandom()
{
    return (rand() % + 100) + 1;
}

Walker::Walker()
{
    //ctor
    _x = 0.0;
    _y = 0.0;
}

Walker::Walker(float x, float y)
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

    float xstep = 0.1;
    float ystep = 0.1;

    int tendency = stepRandom();

    if(tendency < 60)
        {
            _x -= xstep;
            _y -= ystep;
        }
        else if(tendency < 70)
        {
            _x += xstep;
            _y -= ystep;
        }
        else if(tendency < 80)
        {
            _x += xstep;
            _y += ystep;
        }
        else
        {
            _x -= xstep;
            _y += ystep;
        }
}
