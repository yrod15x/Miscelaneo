#ifndef MOVER_H
#define MOVER_H
#include <SFML/Graphics.hpp>

class Mover
{
    public:
        Mover();
        Mover(unsigned int width, unsigned int height);
        ~Mover();
        void update(sf::RenderWindow &window);
        void show(sf::RenderWindow &window);
        void checkEdeges(unsigned int width, unsigned int height);
    private:
        sf::Vector2f _position;
        sf::Vector2f _velocity;
        sf::Vector2f _acceleration;
        sf::Vector2f _direction;
        float _topSpeed = 0;
        float _scale = 0;
        void _limit();
};

#endif // MOVER_H
