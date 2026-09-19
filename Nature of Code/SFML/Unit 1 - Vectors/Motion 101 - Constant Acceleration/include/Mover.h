#ifndef MOVER_H
#define MOVER_H
#include <SFML/Graphics.hpp>

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
        int _topSpeed = 0;
        void _limit();
};

#endif // MOVER_H
