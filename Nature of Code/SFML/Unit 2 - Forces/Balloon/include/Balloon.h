#ifndef BALLOON_H
#define BALLOON_H
#include <SFML/Graphics.hpp>

class Balloon
{
    public:
        Balloon(int width, int height, int radio);
        ~Balloon();
        void show(sf::RenderWindow &window);
        void update();
        void applyForce(sf::Vector2f force);
        void checkBorders(int width);
    private:
        sf::Vector2f _position;
        sf::Vector2f _acceleration;
        sf::Vector2f _velocity;
        int _radio;
        void capSpeed();
        float _topSpeed = 2.0;
};

#endif // BALLOON_H
