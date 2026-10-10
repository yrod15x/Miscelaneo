#ifndef MOVER_H
#define MOVER_H
#include <SFML/Graphics.hpp>
#include "PerlinNoise.hpp"

class Mover
{
    public:
        Mover();
        Mover(unsigned int width, unsigned int height);
        ~Mover();
        void update();
        void show(sf::RenderWindow &window);
        void checkEdeges(unsigned int width, unsigned int height);
    private:
        sf::Vector2f _position;
        sf::Vector2f _velocity;
        sf::Vector2f _acceleration;
        float _topSpeed = 0;
        void _limit();
        float _dx, _dy;
        siv::PerlinNoise noise;
};

#endif // MOVER_H
