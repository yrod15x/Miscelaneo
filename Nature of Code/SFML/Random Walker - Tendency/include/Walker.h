#ifndef WALKER_H
#define WALKER_H
#include <SFML/Graphics.hpp>


class Walker
{
    public:
        Walker();
        Walker(float x, float y);
        void walk();
        void show(sf::RenderWindow &window);

    private:
        float _x;
        float _y;
        int _stepDir;
};

#endif // WALKER_H
