/* Utiliza una distribución de probabilidad personalizada para variar el
tamaño de un paso dado por el aleatorio Walker. El tamaño del paso puede
 determinarse influyendo en el rango de valores elegidos.*/

#include "Walker.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

int stepRandom(int lo, int hi)
{
    static thread_local std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(lo, hi);
    return dist(rng);
}

double randomFloat()
{
    static thread_local std::mt19937 rng{std::random_device{}()};
    static thread_local std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

Walker::Walker()
{
    //ctor
    _x = 0;
    _y = 0;
    _tam = 5;
}

Walker::Walker(float x, float y, float tam)
{
    //ctor
    _x = x;
    _y = y;
    _tam = tam;
}

Walker::~Walker()
{
    //dtor
}

float acceptReject()
{
    srand(time(NULL));

    while(true)
    {
        float r1 = randomFloat();
        float r2 = randomFloat();
        if(r2 < r1 * r1 / r2) return r1;
    }
}

void Walker::walk()
{
    srand(time(0));
    float step = acceptReject();
    int xStep, yStep;

    if(step < 0.8)
    {
        xStep = stepRandom(-20, 20);
        yStep = stepRandom(-20, 20);
    }
    else
    {
        xStep = stepRandom(-1, 1);
        yStep = stepRandom(-1, 1);
    }
    //std::cout << step << " " << xStep << " " << yStep << '\n';
    _x += xStep;
    _y += yStep;
}

void Walker::show(sf::RenderWindow &window)
{
    sf::CircleShape walker(_tam);
    walker.setFillColor(sf::Color::Magenta);
    walker.setPosition(sf::Vector2f(_x, _y));
    window.draw(walker);
}
