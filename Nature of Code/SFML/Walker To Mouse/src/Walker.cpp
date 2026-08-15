#include "Walker.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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

void Walker::walk(sf::RenderWindow &window)
{

    float xstep = 0.1;
    /*Se debe buscar la posición local del mouse, es decir con
     relación a la pantalla de la aplicación y no la del monitor. Por
     eso se pone el objeto window dentro de la función getPosition(window) */
    sf::Vector2i posMouse = sf::Mouse::getPosition(window);

    (_x > posMouse.x) ? _x -= xstep : _x += xstep;
    (_y > posMouse.y) ? _y -= xstep : _y += xstep;

}
